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

void MainCourse::initTexture() {
    switch(type)
    {
        case Mn::HAMBURGER:
            if (!this->texture->loadFromFile("../Textures/Main1.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
            break;
        case Mn::MEATBALLS:
            if (!this->texture->loadFromFile("../Textures/Main2.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
            break;
        case Mn::MEAT:
            if (!this->texture->loadFromFile("../Textures/Main3.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
            break;
        case Mn::CHICKEN:
            if (!this->texture->loadFromFile("../Textures/Main4.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
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

int MainCourse::getPrice() {
    return this->price;
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
