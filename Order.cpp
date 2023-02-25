//
// Created by Paolo Sbarzagli on 02/02/23.
//

#include "Order.h"


Order::Order() {
    this->current = APPETIZER;
}

Order::~Order() {

}

Apt Order::getAppetizer(int i) {
    return this->appetizers[i];
}

Mn Order::getMainCourse(int i) {
    return this->mainCourse[i];
}

Dsr Order::getDessert(int i) {
    return this->desserts[i];
}

Drk Order::getDrink(int i) {
    return this->drinks[i];
}

const int Order::getTableNumber() {
    return this->tableNumber;
}

Current Order::getCurrent() {
    return this->current;
}

void Order::setCurrent(Current c) {
    this->current = c;
}

void Order::setAppetizer(int i) {
    this->apt = new Apt;
    if(i == 0)
    {
        *this->apt = NACHOS;
    }
    this->appetizers.push_back(*this->apt);
    this->apt = nullptr;
}

void Order::setMainCourse(int i) {
    this->mn = new Mn;
    if(i == 0)
    {
        *this->mn = HAMBURGER;
    }
    if(i == 1)
    {
        *this->mn = MEAT;
    }
    if(i == 2)
    {
        *this->mn = MEATBALLS;
    }
    if(i == 3)
    {
        *this->mn = CHICKEN;
    }
    this->mainCourse.push_back(*this->mn);
    this->mn = nullptr;
}

void Order::setDessert(int i) {
    this->dsr = new Dsr;
    if(i == 0)
    {
        *this->dsr = CHOCOLATE_CAKE;
    }
    if(i == 1)
    {
        *this->dsr = CHEESE_CAKE;
    }
    if(i == 2)
    {
        *this->dsr = JELLY;
    }
    this->desserts.push_back(*this->dsr);
    this->dsr = nullptr;
}

void Order::setDrink(int i) {
    this->drk = new Drk;
    if(i == 0)
    {
       *this->drk = WATER;
    }
    else if(i == 1)
    {
       *this->drk = WINE;
    }
    else if(i == 2)
    {
        *this->drk = BEER;
    }
    else if(i == 3)
    {
        *this->drk = COKE;
    }
    this->drinks.push_back(*this->drk);
    this->drk = nullptr;
}

void Order::setTableNumber(int i) {
    this->tableNumber = i;
}

std::vector<Apt> &Order::getAppetizers() {
    return this->appetizers;
}

std::vector<Mn> &Order::getMainCourses() {
    return this->mainCourse;
}

std::vector<Dsr> &Order::getDesserts() {
    return this->desserts;
}

std::vector<Drk> &Order::getDrinks() {
    return this->drinks;
}

void Order::initPointersToNull() {
    this->drk = nullptr;
    this->mn = nullptr;
    this->dsr = nullptr;
    this->apt = nullptr;
}


