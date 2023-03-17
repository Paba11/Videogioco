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
    switch(type)
    {
        case Dsr::CHOCOLATE_CAKE:
            if (!texture->loadFromFile("../Textures/Dessert1.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
        case Dsr::CHEESE_CAKE:
            if (!texture->loadFromFile("../Textures/Dessert2.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
        case Dsr::JELLY:
            if (!texture->loadFromFile("../Textures/Dessert3.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
    }
}

void Dessert::initPreparationTime() {
    switch(type)
    {
        case Dsr::CHEESE_CAKE:
            preparationTime = 10;
        case Dsr::CHOCOLATE_CAKE:
            preparationTime = 5;
        case Dsr::JELLY:
            preparationTime = 8;
    }
}

void Dessert::calculatePrice() {
    switch(type)
    {
        case Dsr::CHOCOLATE_CAKE:
            this->price = 5;
        case Dsr::CHEESE_CAKE:
            this->price = 6;
        case Dsr::JELLY:
            this->price = 4;
    }
}

int Dessert::getPrice() {
    return price;
}
