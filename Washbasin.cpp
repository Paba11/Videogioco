//
// Created by Paolo Sbarzagli on 10/02/23.
//

#include "Washbasin.h"

Washbasin::Washbasin() {
    initSprite();
}

Washbasin::~Washbasin() {

}

void Washbasin::initSprite() {
    this->sprite.setTexture(*this->texture->getTexture("Washbasin"));
    this->sprite.setPosition(1105,170);
    this->sprite.setScale(3.f,3.f);
    //TO DO: SET THE CORRECT POSITION OF THE WASHBASIN (DEPENDING ON THE LEVEL?)
    //this->sprite.setPosition()
}

void Washbasin::update() {

}

void Washbasin::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}

bool Washbasin::getIsPlates() const {
    return this->isPlates;
}

void Washbasin::setIsPlates(bool t) {
    this->isPlates = t;
}
