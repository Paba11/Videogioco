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
    switch(this->type)
    {
        case 1:
            if (!texture->loadFromFile("../Textures/Appetizer1.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
        case 2:
            if (!texture->loadFromFile("../Textures/Appetizer2.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
        case 3:
            if (!texture->loadFromFile("../Textures/Appetizer3.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
    };
}


void Appetizer::initPreparationTime() {
    switch(this->type)
    {
        case NACHOS:
            this->preparationTime = 10;
    }
}

void Appetizer::calculatePrice() {
    switch(this->type)
    {
        case NACHOS:
            this->price = 8;
    }
}

int Appetizer::getPrice() {
    return this->price;
}
