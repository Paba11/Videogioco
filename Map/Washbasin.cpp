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
    sprite.setTexture(*this->texture->getTexture("Washbasin"));
    sprite.setPosition(1105,170);
    sprite.setScale(3.f,3.f);
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

sf::Vector2f Washbasin::getPosition() {
    return this->sprite.getPosition();
}

const sf::Sprite Washbasin::getSprite() {
    return this->sprite;
}

int Washbasin::getNumPlates() {
    return this->numPlates;
}

void Washbasin::setNumPlates(int i) {
    this->numPlates += i;
}
