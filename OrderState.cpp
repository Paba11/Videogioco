//
// Created by Paolo Sbarzagli on 20/02/23.
//

#include "OrderState.h"

OrderState::OrderState() {
    initTexture();
    initSprite();
    this->order = nullptr;
    this->current = DRINK;
    this->actualMax = MAX_DRINKS;
    this->cursor = 0;
}

OrderState::~OrderState() {
    delete this->order;
}

Order *OrderState::getOrder() {
    return this->order;
}

void OrderState::initTexture() {

}

void OrderState::initSprite() {

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

void OrderState::setOrderVariables(Table* t, Order* o) {
    this->table = t;
    this->order = o;
    this->order->initPointersToNull();
}

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

void OrderState::manageOrder() {
    setDrinks();
    setAppetizers();
    setMainCourses();
    setDesserts();
}

void OrderState::setAnimation() {
    if(this->current == DRINK)
    {
        this->current = APPETIZER;
        this->actualMax = MAX_APPETIZERS;
    }
    else if(this->current == APPETIZER)
    {
        this->current = MAIN_DISH;
        this->actualMax = MAX_MAIN_DISHES;
    }
    else if(this->current == MAIN_DISH)
    {
        this->current = DESSERT;
        this->actualMax = MAX_DESSERT;
    }
}

bool OrderState::select() {
    this->flag = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        cursor = ((cursor-1)%actualMax);
        update();
        render();
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        cursor = ((cursor+1)%actualMax);
        update();
        render();
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::J))
    {
        flag = true;
        update();
        render();
    }
    return flag;
}

void OrderState::update() {
    //TODO: UPDATE THE CURSOR IN THE CORRECT POSITION
}

void OrderState::render() {
    //TODO: RENDER THE TEXTURE ON THE SCREEN
}
