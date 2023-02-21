//
// Created by Ettore Righi on 21/02/23.
//

#include "Counter.h"

Counter::Counter() {

    this->texture = new Textures();
    initSprite();
}

Counter::~Counter() {

}

void Counter::initSprite() {

    this->sprite.setTexture(*this->texture->getTexture("Counter"));
    this->sprite.setPosition(1020,170);
    this->sprite.setScale(3.f,3.f);

}

void Counter::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}

const sf::FloatRect Counter::getBounds() const {
    return this->sprite.getGlobalBounds();
}
