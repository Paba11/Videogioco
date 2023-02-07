//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Dessert.h"


Dessert::Dessert(int t) {
    switch(t)
    {
        case 1:
            this->type = CHOCOLATE_CAKE;
        case 2:
            this->type = CHEESE_CAKE;
        case 3:
            this->type = JELLY;
    }
    initTexture();
    initSprite();
}

Dessert::~Dessert() {

}

void Dessert::initTexture() {
    switch(this->type)
    {
        case 1:
            if (!this->texture->loadFromFile("../Textures/Dessert1.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
        case 2:
            if (!this->texture->loadFromFile("../Textures/Dessert2.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
        case 3:
            if (!this->texture->loadFromFile("../Textures/Dessert3.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
    }
}

void Dessert::initPreparationTime() {
    switch(this->type)
    {
        case CHEESE_CAKE:
            this->preparationTime = 10;
        case CHOCOLATE_CAKE:
            this->preparationTime = 5;
        case JELLY:
            this->preparationTime = 8;
    }
}
