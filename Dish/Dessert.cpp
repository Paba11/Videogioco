//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Dessert.h"


Dessert::Dessert(Dsr d) {
    this->type = d;
    calculatePrice();
    calculateTime();
    //initTexture();
    //initSprite();
}

Dessert::~Dessert() {

}

void Dessert::setTexture() {
    switch(type)
    {
        case Dsr::CHOCOLATE_CAKE:
            sprite.setTexture(*this->texture->getTexture("CHOCOLATE_CAKE"));
            break;
        case Dsr::CHEESE_CAKE:
            sprite.setTexture(*this->texture->getTexture("CHEESECAKE"));
            break;
        case Dsr::JELLY:
            sprite.setTexture(*this->texture->getTexture("JELLY"));
            break;
    }
}

void Dessert::initPreparationTime() {
    switch(type)
    {
        case Dsr::CHEESE_CAKE:
            preparationTime = 10;
            break;
        case Dsr::CHOCOLATE_CAKE:
            preparationTime = 5;
            break;
        case Dsr::JELLY:
            preparationTime = 8;
            break;
    }
}

void Dessert::calculatePrice() {
    switch(type)
    {
        case Dsr::CHOCOLATE_CAKE:
            this->price = 5;
            break;
        case Dsr::CHEESE_CAKE:
            this->price = 6;
            break;
        case Dsr::JELLY:
            this->price = 4;
            break;
    }
}

void Dessert::calculateTime() {
    switch(type)
    {
        case Dsr::CHEESE_CAKE:
            preparationTime = 20;
            break;
        case Dsr::CHOCOLATE_CAKE:
            preparationTime = 17;
            break;
        case Dsr::JELLY:
            preparationTime = 15;
            break;
    }
}
