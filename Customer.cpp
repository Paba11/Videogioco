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

void Customer::setSprite(int numberCustomer) {


    if( numberCustomer == 4)
        this->currentFrame = sf::IntRect(96, 128, 32, 32); //box of 32x32

    else if(numberCustomer == 3)
        this->currentFrame = sf::IntRect(0, 128, 32, 32);

    else if(numberCustomer == 2)
        this->currentFrame = sf::IntRect(96, 0, 32, 32);

    else if(numberCustomer == 1)
        this->currentFrame = sf::IntRect(0, 0, 32, 32);


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

