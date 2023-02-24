//
// Created by Paolo Sbarzagli on 23/02/23.
//

#include "Bill.h"

Bill::Bill() {
    this->calculatedTotal = 0;
    this->correctTotal = 0;
    this->isCorrect = false;
}

Bill::~Bill() {

}

bool Bill::calculateTotal() {
    while(this->calculatedTotal == 0)
    {
        update();
        render();
    }
    if(this->calculatedTotal == this->correctTotal)
        this->isCorrect = true;
    return this->isCorrect;
}

void Bill::update() {
 //TODO:: WAIT FOR THE INSERTION OF A VALUE
}

void Bill::render() {
    //TODO: RENDER THE DIGITS
}

void Bill::setAppetizers(Apt apt) {
    this->appetizers.push_back(apt);
}

void Bill::setMainDishes(Mn mn) {
    this->mainDishes.push_back(mn);
}

void Bill::setDesserts(Dsr dsr) {
    this->desserts.push_back(dsr);
}

void Bill::setDrinks(Drk drk) {
    this->drinks.push_back(drk);
}

void Bill::calculateCorrectTotal() {
    while(!this->drinks.empty())
    {
        this->d = new Drink(this->drinks.back());
        this->drinks.pop_back();
        this->correctTotal += this->d->getPrice();
        delete this->d;
    }
    while(!this->appetizers.empty())
    {
        this->a = new Appetizer(this->appetizers.back());
        this->appetizers.pop_back();
        this->correctTotal += this->a->getPrice();
        delete this->a;
    }
    while(!this->mainDishes.empty())
    {
        this->m = new MainCourse(this->mainDishes.back());
        this->mainDishes.pop_back();
        this->correctTotal += this->m->getPrice();
        delete m;
    }
    while(!this->desserts.empty())
    {
        this->ds = new Dessert(this->desserts.back());
        this->desserts.pop_back();
        this->correctTotal += this->ds->getPrice();
        delete ds;
    }
}
