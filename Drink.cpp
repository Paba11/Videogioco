//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Drink.h"


Drink::Drink(int t) {
    switch(t)
    {
        case 1:
            this->type = WATER;
        case 2:
            this->type = WINE;
        case 3:
            this->type = BEER;
        case 4:
            this->type = COKE;
    }
    initTexture();
    initSprite();
}

Drink::~Drink() {

}

void Drink::initTexture() {

}


