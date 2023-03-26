//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "MainCourse.h"


MainCourse::MainCourse(Mn t) {
    type = t;
    calculatePrice();
    calculateTime();
    //initTexture();
    //initSprite();
}

MainCourse::~MainCourse() {

}

void MainCourse::setTexture() {
    switch(type)
    {
        case Mn::HAMBURGER:
            sprite.setTexture(*this->texture->getTexture("HAMBURGER"));
            break;
        case Mn::MEATBALLS:
            sprite.setTexture(*this->texture->getTexture("MEATBALLS"));
            break;
        case Mn::MEAT:
            sprite.setTexture(*this->texture->getTexture("MEAT"));
            break;
        case Mn::CHICKEN:
            sprite.setTexture(*this->texture->getTexture("CHICKEN"));
            break;
    }
}

void MainCourse::initPreparationTime() {
    switch(type)
    {
        case Mn::HAMBURGER:
            preparationTime = 20;
            break;
        case Mn::MEAT:
            preparationTime = 30;
            break;
        case Mn::CHICKEN:
            preparationTime = 25;
            break;
        case Mn::MEATBALLS:
            preparationTime = 30;
            break;
    }
}

void MainCourse::calculatePrice() {
    switch(type)
    {
        case Mn::HAMBURGER:
            price = 14;
            break;
        case Mn::MEAT:
            price = 18;
            break;
        case Mn::MEATBALLS:
            price = 15;
            break;
        case Mn::CHICKEN:
            price = 12;
            break;
    }
}


void MainCourse::calculateTime() {
    switch(type)
    {
        case Mn::MEAT:
            preparationTime = 30;
            break;
        case Mn::MEATBALLS:
            preparationTime = 25;
            break;
        case Mn::CHICKEN:
            preparationTime = 20;
            break;
        case Mn::HAMBURGER:
            preparationTime = 18;
            break;
    }
}
