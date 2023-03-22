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

Order& OrderState::getOrder() {
    return order;
}

const std::shared_ptr<Table>& OrderState::getTable() {
    return table;
}

void OrderState::setTable(const std::shared_ptr<Table>& t) {
    table.reset();
    table = t;
}

void OrderState::setOrderVariables(const std::shared_ptr<Table>& t) {
    table.reset();
    table = t;
    order.initPointersToNull();
}

void OrderState::handleInput(GameCharacter* gc, sf::Event ev) {

}

void OrderState::update(GameCharacter* gc) {

}

void OrderState::randomChoices() {
    switch(current)
    {
        case Current::APPETIZER:
            for(int i = 0; i < table->getCustomers().size(); i++)
            {
                generateRandom(1);
                order.setAppetizer(random);
            }
        case Current::MAIN_DISH:
            for(int i = 0; i < table->getCustomers().size(); i++)
            {
                generateRandom(3);
                order.setMainCourse(random);
            }
        case Current::DESSERT:
            for(int i = 0; i < table->getCustomers().size(); i++)
            {
                generateRandom(2);
                order.setDessert(random);
            }
        case Current::DRINK:
            for(int i = 0; i < table->getCustomers().size(); i++)
            {
                generateRandom(3);
                order.setDrink(random);
            }
    }
}

void OrderState::initVariables(Table& t) {
    table.reset();
    table = std::make_shared<Table>(t);
    order.setTableNumber(table->getTavNum());
    timer.restart();
    isTaken = false;
    current = Current::APPETIZER;
}

Order& OrderState::takeOrder() {
    randomChoices();
    this->current = Current::MAIN_DISH;
    randomChoices();
    this->current = Current::DESSERT;
    randomChoices();
    this->current = Current::DRINK;
    randomChoices();
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