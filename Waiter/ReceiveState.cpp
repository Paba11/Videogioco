//
// Created by Paolo Sbarzagli on 07/03/23.
//

#include "ReceiveState.h"

ReceiveState::ReceiveState(const std::shared_ptr<Map>& m) {
    map.reset();
    map = m;
}

ReceiveState::~ReceiveState() {

}

void ReceiveState::handleInput(GameCharacter* gc, sf::Event ev) {
    table = pickEmptyTable();
    update(gc);
}

void ReceiveState::update(GameCharacter* gc) {
    move();
}


Table* ReceiveState::pickEmptyTable() {
    std::vector<Table> t;
    bool notFound = true;

    while(!map->getAllTables().empty() && notFound)
    {
        t.push_back(map->getAllTables().back());
        map->getAllTables().pop_back();
        if(!t.back().getIsOccupied())
        {
            notFound = false;
            table = &t.back();
            table->setIsOccupied(true);
            table->setChosenTable();
            while(!t.empty())
            {
                map->getAllTables().push_back(t.back());
                t.pop_back();
            }
        }
    }
    return table;
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
    table = t;
}

Table *ReceiveState::getTable() {
    return table;
}

void ReceiveState::setCustomer(const std::shared_ptr<Customer>& c) {
    customer.reset();
    customer = c;
}

const std::shared_ptr<Customer>& ReceiveState::getCustomer() {
    return customer;
}

void ReceiveState::setCustomers(Customer& c) {
    customers.push_back(c);
}

std::vector<Customer> &ReceiveState::getCustomers() {
    return customers;
}

void ReceiveState::setGeneratedCustomers(int numberCustomer, int textureNumber) {
    if(numberCustomer == 1) {
        customers.back().sprite.setPosition(1550, 910);   //1000, 700
        customers.back().setEndingPosition(sf::Vector2f{1256, 910}, Move::MOVING_LEFT);
        for(int i = 0; i < 4 * INITIAL_MOVES; i++)
            customers.back().setPath(Move::MOVING_LEFT);
        std::cout << "4" << std::endl;
    }
    else if(numberCustomer == 2) {
        customers.back().sprite.setPosition(1500, 910);   //1000, 800
        customers.back().setEndingPosition(sf::Vector2f{1172, 910}, Move::MOVING_LEFT);
        for(int i = 0; i < 3 * INITIAL_MOVES; i++)
            customers.back().setPath(Move::MOVING_LEFT);
        std::cout << "3" << std::endl;

    }
    else if(numberCustomer == 3) {
        customers.back().sprite.setPosition(1450, 910);   //1100, 700
        customers.back().setEndingPosition(sf::Vector2f{1088, 910}, Move::MOVING_LEFT);
        for(int i = 0; i < 2 * INITIAL_MOVES; i++)
            customers.back().setPath(Move::MOVING_LEFT);
        std::cout << "2" << std::endl;

    }
    else if(numberCustomer == 4) {
        customers.back().sprite.setPosition(1400, 910); //always generated
        customers.back().setEndingPosition(sf::Vector2f{1004, 910}, Move::MOVING_LEFT);
        for(int i = 0; i < INITIAL_MOVES; i++)
            customers.back().setPath(Move::MOVING_LEFT);
        std::cout << "1" << std::endl;

    }
    if(textureNumber-1 % 4 == 0)
        customers.back().sprite.setTexture(*texture->getTexture("Customer1"));
    if(textureNumber-1 % 4 == 1)
        customers.back().sprite.setTexture(*texture->getTexture("Customer2"));
    if(textureNumber-1 % 4 == 2)
        customers.back().sprite.setTexture(*texture->getTexture("Customer3"));
    if(textureNumber-1 % 4 == 3)
        customers.back().sprite.setTexture(*texture->getTexture("Customer4"));


    customers.back().initSprite();
    std::cout << "set customer" << std::endl;

}

void ReceiveState::addToPath(Move dir) {
    for(auto & it: customers)
    {
        it.setPath(dir);
    }
}

void ReceiveState::moveToTable() {
    int i = 0;
    for(auto & it: customers)
    {
        it.setEndingPosition(table->getStoolTable()[i].sprite.getPosition());
        i++;
    }
}


