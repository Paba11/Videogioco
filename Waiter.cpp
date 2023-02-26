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
    this->isClose = IS_CLOSE_NOTHING;
    this->tray = new Tray();
    this->order = nullptr;
    this->orderState = nullptr;
    this->receivingCustomers = nullptr;
    this->targetCustomer = nullptr;
}

Waiter::~Waiter() {
    delete this->tray;
    delete this->order;
}


void Waiter::initSprite() {
    /*
     * Set the texture on the sprite and resize it
     */
    this->sprite.setPosition(800,400);
    this->sprite.setTexture(*this->texture->getTexture("Waiter"));
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
            validMovement["Left"] = true;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->movingStatus = MOVING_RIGHT;
        if(preMovingStatus != this->movingStatus)
            validMovement["Right"] = true;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->movingStatus = MOVING_UP;
        if(preMovingStatus != this->movingStatus)
            validMovement["Up"] = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->movingStatus = MOVING_DOWN;
        if(preMovingStatus != this->movingStatus)
            validMovement["Down"] = true;
    }

    setAnimation();
    //CONTROL THE INTERACTIONS
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::J) || sf::Keyboard::isKeyPressed(sf::Keyboard::L)
    || sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        interactionManagement();
    else
        move();

}

void Waiter::move() {

        switch (this->movingStatus) {
            case MOVING_LEFT:
                if(validMovement["Left"])
                    this->sprite.move(this->speed * (-0.15f), this->speed * (0.f));
                break;

            case MOVING_RIGHT:
                if(validMovement["Right"])
                    this->sprite.move(this->speed * (0.15f), this->speed * (0.f));
                break;

            case MOVING_UP:
                if(validMovement["Up"])
                    this->sprite.move(this->speed * (0.f), this->speed * (-0.15f));
                break;

            case MOVING_DOWN:
                if(validMovement["Down"])
                    this->sprite.move(this->speed * (0.f), this->speed * (0.15f));
                break;
            case STANDING:
                break;
        }

}

void Waiter::interact() {
    Table* table = distanceTable();
    Kitchen* kitchen = distanceKitchen();
    Washbasin* washbasin = distanceWashbasin();
    distanceEntrance();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::J))
    {

        if(this->order && this->isClose == IS_CLOSE_KITCHEN) {
            leavingOrder(kitchen);
            std::cout << "IsClose Kitchen works correctly" << std::endl;
            this->isClose = IS_CLOSE_NOTHING;
        }
        else if(!this->order && this->isClose == IS_CLOSE_TABLE) {
            takingOrder(table);
            std::cout << "IsClose Table works correctly" << std::endl;
            this->isClose = IS_CLOSE_NOTHING;
        }
        else if(!this->order && this->isClose == IS_CLOSE_ENTRANCE && this->map->getEntrance()->getIsCustomer()) {
            this->state = RECEIVING_CUSTOMERS;
            this->targetTable = receivingCustomers->pickEmptyTable();
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::K) && this->tray->getState() == EMPTY_TRAY && !this->order &&
    (this->isClose == IS_CLOSE_TABLE || this->isClose == IS_CLOSE_KITCHEN))
    {
        if(this->isClose == IS_CLOSE_TABLE) {
            pickUp(table);
            std::cout << "PickUp table works correctly" << std::endl;
        }
        else if(this->isClose == IS_CLOSE_KITCHEN) {
            pickUp(kitchen);
            std::cout << "PickUp kitchen works correctly" << std::endl;
        }
        this->isClose = IS_CLOSE_NOTHING;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::L) && !this->order &&
    (this->isClose == IS_CLOSE_TABLE || this->isClose == IS_CLOSE_DISHWASHER))
    {
        if (this->isClose == IS_CLOSE_TABLE && this->tray->getState() == FILLED_TRAY) {
            putDown(table);
            std::cout << "PutDown Table works correctly" << std::endl;
        }
        else if (this->isClose == IS_CLOSE_DISHWASHER && this->tray->getState() == EMPTY_PLATES) {
            putDown(washbasin);
            std::cout << "IsClose Table works correctly" << std::endl;
        }
        this->isClose = IS_CLOSE_NOTHING;
    }

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

const sf::Vector2f &Waiter::getPosition() const {
    return this->sprite.getPosition();
}



Table *Waiter::distanceTable() {
    /*
     * Calculate the position of the waiter from the Tables
     */

    float dist;
    Table* t = nullptr;
    /*
    for(int i = 0; i < this->map->getAllTables().size(); i++)
    {
        std::cout << std::endl << "table: " << i << " position: " << this->map->getTable(i).getPosition().x
        << ", " << this->map->getTable(i).getPosition().y << std::endl;
    }
    */
    for(int i = 0; i < this->map->getAllTables().size() && this->isClose != IS_CLOSE_TABLE; i++)
    {

        t = &this->map->getTable(i);
        dist = std::sqrt(std::pow(t->sprite.getPosition().x - this->sprite.getPosition().x, 2) +
                std::pow(t->sprite.getPosition().y - this->sprite.getPosition().y, 2));

        std::cout << std::endl << "table " << i; //<< " posX: " << t->sprite.getPosition().x << " PosY:" <<
        // << t->sprite.getPosition().y << std::endl;
        std::cout << " dist: " << dist << std::endl;

        if (dist <= 130 )
        {
            std::cout << "dist <= 10 table: " << i << std::endl;
            //t = &this->map->getTable(i);
            this->isClose = IS_CLOSE_TABLE;
        }
    }
    return t;
}

Kitchen *Waiter::distanceKitchen() {
    /*
     * Calculate the position of the waiter from the Kitchen
     */

    float dist;
    Kitchen* k = this->map->getKitchen();

    //std::cout << std::endl << " posX: " << k->getSprite().getPosition().x << " PosY: " <<
    //          k->getSprite().getPosition().y << std::endl;

    dist = std::sqrt(std::pow(k->getSprite().getPosition().x - this->sprite.getPosition().x, 2) +
                     std::pow(k->getSprite().getPosition().y - this->sprite.getPosition().y, 2));

    std::cout << "Kitchen Dist: " << dist << std::endl;

    if(dist <= 120)
    {
        this->isClose = IS_CLOSE_KITCHEN;
    }

    return k;
}


Washbasin *Waiter::distanceWashbasin() {
    /*
     * Calculate the position of the waiter from the Washbasin
     */

    float dist;
    Washbasin* w = this->map->getWashbasin();

    //std::cout << std::endl << " posX: " << w->getSprite().getPosition().x << " PosY: " <<
    //        w->getSprite().getPosition().y << std::endl;

    dist = std::sqrt(std::pow(w->getSprite().getPosition().x - this->sprite.getPosition().x, 2) +
            std::pow(w->getSprite().getPosition().y - this->sprite.getPosition().y, 2));

    std::cout << "Washbasin dist: " << dist << std::endl;

    if(dist <= 190)
    {
        this->isClose = IS_CLOSE_DISHWASHER;
    }

    return w;
}

Entrance *Waiter::distanceEntrance() {
    float dist;
    Entrance* e = this->map->getEntrance();

    dist = std::sqrt(std::pow(e->getSprite().getPosition().x - this->sprite.getPosition().x, 2) +
                     std::pow(e->getSprite().getPosition().y - this->sprite.getPosition().y, 2));

    std::cout << "Entrance distance: " << dist << std::endl;

    if(dist <= 100)
    {
        this->isClose = IS_CLOSE_ENTRANCE;
    }
    return e;
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

Map *Waiter::getMap() {
    return this->map;
}

void Waiter::setMap(Map *m) {
    this->map = m;
}

OrderState *Waiter::getOrderState() {
    return this->orderState;
}

void Waiter::setOrderState(OrderState *o) {
    this->orderState = o;
}


bool Waiter::distanceSpecificTable(Table *t) {
    float dist;
    bool isCloseTable = false;

    dist = std::sqrt(std::pow(t->sprite.getPosition().x - this->sprite.getPosition().x, 2) +
                     std::pow(t->sprite.getPosition().y - this->sprite.getPosition().y, 2));

    if(dist <= 20)
    {
        isCloseTable = true;
    }

    return isCloseTable;
}

Move Waiter::getMove() {
    return this->movingStatus;
}

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
    }
}

void Waiter::interactionManagement() {
    if(this->state != RECEIVING_CUSTOMERS && this->state != TAKING_ORDER)
        interact();
    else if(this->state == RECEIVING_CUSTOMERS && distanceSpecificTable(this->targetTable))
        receivedCustomers();
}

void Waiter::setReceivingCustomers(ReceivingCustomers *rc) {
    this->receivingCustomers = rc;
}

/*
bool Waiter::getIsCustomer() {
    return this->isCustomer;
}

void Waiter::setIsCustomer(bool t) {
    this->isCustomer = t;
}
*/






