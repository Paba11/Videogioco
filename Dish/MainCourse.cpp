//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "MainCourse.h"


MainCourse::MainCourse(Mn t) {
    this->type = t;
    calculatePrice();
    initTexture();
    initSprite();
}

MainCourse::~MainCourse() {

}

void MainCourse::initTexture() {
    switch(this->type)
    {
        case 1:
            if (!this->texture->loadFromFile("../Textures/Main1.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
        case 2:
            if (!this->texture->loadFromFile("../Textures/Main2.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
        case 3:
            if (!this->texture->loadFromFile("../Textures/Main3.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
        case 4:
            if (!this->texture->loadFromFile("../Textures/Main4.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
    }
}

void MainCourse::initPreparationTime() {
    switch(this->type)
    {
        case HAMBURGER:
            this->preparationTime = 20;
        case MEAT:
            this->preparationTime = 30;
        case CHICKEN:
            this->preparationTime = 25;
        case MEATBALLS:
            this->preparationTime = 30;
    }
}

void MainCourse::calculatePrice() {
    switch(this->type)
    {
        case HAMBURGER:
            this->price = 14;
        case MEAT:
            this->price = 18;
        case MEATBALLS:
            this->price = 15;
        case CHICKEN:
            this->price = 12;
    }
}

int MainCourse::getPrice() {
    return this->price;
}
