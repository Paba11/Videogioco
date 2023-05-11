//
// Created by Paolo Sbarzagli on 02/02/23.
//

#include "Dish.h"

Dish::Dish() {
    state = State::COOKING;
    initSprite();
    initTexture();
    tavNum = 0;
    preparationTime = 0;
}

Dish::~Dish() = default;

void Dish::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}

void Dish::update() {
    this->sprite.move(this->preparationTime * this->direction);
}

void Dish::initSprite() {
    sprite.setOrigin(16,15);
    sprite.setScale(2.5f,2.5f);
}




int Dish::getTavNum() const {
    return this->tavNum;
}

void Dish::setTavNum(int i) {
    this->tavNum = i;
}

float Dish::getPreparationTime() const{
    return preparationTime;
}

void Dish::initTexture() {

    texture = new Textures();

}



void Dish::setPosition(sf::Vector2f pos) {
    sprite.setPosition(pos);
}

void Dish::setScale(float x, float y) {

    sprite.setScale(x,y);
}

void Dish::setEmptyDish() {

    sprite.setTexture(*texture->getTexture("EmptyDish"));
}




