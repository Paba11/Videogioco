//
// Created by Paolo Sbarzagli on 02/02/23.
//

#include "Dish.h"

Dish::Dish() {
    state = State::COOKING;
}

Dish::~Dish() {
    //delete this->texture;
}

void Dish::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}

void Dish::update() {
    this->sprite.move(this->preparationTime * this->direction);
}

void Dish::initSprite() {
    this->sprite.setTexture(*texture);
}

const sf::FloatRect Dish::getBounds() const {
    return this->sprite.getGlobalBounds();
}

void Dish::initTexture() {

}

void Dish::initPreparationTime() {

}

int Dish::getTavNum() {
    return this->tavNum;
}

void Dish::setTavNum(int i) {
    this->tavNum = i;
}


