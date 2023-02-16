//
// Created by Paolo Sbarzagli on 31/01/23.
//

#include "Waiter.h"


Waiter::Waiter() {
    initSprite();
    this->state = STANDING;
    this->speed = 8;
    this->isClose = IS_CLOSE_NOTHING;
    this->tray = nullptr;
    this->order = nullptr;

}

Waiter::~Waiter() {
    delete this->tray;
    delete this->order;
}

void Waiter::initSprite() {
    /*
     * Set the texture on the sprite and resize it
     */
    this->sprite.setTexture(*this->texture->getTexture("Waiter"));
    this->currentFrame = sf::IntRect (0,0,50,50);
    this->sprite.setTextureRect(this->currentFrame);
    this->sprite.setScale(2.5,2.5);
}

void Waiter::updateMovement() {
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

    setAnimation();
    if(this->state == STANDING && (sf::Keyboard::isKeyPressed(sf::Keyboard::J) ||
    sf::Keyboard::isKeyPressed(sf::Keyboard::L) || sf::Keyboard::isKeyPressed(sf::Keyboard::K)))
        interact();
    else
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

void Waiter::interact() {
    Table* table = distanceTable();
    Kitchen* kitchen = distanceKitchen();
    Washbasin* washbasin = distanceWashbasin();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::J) && !this->tray)
    {

        if(this->order && this->isClose == IS_CLOSE_KITCHEN)
            leavingOrder(kitchen);
        else if(!this->order && this->isClose == IS_CLOSE_TABLE) {
            takingOrder(table);
            std::cout << "IsClose Table works correctly" << std::endl;
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::K) && this->tray && !this->order &&
    (this->isClose == IS_CLOSE_TABLE || this->isClose == IS_CLOSE_KITCHEN))
    {
        if(this->isClose == IS_CLOSE_TABLE)
            pickUp(table);
        else if(this->isClose == IS_CLOSE_KITCHEN)
            pickUp(kitchen);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::L) && this->tray && !this->order &&
    (this->isClose == IS_CLOSE_TABLE || this->isClose == IS_CLOSE_DISHWASHER))
    {
        if (this->isClose == IS_CLOSE_TABLE)
            putDown(table);
        else if (this->isClose == IS_CLOSE_DISHWASHER)
            putDown(washbasin);
    }
    this->isClose = IS_CLOSE_NOTHING;
}


void Waiter::pickUp(Kitchen* kitchen) {
    //TODO: PICK UP THE PLATES FROM THE KITCHEN
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
    //TODO: PICK UP THE EMPTY PLATES FROM THE TABLE
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



Table *Waiter::distanceTable() {
    /*
     * Calculate the position of the waiter from the Tables
     */

    sf::Vector2f distVector;
    sf::FloatRect waiter, table;
    float centreTableX, centreTableY;
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

        //std::cout << "CentreWaiter" << centreWaiterX << ", " << centreWaiterY << std::endl;
        t = &this->map->getTable(i);
        dist = std::sqrt(std::pow(t->sprite.getPosition().x - this->sprite.getPosition().x, 2) +
                std::pow(t->sprite.getPosition().y - this->sprite.getPosition().y, 2));
        //centreTableX = t->getPosition().x; //+ (t->sprite.getGlobalBounds().width/2);
        //centreTableY = t->getPosition().y; //+ (t->sprite.getGlobalBounds().height/2);

        //distX = std::abs(centreTableX - this->centreWaiterX);
        //distY = std::abs(centreTableY - this->centreWaiterY);
        std::cout << std::endl << "table: " << i << " posX: " << t->sprite.getPosition().x << " PosY:" <<
        t->sprite.getPosition().y << std::endl;
        std::cout << "dist: " << dist << std::endl;
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
    sf::Vector2f distVector;
    float dist;
    Kitchen* kitchen = this->map->getKitchen();

    distVector = this->sprite.getPosition() - kitchen->getPosition();
    dist = sqrt((distVector.x * distVector.x) + (distVector.y * distVector.y));

    if(dist <= 100)
    {
        this->isClose = IS_CLOSE_KITCHEN;
    }

    return kitchen;
}


Washbasin *Waiter::distanceWashbasin() {
    /*
     * Calculate the position of the waiter from the Washbasin
     */
    sf::Vector2f distVector;
    float dist;
    Washbasin* washbasin = this->map->getWashbasin();

    distVector = this->sprite.getPosition() - washbasin->getPosition();
    dist = sqrt((distVector.x * distVector.x) + (distVector.y * distVector.y));

    if(dist <= 1)
    {
        this->isClose = IS_CLOSE_DISHWASHER;
    }
    return washbasin;
}


void Waiter::update() {
    updateAnimations();
    updateMovement();
    updateCentre();
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

Actions Waiter::getState() {
    return this->state;
}

Map *Waiter::getMap() {
    return this->map;
}

void Waiter::setMap(Map *m) {
    this->map = m;
}

void Waiter::updateCentre() {
    this->centreWaiterX = this->sprite.getGlobalBounds().left + (this->sprite.getGlobalBounds().width/2);
    this->centreWaiterY = this->sprite.getGlobalBounds().top + (this->sprite.getGlobalBounds().height/2);
}


