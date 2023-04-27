//
// Created by Paolo Sbarzagli on 07/03/23.
//

#include "ReceiveState.h"

ReceiveState::ReceiveState(const std::shared_ptr<Map>& m) {
    map.reset();
    map = m;
    isAtTable = false;
    isSit = false;
}

ReceiveState::~ReceiveState() {
}

void ReceiveState::handleInput(std::shared_ptr<GameCharacter>& gc, sf::Event ev) {
    if(!isAtTable)
        table = pickEmptyTable();
    else
        pathToTable();

    update(gc);
}

void ReceiveState::update(std::shared_ptr<GameCharacter>& gc) {
    if(!isAtTable)
        move();
    else
        moveToTable();
}


Table* ReceiveState::pickEmptyTable() {
    bool notFound = true;

    for(auto & it: map->getAllTables())
    {
        //std::cout << "Table num: " << it.getTavNum() << std::endl;
        if(!it.getIsOccupied() && notFound)
        {
            notFound = false;
            table = &it;
            table->setIsOccupied(true);
            table->setChosenTable(true);
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
    /*
    if(textureNumber-1 % 4 == 0)
        customers.back().sprite.setTexture(*texture->getTexture("Customer1"));
    if(textureNumber-1 % 4 == 1)
        customers.back().sprite.setTexture(*texture->getTexture("Customer2"));
    if(textureNumber-1 % 4 == 2)
        customers.back().sprite.setTexture(*texture->getTexture("Customer3"));
    if(textureNumber-1 % 4 == 3)
        customers.back().sprite.setTexture(*texture->getTexture("Customer4"));
        */
    if( (textureNumber-1) % 4 == 0) {
        customers.back().initTexture("Customer1");
        std::cout << "Set Texture 1" << std::endl;
    }
    if( (textureNumber-1) % 4 == 1) {
        customers.back().initTexture("Customer2");
        std::cout << "Set Texture 2" << std::endl;
    }
    if( (textureNumber-1) % 4 == 2) {
        customers.back().initTexture("Customer3");
        std::cout << "Set Texture 3" << std::endl;
    }
    if( (textureNumber-1) % 4 == 3) {
        customers.back().initTexture("Customer4");
        std::cout << "Set Texture 4" << std::endl;
    }


    customers.back().initSprite();
    std::cout << "set customer" << std::endl;

}

void ReceiveState::addToPath(Move dir) {
    if(!isAtTable)
    {
        for(auto & it: customers)
        {
         it.setPath(dir);
        }
    }
}

void ReceiveState::moveToTable() {
    int count = 0;
    for(auto & it: this->customers)
    {
        if(!it.getPath().empty() && it.getPath().front() != Move::STANDING)
        {
            //std::cout << "Move customer " << std::endl;
            it.setMovingStatus(it.getPath().front());
            it.getPath().pop();
            it.move();
        }
        else if(it.getPath().front() == Move::STANDING)
        {
            it.getSprite().setPosition(map->getEntrance()->getWelcomeSquare().getPosition());
            it.getPath().pop();
        }
        else if(it.getPath().empty())
            count += 1;

        if(count == customers.size())
        {
            table->setCustomers(customers);
            isSit = true;
            table->setIsSit(true);
            map->getEntrance()->setIsCustomer(false);

        }
    }
}

void ReceiveState::addToPathSingleCustomer(Move dir, Customer& c) {
    c.setPath(dir);
}

void ReceiveState::setIsAtTable(bool t) {
    isAtTable = t;
}

bool ReceiveState::getIsAtTable() {
    return isAtTable;
}

void ReceiveState::pathToTable() {
    int i = 0;
    for(auto & it: customers)                       //Set the path to the right amount of moves
    {
       // addToPathSingleCustomer(Move::STANDING, it);
        //it.setBlock(true);
        //std::cout << "path to table" << std::endl;
        if(i == 0)
        {
            for(int m = 0; m < 70; m++)
                addToPathSingleCustomer(Move::MOVING_LEFT, it);
            for(int m = 0; m < 100; m++)
                addToPathSingleCustomer(Move::MOVING_DOWN, it);
        }
        else if(i == 1)
        {
            for(int m = 0; m < 70; m++)
                addToPathSingleCustomer(Move::MOVING_RIGHT, it);
            for(int m = 0; m < 100; m++)
                addToPathSingleCustomer(Move::MOVING_DOWN, it);
        }
        else if(i == 2)
        {
            for(int m = 0; m < 70; m++)
                addToPathSingleCustomer(Move::MOVING_LEFT, it);
            for(int m = 0; m < 50; m++)
                addToPathSingleCustomer(Move::MOVING_DOWN, it);
        }
        else if(i == 3)
        {
            for (int m = 0; m < 70; m++)
                addToPathSingleCustomer(Move::MOVING_RIGHT, it);
            for (int m = 0; m < 50; m++)
                addToPathSingleCustomer(Move::MOVING_DOWN, it);
        }
        i++;
    }
}

bool ReceiveState::checkPos() {
    bool pos = false;
    if(!customers.front().isMoving())
        pos = true;
    return pos;
}

void ReceiveState::setAtTable() {
    isAtTable = true;
    table->setIsOccupied(true);
    table->setChosenTable(false);
    table->restartTimer();
}

bool ReceiveState::getIsSit() {
    return isSit;
}


