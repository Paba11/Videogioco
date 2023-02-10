//
// Created by Paolo Sbarzagli on 10/02/23.
//

#include "Washbasin.h"

Washbasin::Washbasin() {
    initTexture();
    initSprite();
}

Washbasin::~Washbasin() {

}

void Washbasin::initTexture() {
    if (!this->texture.loadFromFile("../Textures/MaleWaiter.png"))
    {
        std::cout << "ERROR::WAITER::CAN'T LOAD TEXTURE FILE" << std::endl;
    }
}

void Washbasin::initSprite() {
    this->sprite.setTexture(this->texture);

    //TO DO: SET THE CORRECT POSITION OF THE WASHBASIN (DEPENDING ON THE LEVEL?)
    //this->sprite.setPosition()
}

void Washbasin::update() {

}

void Washbasin::render(sf::RenderTarget &target) {

}

bool Washbasin::getIsPlates() const {
    return this->isPlates;
}

void Washbasin::setIsPlates(bool t) {
    this->isPlates = t;
}
