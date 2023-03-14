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
    this->table = pickEmptyTable();
    update(gc);
}

void ReceiveState::update(GameCharacter& gc) {
    move();
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


void ReceiveState::move() {
    /*
     * Move the selected customer
     */

    int i = 1;
    for(auto & it: this->customers)
    {
        if(it.getPath().size() > i * INITIAL_MOVES)
        {
            it.setMovingStatus(it.getPath().front());
            it.getPath().pop();
            it.move();
        }
        i += 1;
    }
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
    if(numberCustomer == 1) {
        this->customers.back().sprite.setPosition(1550, 910);   //1000, 700
        this->customers.back().setEndingPosition(sf::Vector2f{1256, 910}, MOVING_LEFT);
        for(int i = 0; i < 4 * INITIAL_MOVES; i++)
            this->customers.back().setPath(MOVING_LEFT);
        std::cout << "4" << std::endl;
    }
    else if(numberCustomer == 2) {
        this->customers.back().sprite.setPosition(1500, 910);   //1000, 800
        this->customers.back().setEndingPosition(sf::Vector2f{1172, 910}, MOVING_LEFT);
        for(int i = 0; i < 3 * INITIAL_MOVES; i++)
            this->customers.back().setPath(MOVING_LEFT);
        std::cout << "3" << std::endl;

    }
    else if(numberCustomer == 3) {
        this->customers.back().sprite.setPosition(1450, 910);   //1100, 700
        this->customers.back().setEndingPosition(sf::Vector2f{1088, 910}, MOVING_LEFT);
        for(int i = 0; i < 2 * INITIAL_MOVES; i++)
            this->customers.back().setPath(MOVING_LEFT);
        std::cout << "2" << std::endl;

    }
    else if(numberCustomer == 4) {
        this->customers.back().sprite.setPosition(1400, 910); //always generated
        this->customers.back().setEndingPosition(sf::Vector2f{1004, 910}, MOVING_LEFT);
        for(int i = 0; i < INITIAL_MOVES; i++)
            this->customers.back().setPath(MOVING_LEFT);
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


    this->customers.back().initSprite();
    std::cout << "set customer" << std::endl;

}

void ReceiveState::addToPath(Move dir) {
    for(auto & it: this->customers)
    {
        it.setPath(dir);
    }
}


