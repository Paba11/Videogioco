//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Chef.h"


Chef::Chef() {
    initSprite();
    this->state = WAIT;
}

Chef::~Chef() {
    delete this->dish;
    delete this->order;
}



void Chef::initSprite() {
    /*
     * Set the texture on the sprite, resize it and locate the chef in the right position
     */
    this->texture = new Textures(); //FIXME move the texture pointer in the GameCharachter class (also for waiter)
    this->sprite.setTexture(*this->texture->getTexture("Chef"));
    this->currentFrame = sf::IntRect (0,0,40,40);
    this->sprite.setTextureRect(this->currentFrame);
    this->sprite.setScale(3.5f, 3.5f);
    this->sprite.setPosition(1100,400);

    //this->sprite.setPosition();
}

void Chef::updateMovement(int action) {


}

void Chef::move() {

}

void Chef::setAnimation() {

    if(this->state == WAIT)
        this->currentFrame.top = 0.f;

    else if(this->state == COOK)
        this->currentFrame.top = 40.f;

    this->sprite.setTextureRect(this->currentFrame);
}

void Chef::update() {
    this->updateAnimations();
    this->setAnimation();

}

void Chef::updateAnimations() {

    if(this->animationTimer.getElapsedTime().asSeconds() >= 0.4f) {
        //Idle animation

        this->currentFrame.left += 40.f;
        if (this->currentFrame.left >= 120)
            this->currentFrame.left = 0;

        this->animationTimer.restart();
        this->sprite.setTextureRect(this->currentFrame);
    }
}

