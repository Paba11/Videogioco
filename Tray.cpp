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
    for(int i = 0; !this->dishes.empty(); i++)
    {
        delete this->dishes[i];
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

void Tray::setState(int t) {
    switch(t)
    {
        case 1:
            this->state = EMPTY_PLATES;
        case 2:
            this->state = EMPTY_TRAY;
        case 3:
            this->state = FILLED_TRAY;
    }
}

TrayState Tray::getState() {
    return this->state;
}

Dish *Tray::getDish(int i) {
    return this->dishes[i];
}

void Tray::setDish(Dish* d) {
    this->dishes.push_back(d);
}

std::vector<Dish *>& Tray::getDishes() {
    return this->dishes;
}

