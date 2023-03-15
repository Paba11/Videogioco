//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Drink.h"


Drink::Drink(Drk d) {
    this->type = d;
    calculatePrice();
    initTexture();
    initSprite();
}

Drink::~Drink() {

}

void Drink::initTexture() {

}

void Drink::calculatePrice() {
    switch(this->type)
    {
        case WATER:
            this->price = 2;
        case WINE:
            this->price = 6;
        case BEER:
            this->price = 5;
        case COKE:
            this->price = 4;
    }
}

int Drink::getPrice() {
    return this->price;
}


