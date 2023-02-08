//
// Created by Paolo Sbarzagli on 31/01/23.
//

#include "Waiter.h"

Waiter::Waiter() {
    initTexture();
    initSprite();
    this->state = STANDING;
    this->speed = 10;
    this->isClose = false;
    this->moving = false;
}

Waiter::~Waiter() {

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

void Waiter::updateMovement() {

    this->state = STANDING;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->state = MOVING_LEFT;

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->state = MOVING_RIGHT;

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        state = MOVING_UP;

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->state = MOVING_DOWN;

    setAnimation();
    move();

}

void Waiter::move() {

    switch(this->state)
    {
        case MOVING_LEFT:
            this->sprite.move(this->speed * (-0.15f), this->speed * (0.f));
            break;

        case MOVING_RIGHT:
            this->sprite.move(this->speed * (0.15f), this->speed * (0.f));
            break;

        case MOVING_UP:
            this->sprite.move(this->speed * (0.f), this->speed * (-0.15f));
            break;

        case MOVING_DOWN:
            this->sprite.move(this->speed * (0.f), this->speed * (0.15f));
            break;
    }
}


void Waiter::interact(sf::Event ev) {
    switch(ev.type)
    {
        case ev.KeyPressed:
            if(ev.key.code == sf::Keyboard::J)
            {
                if(this->order && distanceT())
                    giveOrder();
                else if(distanceK())
                    takeOrder();
            }
            else if(ev.key.code == sf::Keyboard::K)
            {
                if(this->dish && distanceT())
                    putDown();
                else if(distanceK())
                    pickUp();
            }
            isClose = false;
            break;

    }
}

bool Waiter::distanceK() {

}

void Waiter::pickUp() {

}

void Waiter::putDown() {

}

void Waiter::takeOrder() {

}

void Waiter::giveOrder() {

}

bool Waiter::distanceT() {
    return false;
}

const sf::Vector2f &Waiter::getPosition() const {
    return this->sprite.getPosition();
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


