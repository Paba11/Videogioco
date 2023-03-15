//
// Created by Paolo Sbarzagli on 02/02/23.
//

#include "Customer.h"


Customer::Customer() {
    initVariables();
}

Customer::Customer(sf::Vector2f dist) {
    initVariables();
}


Customer::~Customer() {

}

void Customer::update() {
    setAnimation();
    updateAnimations();
    moveTo();
}


void Customer::initSprite() {

    this->sprite.setOrigin(16,32);
    this->currentFrame = sf::IntRect(0, 0, 32, 32); //box of 32x32
    this->sprite.setTextureRect(this->currentFrame);
    this->sprite.setScale(3.f,3.f);
}

void Customer::updateAnimations() {

    if(this->animationTimer.getElapsedTime().asSeconds() >= 0.4f)
    {
        //Idle animation

        this->currentFrame.left += 32.f;
        if (this->currentFrame.left >= 96)
            this->currentFrame.left = 0;

        this->animationTimer.restart();
        this->sprite.setTextureRect(this->currentFrame);
    }
}

void Customer::move() {
    switch (this->movingStatus)
    {
        case MOVING_LEFT:
            if (this->validMovement["Left"])
                this->sprite.move(this->speed * (-0.15f), this->speed * (0.f));
            break;

        case MOVING_RIGHT:
            if (this->validMovement["Right"])
                this->sprite.move(this->speed * (0.15f), this->speed * (0.f));
            break;

        case MOVING_UP:
            if (this->validMovement["Up"])
                this->sprite.move(this->speed * (0.f), this->speed * (-0.15f));
            break;

        case MOVING_DOWN:
            if (this->validMovement["Down"])
                this->sprite.move(this->speed * (0.f), this->speed * (0.15f));
            break;
        case STANDING:
            break;
    }
}

const sf::Vector2f &Customer::getPosition() const {
    return this->sprite.getPosition();
}


void Customer::setAnimation() {

    if(this->movingStatus == STANDING)
        this->currentFrame.top = 0.f;
    else if(this->movingStatus == MOVING_DOWN)
        this->currentFrame.top = 0.f;
    else if(this->movingStatus == MOVING_LEFT)
        this->currentFrame.top = 33.f;
    else if(this->movingStatus == MOVING_RIGHT)
        this->currentFrame.top = 66.f;
    else if(this->movingStatus == MOVING_UP)
        this->currentFrame.top = 99.f;

    this->sprite.setTextureRect(this->currentFrame);

}

void Customer::moveTo() {
    if(this->moving)
        move();
    this->actualPos = this->sprite.getPosition();
    if(this->movingStatus == MOVING_LEFT && this->actualPos.x <= this->endingPos.x) {
        this->moving = false;
        this->movingStatus = STANDING;
    }
}



void Customer::setEndingPosition(sf::Vector2f endPos, Move direction) {
    this->endingPos = endPos;
    this->moving = true;
    this->movingStatus = direction;
}

std::queue<Move> &Customer::getPath() {
    return this->path;
}

void Customer::setPath(Move m) {
    /*
     * Insert the new movement of the waiter inside the path that the customer has to take
     */

    this->path.push(m);
}

void Customer::initVariables() {
    this->mood = GOOD;
    this->patience = 100;
    this->movingStatus = STANDING;
    this->preMovingStatus = STANDING;
    this->speed = 8;
    this->moving = false;
}
/*
void Customer::updateMoving(sf::Sprite& previous) {
    //this->clock
    if((this->path.back().x - previous.getPosition().x != 0) || (this->path.back().y - previous.getPosition().y != 0))
    {
        this->path;
    }
}
*/




