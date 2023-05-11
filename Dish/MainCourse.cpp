//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "MainCourse.h"


MainCourse::MainCourse(Mn t) {
    type = t;
    calculateTime();
    setTexture();
    //initTexture();
    //initSprite();
}

MainCourse::~MainCourse() = default;

void MainCourse:: setTexture() {
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
