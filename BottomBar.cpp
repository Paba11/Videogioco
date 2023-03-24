//
// Created by Ettore Righi on 28/02/23.
//

#include "BottomBar.h"

BottomBar::BottomBar() {
    this->texture = new Textures();
    initSprite();

}

BottomBar::~BottomBar() {

}

void BottomBar::update() {

}

void BottomBar::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}

void BottomBar::initSprite() {

    this->sprite.setPosition(5,1200);
    this->sprite.setTexture(*this->texture->getTexture("BottomBar"));
    this->sprite.setScale(0.7f,0.7f);
}
