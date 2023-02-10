//
// Created by Paolo Sbarzagli on 31/01/23.
//

#include "Waiter.h"


Waiter::Waiter() {
    initTexture();
    initSprite();
    this->state = STANDING;
    this->speed = 10;
    this->isClose = IS_CLOSE_NOTHING;
}

Waiter::~Waiter() {
    delete this->tray;
    delete this->order;
}

void Waiter::initTexture() {
    if (!this->texture.loadFromFile("../Textures/new_textures/Waiter_Male_1.png"))
    {
        std::cout << "ERROR::WAITER::CAN'T LOAD TEXTURE FILE" << std::endl;
    }
}

void Waiter::initSprite() {
    /*
     * Set the texture on the sprite and resize it
     */
    this->sprite.setTexture(this->texture);
    this->currentFrame = sf::IntRect (0,0,50,50);
    this->sprite.setTextureRect(this->currentFrame);
    this->sprite.setScale(2.5,2.5);
}

void Waiter::updateMovement() { //appena validMovement diventa false bisogna uscire dal ciclo
    preState = this->state;
    this->state = STANDING;
    //variabile evento ev

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->state = MOVING_LEFT;
        if(preState != this->state)
            validMovement["Left"] = true;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->state = MOVING_RIGHT;
        if(preState != this->state)
            validMovement["Right"] = true;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->state = MOVING_UP;
        if(preState != this->state)
            validMovement["Up"] = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->state = MOVING_DOWN;
        if(preState != this->state)
            validMovement["Down"] = true;
    }
    else
    {
        interact(ev);
    }
    setAnimation();
    move();
}

void Waiter::move() {

        switch (this->state) {
            case MOVING_LEFT:
                if(validMovement["Left"] == true)
                    this->sprite.move(this->speed * (-0.15f), this->speed * (0.f));
                break;

            case MOVING_RIGHT:
                if(validMovement["Right"] == true)
                    this->sprite.move(this->speed * (0.15f), this->speed * (0.f));
                break;

            case MOVING_UP:
                if(validMovement["Up"] == true)
                    this->sprite.move(this->speed * (0.f), this->speed * (-0.15f));
                break;

            case MOVING_DOWN:
                if(validMovement["Down"] == true)
                    this->sprite.move(this->speed * (0.f), this->speed * (0.15f));
                break;
        }

}


void Waiter::interact(sf::Event ev) {
    distance();
    switch(ev.type)
    {
        case ev.KeyPressed:
            if(ev.key.code == sf::Keyboard::J && !this->tray)
            {
                if(this->order && this->isClose == IS_CLOSE_KITCHEN)
                    leavingOrder();
                else if(!this->order && this->isClose == IS_CLOSE_TABLE)
                    takingOrder();
            }
            else if(ev.key.code == sf::Keyboard::K && this->tray && !this->order &&
            (this->isClose == IS_CLOSE_TABLE || this->isClose == IS_CLOSE_KITCHEN))
            {
                    pickUp();
            }
            else if(ev.key.code == sf::Keyboard::L && this->tray && !this->order &&
            (this->isClose == IS_CLOSE_TABLE || this->isClose == IS_CLOSE_DISHWASHER))
            {
                    putDown();
            }
            this->isClose = IS_CLOSE_NOTHING;
            break;

    }
}


void Waiter::pickUp() {
    if(this->isClose == IS_CLOSE_TABLE)
    {

    }
    else if (this->isClose == IS_CLOSE_KITCHEN)
    {

    }
}

void Waiter::putDown() {

}

void Waiter::takingOrder() {

}

void Waiter::leavingOrder() {

}

const sf::Vector2f &Waiter::getPosition() const {
    return this->sprite.getPosition();
}

Table *Waiter::distanceTable(const Map& map) {
    /*
     * Calculate the position of the waiter from the Tables
     */
    if(abs(getPosition()-map))
    return nullptr;
}

Kitchen *Waiter::distanceKitchen(const Map& map) {
    /*
     * Calculate the position of the waiter from the Kitchen
     */
    return nullptr;
}

Washbasin *Waiter::distanceWashbasin(const Map& map) {
    /*
     * Calculate the position of the waiter from the Washbasin
     */
    return nullptr;
}


void Waiter::update() {
    updateAnimations();
    updateMovement();
}


void Waiter::updateAnimations() {

    if(this->animationTimer.getElapsedTime().asSeconds() >= 0.4f) {
                                        //Idle animation

            this->currentFrame.left += 50.f;
            if (this->currentFrame.left >= 150)
                this->currentFrame.left = 0;

            this->animationTimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }


}



void Waiter::setAnimation() {

    if(this->state == STANDING)
        this->currentFrame.top = 0.f;

    else if(this->state == MOVING_DOWN)
        this->currentFrame.top = 50.f;

    else if(this->state == MOVING_LEFT)
        this->currentFrame.top = 100.f;

    else if(this->state == MOVING_RIGHT)
        this->currentFrame.top = 150.f;

    else if(this->state == MOVING_UP)
        this->currentFrame.top = 200.f;

    this->sprite.setTextureRect(this->currentFrame);

}


