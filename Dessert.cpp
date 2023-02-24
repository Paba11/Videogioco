//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Dessert.h"


Dessert::Dessert(Dsr d) {
    this->type = d;
    calculatePrice();
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

void Dessert::calculatePrice() {
    switch(this->type)
    {
        case CHOCOLATE_CAKE:
            this->price = 5;
        case CHEESE_CAKE:
            this->price = 6;
        case JELLY:
            this->price = 4;
    }
}

int Dessert::getPrice() {
    return this->price;
}
