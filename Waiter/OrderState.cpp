//
// Created by Paolo Sbarzagli on 20/02/23.
//

#include "OrderState.h"

OrderState::OrderState(Map* m) {
    initVariables(m);

    /*
    this->actualMax = MAX_DRINKS;
    this->cursor = 0;
     */
}

OrderState::~OrderState() {
    delete this->order;
}

Order *OrderState::getOrder() {
    return this->order;
}

void OrderState::setOrder(Order *o) {
    this->order = o;
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
    //TODO: HANDLE THE INPUT
}

void OrderState::update(GameCharacter &gc) {

}

void OrderState::randomOrder() {

}

void OrderState::initVariables(Map* m) {
    this->map = m;
    this->order = nullptr;
    this->current = DRINK;
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