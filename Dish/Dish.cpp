//
// Created by Paolo Sbarzagli on 02/02/23.
//

#include "Dish.h"
#include "../Textures.h"

Dish::Dish() {
    state = State::COOKING;
    initSprite();
    initTexture();
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
    sprite.setOrigin(16,15);
    sprite.setScale(2.5f,2.5f);
}

const sf::FloatRect Dish::getBounds() const {
    return this->sprite.getGlobalBounds();
}

void Dish::initPreparationTime() {

}

int Dish::getTavNum() {
    return this->tavNum;
}

void Dish::setTavNum(int i) {
    this->tavNum = i;
}

float Dish::getPreparationTime() {
    return preparationTime;
}

void Dish::initTexture() {

    texture = new Textures();

}
void Dish::setPrice(int i) {
    price = i;
}

int Dish::getPrice() {
    return price;
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




