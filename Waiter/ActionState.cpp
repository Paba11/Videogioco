//
// Created by Paolo Sbarzagli on 07/03/23.
//

#include "ActionState.h"

ActionsState::ActionsState(const std::shared_ptr<Map>& m) {
    map.reset();
    map = m;
    waiter = nullptr;
    tray = std::make_unique<Tray>();
    isOrder = false;
}

ActionsState::~ActionsState() {

}

void ActionsState::handleInput(GameCharacter* w, sf::Event ev) {
    if(waiter == nullptr)
        waiter.reset(w);
    event = ev;
    actionManagement();
}

void ActionsState::update(GameCharacter* w) {

}


void ActionsState::pickUp(Kitchen* kitchen) {
    //PICK UP THE PLATES FROM THE KITCHEN

    Dish* d;
    if(tray->getState() == TrayState::EMPTY_TRAY && kitchen->getState() == DishState::FULL)
    {
        while (!kitchen->getDishes().empty())
        {
            d = kitchen->getDish();
            tray->setDish(d);
            tray->update();
            kitchen->update();
            //this->update();
        }
        //Set the tray to filled
        tray->setState(TrayState::FILLED_TRAY);
        //Set the kitchen to empty
        kitchen->setState(DishState::EMPTY);
    }
}


void ActionsState::pickUp(Table* table) {
    //PICK UP THE EMPTY PLATES FROM THE TABLE

    Dish* d;
    if(tray->getState() == TrayState::EMPTY_TRAY && table->getState() == TableState::ENDED)
    {
        while(!table->getDishes().empty())
        {

            d = table->getDish();
            tray->setDish(d);
            tray->update();
            table->update();
            //update();
        }

        //Set the tray to empty plates
        tray->setState(TrayState::EMPTY_PLATES);

        //Set the table to the next instruction on the order
        switch(table->getCourse())
        {
            case Current::APPETIZER:
                table->setState(TableState::WAITING_DISHES);
                table->setCourse(Current::MAIN_DISH);
                break;
            case Current::MAIN_DISH:
                table->setState(TableState::WAITING_DISHES);
                table->setCourse(Current::DESSERT);
                break;
            case Current::DESSERT:
                table->setState(TableState::ENDED);
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
        while(!tray->getDishes().empty())
        {
            table->setDish(tray->getDish());
            tray->update();
            table->update();
            //update();
        }

        //Set the table in the right state
        table->setState(TableState::EATING);
        //Set the tray in the right state
        tray->setState(TrayState::EMPTY_TRAY);
    }
}

void ActionsState::putDown(Washbasin* washbasin) {
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

void ActionsState::leavingOrder(Kitchen* kitchen) {
    //Leave the order at the kitchen

    if(order)
    {
        kitchen->insertNewOrder(order);
        kitchen->update();
        order = nullptr;
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
