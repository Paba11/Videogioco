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
    if (!this->texture.loadFromFile("../Textures/MaleWaiter.png"))
    {
        std::cout << "ERROR::WAITER::CAN'T LOAD TEXTURE FILE" << std::endl;
    }
}

void Waiter::initSprite() {
    /*
     * Set the texture on the sprite and resize it
     */
    this->sprite.setTexture(this->texture);

    this->sprite.setScale(0.3f, 0.3f);
}

void Waiter::updateMovement(sf::Event ev, const Map& map) {
    switch(this->state)
    {
        case STANDING:
            if (ev.key.code == sf::Keyboard::A)
            {
                this->state = MOVING_LEFT;
                //setAnimation();
                move();
            }
            else if (ev.key.code == sf::Keyboard::D)
            {
                this->state = MOVING_RIGHT;
                //setAnimation();
                move();
            }
            else if (ev.key.code == sf::Keyboard::W)
            {
                this->state = MOVING_UP;
                //setAnimation();
                move();
            }
            else if (ev.key.code == sf::Keyboard::S)
            {
                this->state = MOVING_DOWN;
                //setAnimation();
                move();
            }
            else
            {
                interact(ev, map);
            }
            break;
    }
    this->state = STANDING;
    //setAnimation();
}

void Waiter::move() {
    switch(this->state)
    {
        case MOVING_LEFT:
            this->sprite.move(this->speed * (-1.0f), this->speed * (0.f));
            break;
        case MOVING_RIGHT:
            this->sprite.move(this->speed * (1.0f), this->speed * (0.f));
            break;
        case MOVING_UP:
            this->sprite.move(this->speed * (0.f), this->speed * (-1.0f));
            break;
        case MOVING_DOWN:
            this->sprite.move(this->speed * (0.f), this->speed * (1.0f));
            break;
        case STANDING:
            break;
    }
}

void Waiter::setAnimation() {
    switch(this->state)
    {
        case MOVING_LEFT:
            if(!this->texture.loadFromFile("../Textures/MaleWaiter.png"))
            {
                std::cout << "ERROR::WAITER::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
            break;
        case MOVING_RIGHT:
            if(!this->texture.loadFromFile("../Textures/MaleWaiter.png"))
            {
                std::cout << "ERROR::WAITER::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
            break;
        case MOVING_UP:
            if(!this->texture.loadFromFile("../Textures/MaleWaiter.png"))
            {
                std::cout << "ERROR::WAITER::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
            break;
        case MOVING_DOWN:
            if(!this->texture.loadFromFile("../Textures/MaleWaiter.png"))
            {
                std::cout << "ERROR::WAITER::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
            break;
        case STANDING:
            if(!this->texture.loadFromFile("../Textures/MaleWaiter.png"))
            {
                std::cout << "ERROR::WAITER::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
            break;
    }
}

void Waiter::interact(sf::Event ev, const Map& map) {
    Table* table = distanceTable(map);
    Kitchen* kitchen = distanceKitchen(map);
    Washbasin* washbasin = distanceWashbasin(map);
    switch(ev.type)
    {
        case ev.KeyPressed:
            if(ev.key.code == sf::Keyboard::J && !this->tray)
            {
                if(this->order && this->isClose == IS_CLOSE_KITCHEN)
                    leavingOrder(kitchen);
                else if(!this->order && this->isClose == IS_CLOSE_TABLE)
                    takingOrder(table);
            }
            else if(ev.key.code == sf::Keyboard::K && this->tray && !this->order &&
            (this->isClose == IS_CLOSE_TABLE || this->isClose == IS_CLOSE_KITCHEN))
            {
                if(this->isClose == IS_CLOSE_TABLE)
                    pickUp(table);
                else if(this->isClose == IS_CLOSE_KITCHEN)
                    pickUp(kitchen);
            }
            else if(ev.key.code == sf::Keyboard::L && this->tray && !this->order &&
            (this->isClose == IS_CLOSE_TABLE || this->isClose == IS_CLOSE_DISHWASHER))
            {
                if (this->isClose == IS_CLOSE_TABLE)
                    putDown(table);
                else if (this->isClose == IS_CLOSE_DISHWASHER)
                    putDown(washbasin);
            }
            this->isClose = IS_CLOSE_NOTHING;
            break;

    }
}


void Waiter::pickUp(Kitchen* kitchen) {
    //TO DO: PICK UP THE PLATES FROM THE KITCHEN
    Dish* d;
    if(this->tray->getState() == EMPTY_TRAY && kitchen->getState() == FULL)
    {
        for(int i = 0; i < MAX_DISHES; i++)
        {
            if(kitchen->getDish(i))
            {
                d = kitchen->getDish(i);
                this->tray->setDish(i, d);
                kitchen->setDish(i, nullptr);
                this->tray->update();
                kitchen->update();
                this->update();
            }
            else
                i = MAX_DISHES;
        }
        //Set the tray to filled
        tray->setState(2);
        //Set the kitchen to empty
        kitchen->setState(1);
    }
}

void Waiter::pickUp(Table* table) {
    //TO DO: PICK UP THE EMPTY PLATES FROM THE TABLE
    Dish* d;
    if(this->tray->getState() == EMPTY_TRAY && table->getState() == ENDED)
    {
        for(int i = 0; i < MAX_DISHES; i++)
        {
            if(table->getDish(i))
            {
                d = table->getDish(i);
                this->tray->setDish(i, d);
                table->setDish(i, nullptr);
                this->tray->update();
                table->update();
                update();
            }
            else
                i = MAX_DISHES;
        }
        //Set the tray to empty plates
        tray->setState(3);
        //Set the table to the next instruction on the order
        switch(table->getCourse())
        {
            case APPETIZER:
                table->setState(3);
                break;
            case MAINCOURSE:
                table->setState(3);
                break;
            case DESSERT:
                table->setState(5);
                break;
        }
    }
}

void Waiter::putDown(Table* table) {
    //Leave the plates at the table
    if(this->tray->getState() == FILLED_TRAY && table->getState() == WAITING_DISHES)
    {
        for(int i = 0; i < MAX_DISHES; i++)
        {
            if(this->tray->getDish(i))
            {
                table->setDish(i, this->tray->getDish(i));
                this->tray->setDish(i, nullptr);
                this->tray->update();
                table->update();
                update();
            }
            else
                i = MAX_DISHES;
        }
        //Set the table in the right state
        table->setState(4);
        //Set the tray in the right state
        this->tray->setState(1);
    }
}

void Waiter::putDown(Washbasin* washbasin) {
    //Lave the plates at the washbasin
    if(this->tray->getState() == EMPTY_PLATES && !washbasin->getIsPlates())
    {
        this->tray->setDish(1, nullptr);
        //Set the table in the right state
        washbasin->setIsPlates(true);
        washbasin->update();
        //Set the tray in the right state
        this->tray->setState(1);
    }

}

void Waiter::takingOrder(Table* table) {

}

void Waiter::leavingOrder(Kitchen* kitchen) {
    //Leave the order at the kitchen
    if(this->order)
    {
        kitchen->insertNewOrder(order);
        kitchen->update();
        this->order = nullptr;
    }

}

const sf::Vector2f &Waiter::getPosition() const {
    return this->sprite.getPosition();
}

Table *Waiter::distanceTable(const Map& map) const {
    /*
     * Calculate the position of the waiter from the Tables
     */

    float x;
    float y;
    Table* t = nullptr;
    for(int i = 0; i < MAX_SIZE; i++)
    {
        x = abs(getPosition().x - map.getTable(i)->getPosition().x);
        y = abs(getPosition().y - map.getTable(i)->getPosition().y);
        if (x <= 1 && y <= 1)
        {
            t = map.getTable(i);
            i = MAX_SIZE;
        }
    }
    return t;
}

Kitchen *Waiter::distanceKitchen(const Map& map) const {
    /*
     * Calculate the position of the waiter from the Kitchen
     */
    return map.getKitchen();
}

Washbasin *Waiter::distanceWashbasin(const Map& map) const {
    /*
     * Calculate the position of the waiter from the Washbasin
     */
    return map.getWashbasin();
}



