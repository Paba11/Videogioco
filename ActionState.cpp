//
// Created by Paolo Sbarzagli on 07/03/23.
//

#include "ActionState.h"

ActionsState::ActionsState(Map* m) {
    this->map = m;
    this->waiter = nullptr;
    this->tray = new Tray();
    this->isOrder = false;
}

ActionsState::~ActionsState() {

}

void ActionsState::handleInput(GameCharacter &w, sf::Event ev) {
    this->waiter = &w;
    this->event = ev;
    actionManagement();
}

void ActionsState::update(GameCharacter &w) {

}


void ActionsState::pickUp(Kitchen* kitchen) {
    //PICK UP THE PLATES FROM THE KITCHEN

    Dish* d;
    if(this->tray->getState() == TrayState::EMPTY_TRAY && kitchen->getState() == DishState::FULL)
    {
        while (!kitchen->getDishes().empty())
        {
            d = kitchen->getDish();
            this->tray->setDish(d);
            this->tray->update();
            kitchen->update();
            //this->update();
        }
        //Set the tray to filled
        this->tray->setState(TrayState::FILLED_TRAY);
        //Set the kitchen to empty
        kitchen->setState(DishState::EMPTY);
    }
}


void ActionsState::pickUp(Table* table) {
    //PICK UP THE EMPTY PLATES FROM THE TABLE

    Dish* d;
    if(this->tray->getState() == TrayState::EMPTY_TRAY && table->getState() == TableState::ENDED)
    {
        while(!table->getDishes().empty())
        {

            d = table->getDish();
            this->tray->setDish(d);
            this->tray->update();
            table->update();
            //update();
        }

        //Set the tray to empty plates
        this->tray->setState(TrayState::EMPTY_PLATES);

        //Set the table to the next instruction on the order
        switch(table->getCourse())
        {
            case Current::APPETIZER:
                table->setState(WAITING_DISHES);
                table->setCourse(Current::MAIN_DISH);
                break;
            case Current::MAIN_DISH:
                table->setState(WAITING_DISHES);
                table->setCourse(Current::DESSERT);
                break;
            case Current::DESSERT:
                table->setState(ENDED);
                table->setCourse(Current::END);
                break;
        }
    }
}

void ActionsState::putDown(Table* table) {
    //Leave the plates at the table

    if(this->tray->getState() == TrayState::FILLED_TRAY && table->getState() == WAITING_DISHES &&
       this->tray->getDishes().front()->getTavNum() == table->getTavNum())
    {
        while(!this->tray->getDishes().empty())
        {
            table->setDish(this->tray->getDish());
            this->tray->update();
            table->update();
            //update();
        }

        //Set the table in the right state
        table->setState(EATING);
        //Set the tray in the right state
        this->tray->setState(TrayState::EMPTY_TRAY);
    }
}

void ActionsState::putDown(Washbasin* washbasin) {
    //Lave the plates at the washbasin

    if(this->tray->getState() == TrayState::EMPTY_PLATES && !washbasin->getIsPlates())
    {
        //Set the table in the right state
        washbasin->setIsPlates(true);
        int count = 0;

        while(!this->tray->getDishes().empty())
        {
            count++;
            this->tray->getDish();
            this->tray->update();
            washbasin->update();
            //update();
        }
        washbasin->setNumPlates(count);
        //Set the tray in the right state
        this->tray->setState(TrayState::EMPTY_TRAY);
    }
}

void ActionsState::leavingOrder(Kitchen* kitchen) {
    //Leave the order at the kitchen

    if(this->order)
    {
        kitchen->insertNewOrder(order);
        kitchen->update();
        this->order = nullptr;
    }
}

Tray *ActionsState::getTray() {
    return this->tray;
}

void ActionsState::setIsOrder(bool t) {
    this->isOrder = t;
}

bool ActionsState::getIsOrder() {
    return this->isOrder;
}

void ActionsState::actionManagement() {
    if(this->event.key.code == sf::Keyboard::J && this->map->getIsClose() == IS_CLOSE_KITCHEN && this->isOrder)
    {
        this->waiter->setState(Actions::LEAVING_ORDER);
        leavingOrder(this->map->getKitchen());
        std::cout << "IsClose Kitchen works correctly" << std::endl;
        this->map->setIsClose(IS_CLOSE_NOTHING);
    }
    else if(this->event.key.code == sf::Keyboard::K && this->tray->getState() == TrayState::EMPTY_TRAY && !this->isOrder)
    {
        if(this->map->getIsClose() == IS_CLOSE_TABLE) {
            this->waiter->setState(Actions::TAKING_EMPTY_DISHES);
            pickUp(this->map->getTableToPickUp());
            std::cout << "PickUp table works correctly" << std::endl;
        }
        else if(this->map->getIsClose() == IS_CLOSE_KITCHEN) {
            waiter->setState(Actions::TAKING_DISHES);
            pickUp(this->map->getKitchen());
            std::cout << "PickUp kitchen works correctly" << std::endl;
        }
    }
    else if(this->event.key.code == sf::Keyboard::L && !this->isOrder)
    {
        if (this->map->getIsClose() == IS_CLOSE_TABLE && this->tray->getState() == TrayState::FILLED_TRAY) {
            this->waiter->setState(Actions::LEAVING_DISHES);
            putDown(this->map->getTableToPickUp());
            std::cout << "PutDown Table works correctly" << std::endl;
        }
        else if (this->map->getIsClose() == IS_CLOSE_DISHWASHER && this->tray->getState() == TrayState::EMPTY_PLATES) {
            this->waiter->setState(Actions::LEAVING_EMPTY_DISHES);
            putDown(this->map->getWashbasin());
            std::cout << "IsClose Table works correctly" << std::endl;
        }
    }
    this->map->setIsClose(IS_CLOSE_NOTHING);
    this->waiter->setState(Actions::DOING_NOTHING);

}
