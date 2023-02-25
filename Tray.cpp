//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Tray.h"


Tray::Tray() {
    this->state = EMPTY_TRAY;
    initTexture();
    initSprite();
}

Tray::~Tray() {
    Dish* d;
    for(int i = 0; !this->dishes.empty(); i++)
    {
        d = this->dishes.front();
        this->dishes.pop();
        delete d;
    }
}

void Tray::update() {

}

void Tray::render(sf::RenderTarget &target) {
    target.draw(this->sprite);
}

void Tray::initTexture() {

}

void Tray::initSprite() {
    this->sprite.setTexture(this->texture);
}

const sf::Vector2f &Tray::getPosition() const {
    return this->sprite.getPosition();
}

void Tray::setState(TrayState ts) {
    this->state = ts;
}

TrayState Tray::getState() {
    return this->state;
}

Dish *Tray::getDish() {
    Dish* d = this->dishes.front();
    this->dishes.pop();
    return d;
}

void Tray::setDish(Dish* d) {
    this->dishes.push(d);
}

std::queue<Dish *>& Tray::getDishes() {
    return this->dishes;
}

