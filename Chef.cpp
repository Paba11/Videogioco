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

void Chef::setDishes(Dish& d) {
    this->dishes.push_back(&d);
}

Dish *Chef::getDish() {
    Dish* d = this->dishes.back();
    this->dishes.pop_back();
    return d;
}

void Chef::cook() {
    //TODO: SELECT THE CURRENT DISH AND COOK IT FOR THE RIGHT TIME
    switch(this->order->getCurrent())
    {
        case APPETIZER:
            //if (this->clock.getElapsedTime() >= this->order->getAppetizers(i)) {

        //} else
            updateAnimations();
    }
}

void Chef::setOrder() {
    this->order = this->kitchen->getReadyOrder();
}

Order *Chef::getOrder() {
    Order* o = this->order;
    this->order = nullptr;
    return o;
}

void Chef::checkOrder() {
    if(!this->kitchen->getReadyOrders().empty())
    {
        setOrder();
        this->state = COOK;
        move();
        this->clock.restart();
    }
}

void Chef::update() {

    if(!this->order && this->state == WAIT)
    {
        checkOrder();
    }
    if(this->state == COOK)
    {
        cook();
    }
    this->setAnimation();
    this->updateAnimations();
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

void Chef::setKitchen(Kitchen *k) {
    this->kitchen = k;
}

Kitchen *Chef::getKitchen() {
    return this->kitchen;
}

