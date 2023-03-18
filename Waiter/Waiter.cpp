//
// Created by Paolo Sbarzagli on 31/01/23.
//

#include "Waiter.h"

#include <utility>


Waiter::Waiter() {
    initSprite();
    initVariables();
}

Waiter::~Waiter() {

}

void Waiter::initVariables() {
    state = Actions::DOING_NOTHING;
    movingStatus = Move::STANDING;
    preMovingStatus = Move::STANDING;
    speed = 8;
    order = nullptr;
    isReceived = false;
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
    this->movingStatus = Move::STANDING;

    //variabile evento ev

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->movingStatus = Move::MOVING_LEFT;
        if(preMovingStatus != this->movingStatus)
            this->validMovement["Left"] = true;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->movingStatus = Move::MOVING_RIGHT;
        if(preMovingStatus != this->movingStatus)
            this->validMovement["Right"] = true;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->movingStatus = Move::MOVING_UP;
        if(preMovingStatus != this->movingStatus)
            this->validMovement["Up"] = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->movingStatus = Move::MOVING_DOWN;
        if(preMovingStatus != this->movingStatus)
            this->validMovement["Down"] = true;
    }

    setAnimation();
    move();

}

void Waiter::move() {
    //std::cout << "First position: " << this->sprite.getPosition().x << ", " << this->sprite.getPosition().y;
    this->currPos = this->sprite.getPosition();
    this->prevPos = this->currPos;

        switch (this->movingStatus) {
            case Move::MOVING_LEFT:
                if(this->validMovement["Left"])
                {
                    this->sprite.move(this->speed * (-0.15f), this->speed * (0.f));
                    checkReceiving();
                }
                this->dir = Move::MOVING_LEFT;
                break;

            case Move::MOVING_RIGHT:
                if(this->validMovement["Right"])
                {
                    this->sprite.move(this->speed * (0.15f), this->speed * (0.f));
                    checkReceiving();
                }
                this->dir = Move::MOVING_RIGHT;
                break;

            case Move::MOVING_UP:
                if(this->validMovement["Up"])
                {
                    this->sprite.move(this->speed * (0.f), this->speed * (-0.15f));
                    checkReceiving();
                }
                this->dir = Move::MOVING_UP;
                break;

            case Move::MOVING_DOWN:
                if(this->validMovement["Down"])
                {
                    this->sprite.move(this->speed * (0.f), this->speed * (0.15f));
                    checkReceiving();
                }
                this->dir = Move::MOVING_DOWN;
                break;
            case Move::STANDING:
                this->dir = Move::STANDING;
                break;
        }
        /*
    if(prePosition != this->sprite.getPosition() && this->movingStatus != STANDING && this->receivingCustomers)
        this->receivingCustomers->follow(prePosition, this->sprite.getPosition(), this->movingStatus);
    //std::cout << "New position: " << this->sprite.getPosition().x << ", " << this->sprite.getPosition().y;
*/
}

void Waiter::interact(const std::shared_ptr<Map>& map, sf::Event ev) {
    Table* t = map->distanceTable(this->sprite);
    map->distanceEntrance(this->sprite);
    map->distanceKitchen(this->sprite);
    map->distanceWashbasin(this->sprite);
    map->distanceDirtyDishes(this->sprite);
    map->distanceChefDishes(this->sprite);

    if(this->state == Actions::DOING_NOTHING)
    {
        if(!this->order && map->getIsClose() == IS_CLOSE_ENTRANCE && map->getEntrance()->getIsCustomer()
            && ev.key.code == sf::Keyboard::J)
        {
            this->state = Actions::RECEIVING_CUSTOMERS;
            this->sprite.setPosition(920,910);
            map->getEntrance()->setCustomerReceived(false);
            this->receiveState->handleInput(this, ev);
            std::cout << "Receiving customers" << std::endl;
        }
        else if(!this->order && map->getIsClose() == IS_CLOSE_TABLE && t->getIsReady())
        {
            this->state = Actions::TAKING_ORDER;
            this->orderState->handleInput(this, ev);
            this->actionsState->setIsOrder(true);
        }
        else
        {
            this->actionsState->handleInput(this, ev);
            this->state = Actions::DOING_NOTHING;
        }
    }
    else if(this->state == Actions::RECEIVING_CUSTOMERS && ev.key.code == sf::Keyboard::J)
    {
        if(map->distanceInteractionSquare(this->getSprite(), this->receiveState->getTable()))
        {
            this->state = Actions::DOING_NOTHING;
            this->receiveState->getTable()->setCustomers(this->receiveState->getCustomers());
            this->receiveState->moveToTable();
            this->receiveState->getTable()->setIsOccupied(true);
        }
    }
}

std::shared_ptr<Order> Waiter::getOrder() {
    return this->order;
}

void Waiter::setOrder(std::shared_ptr<Order> o) {
    this->order = std::move(o);
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

    if(this->movingStatus == Move::STANDING)
        this->currentFrame.top = 0.f;

    else if(this->movingStatus == Move::MOVING_DOWN)
        this->currentFrame.top = 50.f;

    else if(this->movingStatus == Move::MOVING_LEFT)
        this->currentFrame.top = 100.f;

    else if(this->movingStatus == Move::MOVING_RIGHT)
        this->currentFrame.top = 150.f;

    else if(this->movingStatus == Move::MOVING_UP)
        this->currentFrame.top = 200.f;

    this->sprite.setTextureRect(this->currentFrame);

}

std::shared_ptr<OrderState> Waiter::getOrderState() {
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

bool Waiter::getIsReceived() {
    return this->isReceived;
}

void Waiter::initTexture(sf::Texture* textureW) {       //initTexture with a pointer from Games
    this->sprite.setTexture(*textureW);
}

std::shared_ptr<ActionsState> Waiter::getActionState() {
    return this->actionsState;
}

std::shared_ptr<ReceiveState> Waiter::getReceiveState() {
    return this->receiveState;
}

void Waiter::initStates(const std::shared_ptr<ActionsState>& as, const std::shared_ptr<ReceiveState>& rs, const std::shared_ptr<OrderState>& os) {
    actionsState.reset();
    actionsState = as;
    orderState.reset();
    orderState = os;
    receiveState.reset();
    receiveState = rs;
}

void Waiter::setActionState(const std::shared_ptr<ActionsState>& as) {
    actionsState.reset();
    actionsState = as;
}

void Waiter::setOrderState(const std::shared_ptr<OrderState>& os) {
    orderState.reset();
    orderState = os;
}

void Waiter::setReceiveState(const std::shared_ptr<ReceiveState>& rs) {
    receiveState.reset();
    receiveState = rs;
}

void Waiter::checkReceiving() {
    if(this->state == Actions::RECEIVING_CUSTOMERS)
    {
        this->receiveState->addToPath(this->dir);
    }
}




/*
bool Waiter::getIsCustomer() {
    return this->isCustomer;
}

void Waiter::setIsCustomer(bool t) {
    this->isCustomer = t;
}
*/






