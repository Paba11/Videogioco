//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "DishWasher.h"


DishWasher::DishWasher() {
    this->isWashing = false;
    this->timer = 5;
    this->numPlates = 0;
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
    if(this->isWashing)
        updateWashing();
}

void DishWasher::updateWashing() {
    //FIXME: CALCULATE THE TIME TO WASH PLATES, DEPENDING ON THE TOTAL NUMBER
    if(this->timer * this->washbasin->getNumPlates() <= this->clock.getElapsedTime().asSeconds())
    {
        this->isWashing = false;
        this->numPlates = 0;
    }
}

void DishWasher::updateAnimations() {
    //FIXME: UPDATE THE ANIMATION OF THE DISHWASHER
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
    //FIXME: SET THE VARIABLES
    if(!this->isWashing && this->washbasin->getIsPlates())
    {
        this->isWashing = true;
        this->washbasin->setIsPlates(false);
        this->numPlates += this->washbasin->getNumPlates();
        this->washbasin->setNumPlates(0);
        this->clock.restart();
        move();
    }
}

void DishWasher::setWashbasin(Washbasin &w) {
    this->washbasin = &w;
}

void DishWasher::move() {
    //TODO: MOVE TO THE WASHBASIN AND UPDATE THE ANIMATION
}


