//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Appetizer.h"


Appetizer::Appetizer(Apt t) {
    type = t;
    calculatePrice();
    calculateTime();
    setTexture();
}

Appetizer::~Appetizer() {

}

void Appetizer::setTexture() {
    switch(type)
    {
        case Apt::NACHOS:
            sprite.setTexture(*this->texture->getTexture("NACHOS"));
            break;
        case Apt::OMELETTE:
            sprite.setTexture(*this->texture->getTexture("OMELETTE"));
            break;
    }
}


void Appetizer::initPreparationTime() {
    switch(type)
    {
        case Apt::NACHOS:
            preparationTime = 10;
            break;
        case Apt::OMELETTE:
            preparationTime = 20;
            break;
    }
}

void Appetizer::calculatePrice() {
    switch(type)
    {
        case Apt::NACHOS:
            price = 8;
            break;
        case Apt::OMELETTE:
            price = 10;
            break;
    }
}

void Appetizer::calculateTime() {
    preparationTime = 0;
    switch(type)
    {
        case Apt::NACHOS:
            preparationTime = 15;
            break;
        case Apt::OMELETTE:
            preparationTime = 20;
            break;
    }
}