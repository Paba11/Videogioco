//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "MainCourse.h"


MainCourse::MainCourse(Mn t) {
    type = t;
    calculatePrice();
    initTexture();
    initSprite();
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
        case Mn::MEATBALLS:
            if (!this->texture->loadFromFile("../Textures/Main2.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
        case Mn::MEAT:
            if (!this->texture->loadFromFile("../Textures/Main3.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
        case Mn::CHICKEN:
            if (!this->texture->loadFromFile("../Textures/Main4.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
    }
}

void MainCourse::initPreparationTime() {
    switch(this->type)
    {
        case Mn::HAMBURGER:
            this->preparationTime = 20;
        case Mn::MEAT:
            this->preparationTime = 30;
        case Mn::CHICKEN:
            this->preparationTime = 25;
        case Mn::MEATBALLS:
            this->preparationTime = 30;
    }
}

void MainCourse::calculatePrice() {
    switch(this->type)
    {
        case Mn::HAMBURGER:
            this->price = 14;
        case Mn::MEAT:
            this->price = 18;
        case Mn::MEATBALLS:
            this->price = 15;
        case Mn::CHICKEN:
            this->price = 12;
    }
}

int MainCourse::getPrice() {
    return this->price;
}
