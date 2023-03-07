//
// Created by Paolo Sbarzagli on 31/01/23.
//

#include "Waiter.h"


Waiter::Waiter() {
    initSprite();
    initVariables();
}

Waiter::~Waiter() {
    delete this->order;
}

void Waiter::initVariables() {
    this->state = DOING_NOTHING;
    this->movingStatus = STANDING;
    this->preMovingStatus = STANDING;
    this->speed = 8;
    this->order = nullptr;
    this->receivingCustomers = nullptr;
    this->targetCustomer = nullptr;
    this->isReceived = false;
}

void Waiter::initSprite() {
    /*
     * Set the texture on the sprite and resize it
     */
    this->sprite.setOrigin(25, 50);
    this->sprite.setPosition(800,400);
    //this->sprite.setTexture(*this->texture->getTexture("Waiter"));
    this->currentFrame = sf::IntRect (0,0,50,50);
    this->sprite.setTextureRect(this->currentFrame);
    this->sprite.setScale(2.5,2.5);
}


void Waiter::updateMovement() {
    this->preMovingStatus = this->movingStatus;
    this->movingStatus = STANDING;

    //variabile evento ev

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->movingStatus = MOVING_LEFT;
        if(preMovingStatus != this->movingStatus)
            this->validMovement["Left"] = true;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->movingStatus = MOVING_RIGHT;
        if(preMovingStatus != this->movingStatus)
            this->validMovement["Right"] = true;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->movingStatus = MOVING_UP;
        if(preMovingStatus != this->movingStatus)
            this->validMovement["Up"] = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->movingStatus = MOVING_DOWN;
        if(preMovingStatus != this->movingStatus)
            this->validMovement["Down"] = true;
    }

    setAnimation();
    move();

}

void Waiter::move() {
    //std::cout << "First position: " << this->sprite.getPosition().x << ", " << this->sprite.getPosition().y;
    sf::Vector2f prePosition = this->sprite.getPosition();
        switch (this->movingStatus) {
            case MOVING_LEFT:
                if(this->validMovement["Left"])
                    this->sprite.move(this->speed * (-0.15f), this->speed * (0.f));
                break;

            case MOVING_RIGHT:
                if(this->validMovement["Right"])
                    this->sprite.move(this->speed * (0.15f), this->speed * (0.f));
                break;

            case MOVING_UP:
                if(this->validMovement["Up"])
                    this->sprite.move(this->speed * (0.f), this->speed * (-0.15f));
                break;

            case MOVING_DOWN:
                if(this->validMovement["Down"])
                    this->sprite.move(this->speed * (0.f), this->speed * (0.15f));
                break;
            case STANDING:
                break;
        }
        /*
    if(prePosition != this->sprite.getPosition() && this->movingStatus != STANDING && this->receivingCustomers)
        this->receivingCustomers->follow(prePosition, this->sprite.getPosition(), this->movingStatus);
    //std::cout << "New position: " << this->sprite.getPosition().x << ", " << this->sprite.getPosition().y;
*/
}

void Waiter::interact(Map* map, sf::Event ev) {
    map->distanceTable(this->sprite);
    map->distanceEntrance(this->sprite);
    map->distanceKitchen(this->sprite);
    map->distanceWashbasin(this->sprite);

    if(!this->order && map->getIsClose() == IS_CLOSE_ENTRANCE && map->getEntrance()->getIsCustomer())
    {
        this->state = RECEIVING_CUSTOMERS;
        this->receiveState->handleInput(*this, ev);
    }
    else if(!this->order && map->getIsClose() == IS_CLOSE_TABLE)
    {
        this->state = TAKING_ORDER;
        this->orderState->handleInput(*this, ev);
    }
    else
        this->actionsState->handleInput(*this, ev);

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

    if(this->movingStatus == STANDING)
        this->currentFrame.top = 0.f;

    else if(this->movingStatus == MOVING_DOWN)
        this->currentFrame.top = 50.f;

    else if(this->movingStatus == MOVING_LEFT)
        this->currentFrame.top = 100.f;

    else if(this->movingStatus == MOVING_RIGHT)
        this->currentFrame.top = 150.f;

    else if(this->movingStatus == MOVING_UP)
        this->currentFrame.top = 200.f;

    this->sprite.setTextureRect(this->currentFrame);

}

OrderState* Waiter::getOrderState() {
    return this->orderState;
}

Move Waiter::getMove() {
    return this->movingStatus;
}

/*
void Waiter::receivedCustomers() {
    if(distanceSpecificTable(this->targetTable))
    {
        //Move all the customer object inside the table vector
        this->targetTable->receivingCustomers(this->receivingCustomers->getCustomers());
        delete this->receivingCustomers;
        this->receivingCustomers = nullptr;
        delete this->targetTable;
        this->targetTable = nullptr;
        this->map->getEntrance()->setIsCustomer(false);
        this->state = DOING_NOTHING;
        this->isReceived = false;
    }
}

void Waiter::interactionManagement() {
    if(this->state != RECEIVING_CUSTOMERS && this->state != TAKING_ORDER)
        interact();
    else if(this->state == RECEIVING_CUSTOMERS && distanceSpecificTable(this->targetTable))
        receivedCustomers();

}
*/
void Waiter::setReceivingCustomers(ReceivingCustomers *rc) {
    this->receivingCustomers = rc;
}

bool Waiter::getIsReceived() {
    return this->isReceived;
}

void Waiter::initTexture(sf::Texture* textureW) {       //initTexture with a pointer from Games
    this->sprite.setTexture(*textureW);
}

ActionsState *Waiter::getActionState() {
    return this->actionsState;
}

ReceiveState *Waiter::getReceiveState() {
    return this->receiveState;
}

void Waiter::initStates(Map *map) {
    this->actionsState = new ActionsState(map);
    this->orderState = new OrderState(map);
    this->receiveState = new ReceiveState(map);
}




/*
bool Waiter::getIsCustomer() {
    return this->isCustomer;
}

void Waiter::setIsCustomer(bool t) {
    this->isCustomer = t;
}
*/






