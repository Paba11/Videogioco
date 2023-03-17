//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Drink.h"


Drink::Drink(Drk d) {
    type = d;
    calculatePrice();
    initTexture();
    initSprite();
}

Drink::~Drink() {

}

void Drink::initTexture() {

}

void Drink::calculatePrice() {
    switch(type)
    {
        case Drk::WATER:
            price = 2;
        case Drk::WINE:
            price = 6;
        case Drk::BEER:
            price = 5;
        case Drk::COKE:
            price = 4;
    }
}

int Drink::getPrice() {
    return price;
}


