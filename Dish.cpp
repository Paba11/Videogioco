//
// Created by Paolo Sbarzagli on 02/02/23.
//

#include "Dish.h"


Dish::Dish(float dirX, float dirY, float s, int t, int subType) {
    this->direction.x = dirX;
    this->direction.y = dirY;
    this->speed = s;
    if(t == 1)
        type = APPETIZER;
    else if(t == 2)
        type = MAIN_COURSE;
    else if(t == 3)
        type = DESSERT;
    else
        type = DRINK;
    initTexture(subType);
    initSprite();
}

Dish::~Dish() {
    delete this->texture;
}

void Dish::render() {

}

void Dish::update() {
    this->sprite.move(this->speed * this->direction);
}

void Dish::initTexture(int subType) {
    switch(this->type)
    {
        case APPETIZER:
            selectAppetizer(subType);
        case MAIN_COURSE:
            selectMain(subType);
        case DESSERT:
            selectDessert(subType);
        case DRINK:
            selectDrink(subType);
    }
}

void Dish::selectAppetizer(int subType) {
    switch(this->appetizer)
    {
        case 1:
            if (!this->texture->loadFromFile("../Textures/Appetizer1.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
        case 2:
            if (!this->texture->loadFromFile("../Textures/Appetizer2.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
        case 3:
            if (!this->texture->loadFromFile("../Textures/Appetizer3.png"))
            {
                std::cout << "ERROR::DISH::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
    }
}

void Dish::selectMain(int subType) {
    switch(this->main)
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
    }
}

void Dish::selectDessert(int subType) {
    switch(this->dessert)
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

void Dish::selectDrink(int subType) {

}

void Dish::initSprite() {
    this->sprite.setTexture(*texture);
}

const sf::FloatRect Dish::getBounds() const {
    return this->sprite.getGlobalBounds();
}
