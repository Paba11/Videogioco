//
// Created by Paolo Sbarzagli on 02/02/23.
//

#include "Customer.h"


Customer::Customer() {
    initVariables();
    leaving = false;
    blockedSaved = false;
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
    if(leaving)
        leftTheRestaurant();
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
        case Move::MOVING_LEFT:
            if (this->validMovement["Left"]) {
                this->sprite.move(this->speed * (-0.15f), this->speed * (0.f));
                if(!leaving)
                    savePath(movingStatus);
            }
            break;

        case Move::MOVING_RIGHT:
            if (this->validMovement["Right"]) {
                this->sprite.move(this->speed * (0.15f), this->speed * (0.f));
                if(!leaving)
                    savePath(movingStatus);
            }
            break;

        case Move::MOVING_UP:
            if (this->validMovement["Up"]) {
                this->sprite.move(this->speed * (0.f), this->speed * (-0.15f));
                if(!leaving)
                    savePath(movingStatus);
            }
            break;

        case Move::MOVING_DOWN:
            if (this->validMovement["Down"]) {
                this->sprite.move(this->speed * (0.f), this->speed * (0.15f));
                if(!leaving)
                    savePath(movingStatus);
            }
            break;
        case Move::STANDING:
            if(!leaving)
                savePath(movingStatus);
            break;
    }
}

const sf::Vector2f &Customer::getPosition() const {
    return this->sprite.getPosition();
}


void Customer::setAnimation() {

    if(this->movingStatus == Move::STANDING)
        this->currentFrame.top = 0.f;
    else if(this->movingStatus == Move::MOVING_DOWN)
        this->currentFrame.top = 0.f;
    else if(this->movingStatus == Move::MOVING_LEFT)
        this->currentFrame.top = 33.f;
    else if(this->movingStatus == Move::MOVING_RIGHT)
        this->currentFrame.top = 66.f;
    else if(this->movingStatus == Move::MOVING_UP)
        this->currentFrame.top = 99.f;

    this->sprite.setTextureRect(this->currentFrame);

}

void Customer::moveTo() {
    if(this->moving)
        move();
    this->actualPos = this->sprite.getPosition();
    if(this->movingStatus == Move::MOVING_LEFT && this->actualPos.x <= this->endingPos.x) {
        this->moving = false;
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
    this->movingStatus = Move::STANDING;
    this->preMovingStatus = Move::STANDING;
    this->speed = 8;
    this->moving = false;
}

void Customer::setEndingPosition(sf::Vector2f endPos) {
    this->endingPos = endPos;
    this->moving = true;
    if((endPos.y - this->sprite.getPosition().y >= 0) && (endPos.x - this->sprite.getPosition().x >= 0))
    {
        if(this->validMovement["Down"])
            this->movingStatus = Move::MOVING_DOWN;
        else if(this->validMovement["Left"])
            this->movingStatus = Move::MOVING_LEFT;
        else
            this->movingStatus = Move::MOVING_RIGHT;
    }
    else if((endPos.y - this->sprite.getPosition().y >= 0) && (endPos.x - this->sprite.getPosition().x <= 0))
    {
        if(this->validMovement["Down"])
            this->movingStatus = Move::MOVING_DOWN;
        else if(this->validMovement["Right"])
            this->movingStatus = Move::MOVING_RIGHT;
        else
            this->movingStatus = Move::MOVING_LEFT;
    }
    else if((endPos.y - this->sprite.getPosition().y <= 0) && (endPos.x - this->sprite.getPosition().x <= 0))
    {
        if(this->validMovement["Up"])
            this->movingStatus = Move::MOVING_UP;
        else if(this->validMovement["Right"])
            this->movingStatus = Move::MOVING_RIGHT;
        else
            this->movingStatus = Move::MOVING_LEFT;
    }
    else if((endPos.y - this->sprite.getPosition().y <= 0) && (endPos.x - this->sprite.getPosition().x >= 0))
    {
        if(this->validMovement["Up"])
            this->movingStatus = Move::MOVING_UP;
        else if(this->validMovement["Left"])
            this->movingStatus = Move::MOVING_LEFT;
        else
            this->movingStatus = Move::MOVING_RIGHT;
    }
}

bool Customer::isMoving() {
    return moving;
}

void Customer::initTexture(std::string textureName) {


    sprite.setTexture(*this->texture->getTexture(textureName));

}

void Customer::setLeaving(bool t) {
    std::cout <<"set Leaving" << std::endl;
    leaving = t;
}

void Customer::savePath(Move m) {


        if (m == Move::MOVING_LEFT)
            invertedPath.push(Move::MOVING_RIGHT);
        else if (m == Move::MOVING_RIGHT)
            invertedPath.push(Move::MOVING_LEFT);
        else if (m == Move::MOVING_UP)
            invertedPath.push(Move::MOVING_DOWN);
        else if (m == Move::MOVING_DOWN)
            invertedPath.push(Move::MOVING_UP);
        else
            invertedPath.push(Move::STANDING);

}
;
void Customer::leftTheRestaurant() {

    std::cout << "Left The Restaurant" << std::endl;
    if(invertedPath.size() > 0) {
        movingStatus = invertedPath.top();
        invertedPath.pop();
        move();
    }



}

void Customer::leftTheTable(int n) {

    if(n==0 || n==2){
        for(int m = 0; m < 15; m++)
            savePath(Move::STANDING);
    }




    /*
        if(n == 0)
        {
            for(int m = 0; m < 70; m++)
                savePath(Move::MOVING_LEFT);
            for(int m = 0; m < 100; m++)
                savePath(Move::MOVING_DOWN);
        }
        else if(n == 1)
        {
            for(int m = 0; m < 70; m++)
                savePath(Move::MOVING_RIGHT);
            for(int m = 0; m < 100; m++)
                savePath(Move::MOVING_DOWN);
        }
        else if(n == 2)
        {
            for(int m = 0; m < 70; m++)
                savePath(Move::MOVING_LEFT);
            for(int m = 0; m < 50; m++)
                savePath(Move::MOVING_DOWN);
        }
        else if(n == 3)
        {
            for (int m = 0; m < 70; m++)
                savePath(Move::MOVING_RIGHT);
            for (int m = 0; m < 50; m++)
                savePath(Move::MOVING_DOWN);
        }
*/
}


void Customer::setBlock(bool t) {
    blockedSaved = t;
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




