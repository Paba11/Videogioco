//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Appetizer.h"


Appetizer::Appetizer(Apt t) {
    type = t;
    calculatePrice();
    calculateTime();
    //initTexture();
    //initSprite();
}

Appetizer::~Appetizer() {

}

void Appetizer::initTexture() {
    switch(type)
    {
        case Apt::NACHOS:
            if (!texture->loadFromFile("../Textures/Appetizer1.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
            break;
        case Apt::OMELETTE:
            if (!texture->loadFromFile("../Textures/Appetizer2.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
            break;
    }
}


void Appetizer::initPreparationTime() {
    switch(type)
    {
        case Apt::NACHOS:
            preparationTime = 10;
            break;
        case Apt::OMELETTE:
            preparationTime = 20;
            break;
    }
}

void Appetizer::calculatePrice() {
    switch(type)
    {
        case Apt::NACHOS:
            price = 8;
            break;
        case Apt::OMELETTE:
            price = 10;
            break;
    }
}

int Appetizer::getPrice() {
    return price;
}

void Appetizer::calculateTime() {
    preparationTime = 0;
    switch(type)
    {
        case Apt::NACHOS:
            preparationTime = 15;
            break;
        case Apt::OMELETTE:
            preparationTime = 20;
            break;
    }
}