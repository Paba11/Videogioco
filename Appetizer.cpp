//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Appetizer.h"


Appetizer::Appetizer(Apt t) {
    this->type = t;
    calculatePrice();
    initTexture();
    initSprite();
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
        case Apt::OMELETTE:
            if (!texture->loadFromFile("../Textures/Appetizer2.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
    }
}


void Appetizer::initPreparationTime() {
    switch(type)
    {
        case Apt::NACHOS:
            preparationTime = 10;
        case Apt::OMELETTE:
            preparationTime = 20;
    }
}

void Appetizer::calculatePrice() {
    switch(type)
    {
        case Apt::NACHOS:
            price = 8;
        case Apt::OMELETTE:
            price = 10;
    }
}

int Appetizer::getPrice() {
    return price;
}
