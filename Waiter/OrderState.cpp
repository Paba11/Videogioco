//
// Created by Paolo Sbarzagli on 20/02/23.
//

#include "OrderState.h"

#include <utility>

OrderState::OrderState(Table& t) {
    initVariables(&t);
    current = Current::APPETIZER;
}

OrderState::~OrderState() {

}

std::shared_ptr<Order> OrderState::getOrder() {
    return this->order;
}

void OrderState::setOrder(std::shared_ptr<Order> o) {
    this->order = std::move(o);
}

Table *OrderState::getTable() {
    return this->table;
}

void OrderState::setTable(Table *t) {
    this->table = t;
}

void OrderState::setOrderVariables(Table* t) {
    this->table = t;
    this->order->initPointersToNull();
}

void OrderState::handleInput(GameCharacter &gc, sf::Event ev) {
    takeOrder();
}

void OrderState::update(GameCharacter &gc) {

}

void OrderState::randomChoices() {
    switch(this->current)
    {
        case Current::APPETIZER:
            for(int i = 0; i < this->table->getCustomers().size(); i++)
            {
                generateRandom(1);
                this->order->setAppetizer(this->random);
            }
        case Current::MAIN_DISH:
            for(int i = 0; i < this->table->getCustomers().size(); i++)
            {
                generateRandom(3);
                this->order->setMainCourse(this->random);
            }
        case Current::DESSERT:
            for(int i = 0; i < this->table->getCustomers().size(); i++)
            {
                generateRandom(2);
                this->order->setDessert(this->random);
            }
        case Current::DRINK:
            for(int i = 0; i < this->table->getCustomers().size(); i++)
            {
                generateRandom(3);
                this->order->setDrink(this->random);
            }
    }
}

void OrderState::initVariables(Table* t) {
    table = t;
    order = std::make_shared<Order>();
    order->setTableNumber(table->getTavNum());
    current = Current::DRINK;
}

std::shared_ptr<Order> OrderState::takeOrder() {
    randomChoices();
    this->current = Current::MAIN_DISH;
    randomChoices();
    this->current = Current::DESSERT;
    randomChoices();
    this->current = Current::DRINK;
    randomChoices();
    return this->order;
}

void OrderState::generateRandom(int max) {
    std::mt19937 gen(this->rd());
    std::uniform_int_distribution<> distrib(0, max);
    this->random = distrib(gen);
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