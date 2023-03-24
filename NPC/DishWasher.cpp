//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "DishWasher.h"


DishWasher::DishWasher() {
    initSprite();
    this->isWashing = false;
    this->timer = 5;
    this->numPlates = 0;
}

DishWasher::~DishWasher() {

}


void DishWasher::initSprite() {
    /*
     * Set the texture on the sprite and resize it
     */

    this->sprite.setTexture(*this->texture->getTexture("Dishwasher"));
    this->currentFrame = sf::IntRect (0,0,40,40);
    this->sprite.setTextureRect(this->currentFrame);
    this->sprite.setScale(3.5f,3.5f);
    this->sprite.setPosition(1080,210);
}

void DishWasher::update() {
    setAnimation();
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



    if(this->animationTimer.getElapsedTime().asSeconds() >= 0.4f)
    {

        this->currentFrame.left += 40.f;
        if (this->currentFrame.left >= 120)
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

void DishWasher::setWashbasin(const std::shared_ptr<Washbasin>& w) {
    washbasin.reset();
    washbasin = w;
}

void DishWasher::move() {
    //TODO: MOVE THE DISHWASHER FROM THE TABLE TO THE WASHBASIN AND UPDATE THE ANIMATION
}

std::shared_ptr<Washbasin> DishWasher::getWashbasin() {
    return washbasin;
}

void DishWasher::setAnimation() {

    if(this->isWashing)
        this->currentFrame.top = 40.f; //Washing animation
    else
        this->currentFrame.top = 0.f; //Idle animation

    this->sprite.setTextureRect(this->currentFrame);
}


