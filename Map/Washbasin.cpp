//
// Created by Paolo Sbarzagli on 10/02/23.
//

#include "Washbasin.h"

Washbasin::Washbasin() {
    initSprite();
    isPlates = false;
    numPlates = 0;
    cicle = false;
    takenDirtyDish = false;
}

Washbasin::~Washbasin() = default;

void Washbasin::initSprite() {
    sprite.setTexture(*this->texture->getTexture("Washbasin"));
    sprite.setPosition(1105,170);
    sprite.setScale(3.f,3.f);

    interactionSquare.setSize({62,62});
    interactionSquare.setOrigin(31,31);
    interactionSquare.setOutlineThickness(1);
    interactionSquare.setFillColor(sf::Color::Transparent);
    interactionSquare.setPosition(985,300.f);

    cornerSprite.setTexture(*this->texture->getTexture("EmptyDish"));
    cornerSprite.setOrigin(16,16);
    cornerSprite.setPosition(interactionSquare.getPosition().x + 31, interactionSquare.getPosition().y - 31);
}

void Washbasin::update() {
    updateBox();
}

void Washbasin::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
    if(takenDirtyDish)
        target.draw(interactionSquare);
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

sf::Sprite Washbasin::getSprite() {
    return this->sprite;
}

int Washbasin::getNumPlates() const {
    return this->numPlates;
}

void Washbasin::setNumPlates(int i) {
    this->numPlates += i;
}

void Washbasin::updateBox() {

    if(takenDirtyDish) {
        interactionSquare.setFillColor(this->boxOpacity);

        if(boxOpacity.a == 255)
            cicle = false;
        if(boxOpacity.a == 0)
            cicle = true;
        if(cicle)
            boxOpacity.a += 5;
        else
            boxOpacity.a-= 5;
    }
}

void Washbasin::setTakenDirtyDish(bool t) {

    takenDirtyDish = t;
}
