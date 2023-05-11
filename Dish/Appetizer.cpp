//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Appetizer.h"


Appetizer::Appetizer(Apt t) {
    type = t;
    calculateTime();
    setTexture();
}

Appetizer::~Appetizer() = default;

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

void Appetizer::calculateTime() {
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
