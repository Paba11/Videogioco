//
// Created by Paolo Sbarzagli on 31/01/23.
//

#include "Waiter.h"


Waiter::Waiter() {
    initSprite();
    this->state = DOING_NOTHING;
    this->movingStatus = STANDING;
    this->preMovingStatus = STANDING;
    this->speed = 8;
    this->tray = new Tray();
    this->order = nullptr;
    this->orderState = nullptr;
    this->receivingCustomers = nullptr;
    this->targetCustomer = nullptr;
    this->isReceived = false;
}

Waiter::~Waiter() {
    delete this->tray;
    delete this->order;
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
    Washbasin* washbasin = map->distanceWashbasin(this->sprite);
    Kitchen* kitchen = map->distanceKitchen(this->sprite);
    Entrance* entrance = map->distanceEntrance(this->sprite);
    Table* table = map->distanceTable(this->sprite);
    /*
    delete this->wState;
    if(!this->order && map->getIsClose() == IS_CLOSE_ENTRANCE && map->getEntrance()->getIsCustomer())
    {
        this->state = RECEIVING_CUSTOMERS;
        this->wState = new ReceiveState(map);
    }
    else if(!this->order && map->getIsClose() == IS_CLOSE_TABLE)
    {
        this->state = TAKING_ORDER;
        this->wState = new OrderState(table);
    }
    else
        this->wState = new ActionsState(map);

    this->wState->handleInput(*this, ev);
*/
}


void Waiter::pickUp(Kitchen* kitchen) {
    //PICK UP THE PLATES FROM THE KITCHEN

    Dish* d;
    if(this->tray->getState() == EMPTY_TRAY && kitchen->getState() == FULL)
    {
        this->state = TAKING_DISHES;
        while (!kitchen->getDishes().empty())
        {
            d = kitchen->getDish();
            this->tray->setDish(d);
            this->tray->update();
            kitchen->update();
            this->update();
        }
        //Set the tray to filled
        tray->setState(FILLED_TRAY);
        //Set the kitchen to empty
        kitchen->setState(0);
    }

    this->state = DOING_NOTHING;
}


void Waiter::pickUp(Table* table) {
    //PICK UP THE EMPTY PLATES FROM THE TABLE

    Dish* d;
    if(this->tray->getState() == EMPTY_TRAY && table->getState() == ENDED)
    {
        this->state = TAKING_EMPTY_DISHES;
        while(!table->getDishes().empty())
        {

            d = table->getDish();
            this->tray->setDish(d);
            this->tray->update();
            table->update();
            update();
        }

        //Set the tray to empty plates
        tray->setState(EMPTY_PLATES);

        //Set the table to the next instruction on the order
        switch(table->getCourse())
        {
            case APPETIZER:
                table->setState(WAITING_DISHES);
                table->setCourse(MAIN_DISH);
                break;
            case MAIN_DISH:
                table->setState(WAITING_DISHES);
                table->setCourse(DESSERT);
                break;
            case DESSERT:
                table->setState(ENDED);
                table->setCourse(END);
                break;
        }
    }
    this->state = DOING_NOTHING;
}

void Waiter::putDown(Table* table) {
    //Leave the plates at the table

    if(this->tray->getState() == FILLED_TRAY && table->getState() == WAITING_DISHES &&
    this->tray->getDishes().front()->getTavNum() == table->getTavNum())
    {
        this->state = LEAVING_DISHES;

        while(!this->tray->getDishes().empty())
        {
            table->setDish(this->tray->getDish());
            this->tray->update();
            table->update();
            update();
        }

        //Set the table in the right state
        table->setState(EATING);
        //Set the tray in the right state
        this->tray->setState(EMPTY_TRAY);
    }

    this->state = DOING_NOTHING;
}

void Waiter::putDown(Washbasin* washbasin) {
    //Lave the plates at the washbasin

    if(this->tray->getState() == EMPTY_PLATES && !washbasin->getIsPlates())
    {
        this->state = LEAVING_EMPTY_DISHES;

        //Set the table in the right state
        washbasin->setIsPlates(true);
        int count = 0;

        while(!this->tray->getDishes().empty())
        {
            count++;
            this->tray->getDish();
            this->tray->update();
            washbasin->update();
            update();
        }
        washbasin->setNumPlates(count);
        //Set the tray in the right state
        this->tray->setState(EMPTY_TRAY);
    }
    this->state = DOING_NOTHING;
}

void Waiter::takingOrder(Table* table) {
    this->order = new Order;
    this->orderState->setOrderVariables(table, this->order);

}

void Waiter::leavingOrder(Kitchen* kitchen) {
    //Leave the order at the kitchen

    if(this->order)
    {
        this->state = LEAVING_ORDER;
        kitchen->insertNewOrder(order);
        kitchen->update();
        this->order = nullptr;
    }
    this->state = DOING_NOTHING;
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

Actions Waiter::getState() {
    return this->state;
}

OrderState *Waiter::getOrderState() {
    return this->orderState;
}

void Waiter::setOrderState(OrderState *o) {
    this->orderState = o;
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


/*
bool Waiter::getIsCustomer() {
    return this->isCustomer;
}

void Waiter::setIsCustomer(bool t) {
    this->isCustomer = t;
}
*/






