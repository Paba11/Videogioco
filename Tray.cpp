//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Tray.h"


Tray::Tray() {
}

Tray::~Tray() {

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
    return this->tray[i];
}

void Tray::setDish(int i, Dish* d) {
    this->tray[i] = d;
}

