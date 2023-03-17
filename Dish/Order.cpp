//
// Created by Paolo Sbarzagli on 02/02/23.
//

#include "Order.h"


Order::Order() {
    current = Current::APPETIZER;
}

Order::~Order() {

}

Apt Order::getAppetizer(int i) {
    return appetizers[i];
}

Mn Order::getMainCourse(int i) {
    return mainCourse[i];
}

Dsr Order::getDessert(int i) {
    return desserts[i];
}

Drk Order::getDrink(int i) {
    return drinks[i];
}

const int Order::getTableNumber() {
    return tableNumber;
}

Current Order::getCurrent() {
    return current;
}

void Order::setCurrent(Current c) {
    current = c;
}

void Order::setAppetizer(int i) {
    this->apt = new Apt;
    if(i == 0)
    {
        *this->apt = Apt::NACHOS;
    }
    else if(i == 1)
    {
        *this->apt = Apt::OMELETTE;
    }
    this->appetizers.push_back(*this->apt);
    this->apt = nullptr;
}

void Order::setMainCourse(int i) {
    this->mn = new Mn;
    if(i == 0)
    {
        *this->mn = Mn::HAMBURGER;
    }
    if(i == 1)
    {
        *this->mn = Mn::MEAT;
    }
    if(i == 2)
    {
        *this->mn = Mn::MEATBALLS;
    }
    if(i == 3)
    {
        *this->mn = Mn::CHICKEN;
    }
    this->mainCourse.push_back(*this->mn);
    this->mn = nullptr;
}

void Order::setDessert(int i) {
    this->dsr = new Dsr;
    if(i == 0)
    {
        *this->dsr = Dsr::CHOCOLATE_CAKE;
    }
    if(i == 1)
    {
        *this->dsr = Dsr::CHEESE_CAKE;
    }
    if(i == 2)
    {
        *this->dsr = Dsr::JELLY;
    }
    this->desserts.push_back(*this->dsr);
    this->dsr = nullptr;
}

void Order::setDrink(int i) {
    this->drk = new Drk;
    if(i == 0)
    {
       *this->drk = Drk::WATER;
    }
    else if(i == 1)
    {
       *this->drk = Drk::WINE;
    }
    else if(i == 2)
    {
        *this->drk = Drk::BEER;
    }
    else if(i == 3)
    {
        *this->drk = Drk::COKE;
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

int Order::getPeopleNumber() {
    return this->peopleNumber;
}

void Order::setPeopleNumber(int i) {
    this->peopleNumber = i;
}


