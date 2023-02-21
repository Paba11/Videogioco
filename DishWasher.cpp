//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "DishWasher.h"


DishWasher::DishWasher() {
    this->isPlates = false;
    this->isWashing = false;
    this->timer = 0;
}

DishWasher::~DishWasher() {
    delete this->texture;
}

void DishWasher::initTexture() {

}

void DishWasher::initSprite() {
    /*
     * Set the texture on the sprite and resize it
     */

    this->sprite.setTexture(*this->texture->getTexture("Waiter"));
    this->currentFrame = sf::IntRect (200,85.f,50,50);
    this->sprite.setTextureRect(this->currentFrame);
    this->sprite.setScale(2.5,2.5);
}

void DishWasher::update() {
    updateAnimations();
    updateVariables();
    updateWashing();
}

void DishWasher::updateWashing() {

}

void DishWasher::updateAnimations() {

    if(this->animationTimer.getElapsedTime().asSeconds() >= 0.4f)
    {
        //Idle animation

        this->currentFrame.left += 50.f;
        if (this->currentFrame.left >= 150)
            this->currentFrame.left = 0;

        this->animationTimer.restart();
        this->sprite.setTextureRect(this->currentFrame);
    }
}

void DishWasher::updateVariables() {
    if(this->washbasin->getIsPlates())
    {
        this->isPlates = true;
    }
    if(!this->isWashing && this->isPlates)
    {
        this->isWashing = true;
        this->isPlates = false;
    }
}

void DishWasher::setWashbasin(Washbasin &w) {
    this->washbasin = &w;
}


