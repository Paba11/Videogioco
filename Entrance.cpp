//
// Created by Paolo Sbarzagli on 24/02/23.
//

#include "Entrance.h"

Entrance::Entrance() {
    initTexture();
    initSprite();
    this->isCustomer = false;
}

Entrance::~Entrance() {

}

void Entrance::initSprite() {

}

void Entrance::initTexture() {

}

void Entrance::setSprite(sf::Sprite& e) {
    this->sprite = e;
}

sf::Sprite Entrance::getSprite() {
    return this->sprite;
}

void Entrance::setIsCustomer(bool t) {
    this->isCustomer = t;
}

bool Entrance::getIsCustomer() {
    return this->isCustomer;
}
