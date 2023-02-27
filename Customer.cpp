//
// Created by Paolo Sbarzagli on 02/02/23.
//

#include "Customer.h"


Customer::Customer() {
    this->mood = GOOD;
    this->patience = 100;

}

Customer::~Customer() {

}

void Customer::update() {
    updateAnimations();
}

void Customer::moveToChair() {


}

void Customer::setSprite() {

    this->currentFrame = sf::IntRect(0, 0, 32, 32); //box of 32x32
    this->sprite.setTextureRect(this->currentFrame);
    this->sprite.setScale(3.f,3.f);
}

void Customer::updateAnimations() {

    if(this->animationTimer.getElapsedTime().asSeconds() >= 0.4f) {
        //Idle animation

        this->currentFrame.left += 32.f;
        if (this->currentFrame.left >= 96)
            this->currentFrame.left = 0;

        this->animationTimer.restart();
        this->sprite.setTextureRect(this->currentFrame);
    }
}

void Customer::move() {

    switch (this->movingStatus) {
        case MOVING_LEFT:
            if(validMovement["Left"])
                this->sprite.move(this->speed * (-0.15f), this->speed * (0.f));
            break;

        case MOVING_RIGHT:
            if(validMovement["Right"])
                this->sprite.move(this->speed * (0.15f), this->speed * (0.f));
            break;

        case MOVING_UP:
            if(validMovement["Up"])
                this->sprite.move(this->speed * (0.f), this->speed * (-0.15f));
            break;

        case MOVING_DOWN:
            if(validMovement["Down"])
                this->sprite.move(this->speed * (0.f), this->speed * (0.15f));
            break;
        case STANDING:
            break;
    }

}

