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
    apt = std::make_unique<Apt>();
    if(i == 0)
    {
        *apt = Apt::NACHOS;
    }
    else if(i == 1)
    {
        *apt = Apt::OMELETTE;
    }
    appetizers.push_back(*apt);
    apt.reset();
}

void Order::setMainCourse(int i) {
    mn = std::make_unique<Mn>();
    if(i == 0)
    {
        *mn = Mn::HAMBURGER;
    }
    if(i == 1)
    {
        *mn = Mn::MEAT;
    }
    if(i == 2)
    {
        *mn = Mn::MEATBALLS;
    }
    if(i == 3)
    {
        *mn = Mn::CHICKEN;
    }
    mainCourse.push_back(*mn);
    mn.reset();
}

void Order::setDessert(int i) {
    dsr = std::make_unique<Dsr>();
    if(i == 0)
    {
        *dsr = Dsr::CHOCOLATE_CAKE;
    }
    if(i == 1)
    {
        *dsr = Dsr::CHEESE_CAKE;
    }
    if(i == 2)
    {
        *dsr = Dsr::JELLY;
    }
    desserts.push_back(*dsr);
    dsr.reset();
}

void Order::setDrink(int i) {
    drk = std::make_unique<Drk>();
    if(i == 0)
    {
       *drk = Drk::WATER;
    }
    else if(i == 1)
    {
       *drk = Drk::WINE;
    }
    else if(i == 2)
    {
        *drk = Drk::BEER;
    }
    else if(i == 3)
    {
        *drk = Drk::COKE;
    }
    drinks.push_back(*drk);
    drk.reset();
}

void Order::setTableNumber(int i) {
    tableNumber = i;
}

std::vector<Apt> &Order::getAppetizers() {
    return appetizers;
}

std::vector<Mn> &Order::getMainCourses() {
    return mainCourse;
}

std::vector<Dsr> &Order::getDesserts() {
    return desserts;
}

std::vector<Drk> &Order::getDrinks() {
    return drinks;
}

void Order::initPointersToNull() {
    drk.reset();
    mn.reset();
    dsr.reset();
    apt.reset();
}

int Order::getPeopleNumber() {
    return peopleNumber;
}

void Order::setPeopleNumber(int i) {
    peopleNumber = i;
}


