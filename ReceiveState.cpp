//
// Created by Paolo Sbarzagli on 07/03/23.
//

#include "ReceiveState.h"

ReceiveState::ReceiveState(Map *m) {
    this->map = m;
}

ReceiveState::~ReceiveState() {

}

void ReceiveState::handleInput(GameCharacter& gc, sf::Event ev) {

}

void ReceiveState::update(GameCharacter& gc) {
    if(!this->table)
    {
        this->table = pickEmptyTable();
    }
}


Table* ReceiveState::pickEmptyTable() {
    std::vector<Table> t;
    bool notFound = true;

    while(!this->map->getAllTables().empty() && notFound)
    {
        t.push_back(this->map->getAllTables().back());
        this->map->getAllTables().pop_back();
        if(!t.back().getIsOccupied())
        {
            notFound = false;
            this->table = &t.back();
            this->table->setIsOccupied(true);
            while(!t.empty())
            {
                this->map->getAllTables().push_back(t.back());
                t.pop_back();
            }
        }
    }
    return this->table;
}


Move ReceiveState::checkState(float distX, float distY) {
    Move direction = MOVING_LEFT;
    if(distX != 0 && distY == 0)
    {
        if(distX < 0)
            direction = MOVING_RIGHT;
        else if(distX > 0)
            direction = MOVING_LEFT;
    }
    else if(distX == 0 && distY != 0)
    {
        if(distY < 0)
            direction = MOVING_DOWN;
        else if(distY > 0)
            direction = MOVING_UP;
    }
    else
    {
        //TODO IMPLEMENT CASE IN WHICH BOTH ARE DIFFERENT
    }
    return direction;
}


void ReceiveState::move() {
    /*
     * Move the selected customer in the specific position indicated
     */
    float x, y;
    for(auto & it : this->customers)
    {
        while(it.getOffsetX() + it.getOffsetY() > TOTAL_OFFSET)
        {
            it.setOffsetX(abs(it.getPath().front().x - it.sprite.getPosition().x));
            it.setOffsetY(abs(it.getPath().front().y - it.sprite.getPosition().y));
            if(x > 2)
            {

            }
            if(y > 2)
            {

            }
        }
    }


}

void ReceiveState::follow(sf::Vector2f prePosition, sf::Vector2f finalPosition, Move status) {
    /*
     * if previous moving status = final moving status then just modify the value of dist
     * if change of direction then set a new breakpoint
     */

    float distX = (prePosition.x - finalPosition.x);
    float distY = (prePosition.y - finalPosition.y);
    Move direction = checkState(distX, distY);
/*
    for(auto & tmp : this->map->getEntrance()->getCustomers())
    {
        if(tmp.getPath().back().getMove() == direction)
            tmp.getPath().back().setDist(finalPosition);
        else
            tmp.setPath(finalPosition, direction);
    }
*/
}

void ReceiveState::setTable(Table *t) {
    this->table = t;
}

Table *ReceiveState::getTable() {
    return this->table;
}

void ReceiveState::setCustomer(Customer *c) {
    this->customer = c;
}

Customer *ReceiveState::getCustomer() {
    return this->customer;
}

void ReceiveState::setCustomers(Customer& c) {
    this->customers.push_back(c);
}

std::vector<Customer> &ReceiveState::getCustomers() {
    return this->customers;
}

void ReceiveState::setGeneratedCustomers(int numberCustomer, int textureNumber) {
    if(numberCustomer == 4) {
        this->customers.back().sprite.setPosition(1550, 910);   //1000, 700
        this->customers.back().setEndingPosition(sf::Vector2f{1300, 910}, MOVING_LEFT);

        std::cout << "4" << std::endl;
    }
    else if(numberCustomer == 3) {
        this->customers.back().sprite.setPosition(1500, 910);   //1000, 800
        this->customers.back().setEndingPosition(sf::Vector2f{1200, 910}, MOVING_LEFT);

        std::cout << "3" << std::endl;

    }
    else if(numberCustomer == 2) {
        this->customers.back().sprite.setPosition(1450, 910);   //1100, 700
        this->customers.back().setEndingPosition(sf::Vector2f{1100, 910}, MOVING_LEFT);

        std::cout << "2" << std::endl;

    }
    else if(numberCustomer == 1) {
        this->customers.back().sprite.setPosition(1400, 910); //always generated
        this->customers.back().setEndingPosition(sf::Vector2f{1000, 910}, MOVING_LEFT);
        std::cout << "1" << std::endl;

    }
    if(textureNumber-1 % 4 == 0)
        this->customers.back().sprite.setTexture(*this->texture->getTexture("Customer1"));
    if(textureNumber-1 % 4 == 1)
        this->customers.back().sprite.setTexture(*this->texture->getTexture("Customer2"));
    if(textureNumber-1 % 4 == 2)
        this->customers.back().sprite.setTexture(*this->texture->getTexture("Customer3"));
    if(textureNumber-1 % 4 == 3)
        this->customers.back().sprite.setTexture(*this->texture->getTexture("Customer4"));


    this->customers.back().setSprite();
    std::cout << "set customer" << std::endl;

}

void ReceiveState::moveToChair(sf::Sprite* sprite) {
    /*
     * Keep a constant distance from the sprite before calling the rest of the functions
     */
    sf::Vector2f previous = sprite->getPosition();
    for(auto & it: this->customers)
    {
        it.setPath(previous);
        previous = it.getPosition();
    }
    move();
}

