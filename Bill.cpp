//
// Created by Paolo Sbarzagli on 23/02/23.
//

#include "Bill.h"

Bill::Bill() {
    calculatedTotal = 0;
    correctTotal = 0;
    isCorrect = false;
}

Bill::~Bill() {

}

bool Bill::calculateTotal() {
    while(calculatedTotal == 0)
    {
        update();
        render();
    }
    if(calculatedTotal == correctTotal)
        isCorrect = true;
    return isCorrect;
}

void Bill::update() {
 //TODO:: WAIT FOR THE INSERTION OF A VALUE
}

void Bill::render() {
    //TODO: RENDER THE DIGITS
}

void Bill::setAppetizers(Apt apt) {
    appetizers.push_back(apt);
}

void Bill::setMainDishes(Mn mn) {
    mainDishes.push_back(mn);
}

void Bill::setDesserts(Dsr dsr) {
    desserts.push_back(dsr);
}

void Bill::setDrinks(Drk drk) {
    drinks.push_back(drk);
}

void Bill::calculateCorrectTotal() {
    while(!drinks.empty())
    {
        d = std::make_unique<Drink>(drinks.back());
        drinks.pop_back();
        correctTotal += d->getPrice();
    }
    while(!appetizers.empty())
    {
        a = std::make_unique<Appetizer>(appetizers.back());
        appetizers.pop_back();
        correctTotal += a->getPrice();
    }
    while(!mainDishes.empty())
    {
        m = std::make_unique<MainCourse>(mainDishes.back());
        mainDishes.pop_back();
        correctTotal += m->getPrice();
    }
    while(!desserts.empty())
    {
        ds = std::make_unique<Dessert>(desserts.back());
        desserts.pop_back();
        correctTotal += ds->getPrice();
    }
}
