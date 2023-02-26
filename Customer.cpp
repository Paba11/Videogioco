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
    GameCharacter::update();
}

void Customer::moveToChair() {


}

void Customer::setSprite(int numberCustomer) {

    if( numberCustomer == 4)
        this->currentFrame = sf::IntRect(0, 0, 33, 33);

    else if(numberCustomer == 3)
        this->currentFrame = sf::IntRect(0, 0, 33, 33);

    else if(numberCustomer == 2)
        this->currentFrame = sf::IntRect(0, 0, 33, 33);

    else if(numberCustomer == 1)
        this->currentFrame = sf::IntRect(0, 0, 33, 33);


    this->sprite.setTextureRect(this->currentFrame);
    this->sprite.setScale(3.f,3.f);
}

