//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "MainCourse.h"

MainCourse::MainCourse(int t) {
    switch(t)
    {
        case 1:
            this->type = HAMBURGER;
        case 2:
            this->type = MEAT;
        case 3:
            this->type = MEATBALLS;
        case 4:
            this->type = CHICKEN;
    }
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
