//
// Created by Paolo Sbarzagli on 20/02/23.
//

#include "OrderState.h"

#include <utility>

OrderState::OrderState(Table& t) {
    initVariables(t);
}

OrderState::~OrderState() {

}

std::shared_ptr<Order>& OrderState::getOrder() {
    return order;
}

Table* OrderState::getTable() {
    return table;
}

void OrderState::setTable(Table* t) {
    table = t;
}

void OrderState::setOrderVariables(const std::shared_ptr<Table>& t) {

}

void OrderState::handleInput(std::shared_ptr<GameCharacter>& gc, sf::Event ev) {

}

void OrderState::update(std::shared_ptr<GameCharacter>& gc) {

}

void OrderState::randomChoices() {

    switch(current)
    {
        case Current::APPETIZER:
            for(int i = 0; i < table->getCustomers().size(); i++)
            {
                generateRandom(1);
                order->setAppetizer(random);
            }
            break;
        case Current::MAIN_DISH:
            for(int i = 0; i < table->getCustomers().size(); i++)
            {
                generateRandom(3);
                order->setMainCourse(random);
            }
            break;
        case Current::DESSERT:
            for(int i = 0; i < table->getCustomers().size(); i++)
            {
                generateRandom(2);
                order->setDessert(random);
            }
            break;
    }
}

void OrderState::initVariables(Table& t) {
    order = std::make_shared<Order>();
    table = &t;
    order->setTableNumber(table->getTavNum());
    order->setPeopleNumber(table->getCustomerNumber());
    timer.restart();
    isTaken = false;
    current = Current::APPETIZER;
}

std::shared_ptr<Order>& OrderState::takeOrder() {
    if(!isTaken)
    {
        map->getKitchen()->setWaiterOrder(true);
        randomChoices();
        current = Current::MAIN_DISH;
        randomChoices();
        current = Current::DESSERT;
        randomChoices();
        isTaken = true;
    }
    return order;
}

void OrderState::generateRandom(int max) {
    std::mt19937 gen(this->rd());
    std::uniform_int_distribution<> distrib(0, max);
    this->random = distrib(gen);
}

bool OrderState::getIsTaken() {
    return isTaken;
}

void OrderState::setIsTaken(bool t) {
    isTaken = t;
}

void OrderState::setMap(const std::shared_ptr<Map>& m) {

    map.reset();
    map = m;

}

/*
void OrderState::setAppetizers() {
    cursor = 0;
    setAnimation();
    while(this->order->getAppetizers().size() < this->table->getCustomerNumber())
    {
        while(!flag)
        {
            select();
        }
        this->order->setAppetizer(this->cursor);
        this->flag = false;
    }
}

void OrderState::setMainCourses() {
    cursor = 0;
    setAnimation();
    while(this->order->getMainCourses().size() < this->table->getCustomerNumber())
    {
        while(!flag)
        {
            select();
        }
        this->order->setMainCourse(this->cursor);
        this->flag = false;
    }
}

void OrderState::setDesserts() {
    cursor = 0;
    setAnimation();
    while(this->order->getDesserts().size() < this->table->getCustomerNumber())
    {
        while(!flag)
        {
            select();
        }
        this->order->setDessert(this->cursor);
        this->flag = false;
    }
}

void OrderState::setDrinks() {
    cursor = 0;
    setAnimation();
    while(this->order->getDrinks().size() < this->table->getCustomerNumber())
    {
        while(!flag)
        {
            select();
        }
        this->order->setDrink(this->cursor);
        this->flag = false;
    }
}
*/