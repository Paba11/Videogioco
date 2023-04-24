//
// Created by Paolo Sbarzagli on 07/03/23.
//

#include "ActionState.h"

ActionsState::ActionsState(const std::shared_ptr<Map>& m) {
    map.reset();
    map = m;
    waiter = nullptr;
    isOrder = false;
}

ActionsState::~ActionsState() {

}

void ActionsState::handleInput(std::shared_ptr<GameCharacter>& w, sf::Event ev) {
    if(waiter == nullptr)
    {
        waiter.reset();
        waiter = w;
    }
    event = ev;
    actionManagement();
}

void ActionsState::update(std::shared_ptr<GameCharacter>& w) {

}


void ActionsState::pickUp(std::shared_ptr<Kitchen>& kitchen) {
    //PICK UP THE PLATES FROM THE KITCHEN
    std::cout << "take dish" << std::endl;
    Dish* d;
    if(tray->getState() == TrayState::EMPTY_TRAY && kitchen->getCounter()->getState() == DishState::FULL)
    {
        int dishNum = 0;
        while (!kitchen->getCounter()->getDishes().empty())
        {
            d = kitchen->getCounter()->getDish();
            tray->setDish(d, dishNum);
            tray->update();
            kitchen->update();
            dishNum++;
            //this->update();
        }
        //Set the tray to filled
        tray->setState(TrayState::FILLED_TRAY);
        //Set the kitchen to empty
        kitchen->getCounter()->setState(DishState::EMPTY);
        map->getTable(tray->getDishes().front()->getTavNum()).setChosenTable(true);
    }
}


void ActionsState::pickUp(Table* table) {
    //PICK UP THE EMPTY PLATES FROM THE TABLE

    Dish* d;
    if(tray->getState() == TrayState::EMPTY_TRAY && table->getState() == TableState::ENDED)
    {
        int dishNum = 0;
        while(!table->getDishes().empty())
        {

            d = table->getDish();
            tray->setDish(d, dishNum);
            tray->update();
            table->update();
            dishNum++;
            //update();
        }

        //Set the tray to empty plates
        tray->setState(TrayState::EMPTY_PLATES);

        //Set the table to the next instruction on the order
        table->setChosenTable(false);
        switch(table->getCourse())
        {
            case Current::APPETIZER:
                table->setState(TableState::WAITING_DISHES);
                table->restartScoreTimer();
                table->setCourse(Current::MAIN_DISH);
                break;
            case Current::MAIN_DISH:
                table->setState(TableState::WAITING_DISHES);
                table->restartScoreTimer();
                table->setCourse(Current::DESSERT);
                break;
            case Current::DESSERT:
                table->setState(TableState::ENDED);
                table->restartScoreTimer();
                table->setCourse(Current::END);
                break;
        }
    }
}

void ActionsState::putDown(Table* table) {
    //Leave the plates at the table

    if(tray->getState() == TrayState::FILLED_TRAY && table->getState() == TableState::WAITING_DISHES &&
       tray->getDishes().front()->getTavNum() == table->getTavNum())
    {
        int dishNum = 0;
        while(!tray->getDishes().empty())
        {
            table->setDish(tray->getDish(), dishNum);
            tray->update();
            table->update();
            //update();
            dishNum++;
        }

        //Set the table in the right state
        table->setState(TableState::EATING);
        table->restartTimer();
        //Set the tray in the right state
        tray->setState(TrayState::EMPTY_TRAY);

        map->getTable(table->getTavNum()).setChosenTable(false);
    }
}

void ActionsState::putDown(std::shared_ptr<Washbasin>& washbasin) {
    //Lave the plates at the washbasin

    if(tray->getState() == TrayState::EMPTY_PLATES && !washbasin->getIsPlates())
    {
        //Set the table in the right state
        washbasin->setIsPlates(true);
        int count = 0;

        while(!tray->getDishes().empty())
        {
            count++;
            tray->getDish();
            tray->update();
            washbasin->update();
            //update();
        }
        washbasin->setNumPlates(count);
        //Set the tray in the right state
        tray->setState(TrayState::EMPTY_TRAY);
    }
}

void ActionsState::leavingOrder(std::shared_ptr<Kitchen>& kitchen) {
    //Leave the order at the kitchen

    if(isOrder)
    {
        kitchen->insertNewOrder(order);
        map->getKitchen()->setWaiterOrder(false);
        getTray()->setOrderTaken(false);
        order = nullptr;
        isOrder = false;
        std::cout << "Order inserted in the kitchen queue" << std::endl;
    }
}

Tray *ActionsState::getTray() {
    return tray.get();
}

void ActionsState::setIsOrder(bool t) {
    isOrder = t;
}

bool ActionsState::getIsOrder() {
    return isOrder;
}

void ActionsState::actionManagement() {
    if(event.key.code == sf::Keyboard::J && map->getIsClose() == IS_CLOSE_KITCHEN && isOrder)
    {
        waiter->setState(Actions::LEAVING_ORDER);
        leavingOrder(map->getKitchen());
        std::cout << "IsClose Kitchen works correctly" << std::endl;
        map->setIsClose(IS_CLOSE_NOTHING);
    }
    else if(event.key.code == sf::Keyboard::K && tray->getState() == TrayState::EMPTY_TRAY && !isOrder)
    {
        if(map->getIsClose() == IS_CLOSE_TABLE) {
            waiter->setState(Actions::TAKING_EMPTY_DISHES);
            pickUp(map->getTableToPickUp());
            std::cout << "PickUp table works correctly" << std::endl;
        }
        else if(map->getIsClose() == IS_CLOSE_KITCHEN) {
            waiter->setState(Actions::TAKING_DISHES);
            pickUp(map->getKitchen());
            std::cout << "PickUp kitchen works correctly" << std::endl;
            map->getKitchen()->setReadyDishes(false);
            map->getKitchen()->getBottomBar()->setIsReady(false, 0);
        }
    }
    else if(event.key.code == sf::Keyboard::L && !isOrder)
    {
        if (map->getIsClose() == IS_CLOSE_TABLE && tray->getState() == TrayState::FILLED_TRAY) {
            waiter->setState(Actions::LEAVING_DISHES);
            putDown(map->getTableToPickUp());
            std::cout << "PutDown Table works correctly" << std::endl;
        }
        else if (map->getIsClose() == IS_CLOSE_DISHWASHER && tray->getState() == TrayState::EMPTY_PLATES) {
            waiter->setState(Actions::LEAVING_EMPTY_DISHES);
            putDown(map->getWashbasin());
            std::cout << "IsClose Table works correctly" << std::endl;
        }
    }
    map->setIsClose(IS_CLOSE_NOTHING);
    waiter->setState(Actions::DOING_NOTHING);

}

void ActionsState::setOrder(std::shared_ptr<Order>& o) {
    order = o;
}

void ActionsState::setTray(const std::shared_ptr<Tray>& t) {

    tray.reset();
    tray = t;
}
