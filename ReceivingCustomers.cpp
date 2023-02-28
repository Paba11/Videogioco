//
// Created by Paolo Sbarzagli on 24/02/23.
//

#include "ReceivingCustomers.h"


ReceivingCustomers::ReceivingCustomers(Map* m) {
    this->map = m;
    this->isClose = false;
}

ReceivingCustomers::~ReceivingCustomers() {

}

bool ReceivingCustomers::receive() {
    this->table = pickEmptyTable();
    //TODO: ISSUE TO THE GAMER THE SELECTED TABLE
    /*
    if(!distanceTable(table))
    {

    }
     */
}

void ReceivingCustomers::setCustomers(std::vector<Customer>& c) {
    while(!c.empty())
    {
        this->customer = &c.back();
        c.pop_back();
        this->customers.push_back(*this->customer);
    }

}


Table *ReceivingCustomers::pickEmptyTable() {
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

std::vector<Customer>& ReceivingCustomers::getCustomers() {
    return this->customers;
}

void ReceivingCustomers::setGeneratedCustomers(int numberCustomer, int textureNumber) {


    if(numberCustomer == 4) {
        this->customers.back().sprite.setPosition(1600, 700);   //1000, 700
        this->customers.back().setEndingPosition(sf::Vector2f{1300, 700}, MOVING_LEFT);

        std::cout << "4" << std::endl;
    }
    else if(numberCustomer == 3) {
        this->customers.back().sprite.setPosition(1600, 800);   //1000, 800
        this->customers.back().setEndingPosition(sf::Vector2f{1300, 800}, MOVING_LEFT);

        std::cout << "3" << std::endl;

    }
    else if(numberCustomer == 2) {
        this->customers.back().sprite.setPosition(1400, 700);   //1100, 700
        this->customers.back().setEndingPosition(sf::Vector2f{1100, 700}, MOVING_LEFT);

        std::cout << "2" << std::endl;

    }
    else if(numberCustomer == 1) {
        this->customers.back().sprite.setPosition(1400, 800); //always generated    //1100, 800
        this->customers.back().setEndingPosition(sf::Vector2f{1100, 800}, MOVING_LEFT);
        std::cout << "1" << std::endl;

    }
    if(textureNumber % 4 == 1)
        this->customers.back().sprite.setTexture(*this->texture->getTexture("Customer1"));
    if(textureNumber % 4 == 2)
        this->customers.back().sprite.setTexture(*this->texture->getTexture("Customer2"));
    if(textureNumber % 4 == 3)
        this->customers.back().sprite.setTexture(*this->texture->getTexture("Customer3"));
    if(textureNumber % 4 == 0)
        this->customers.back().sprite.setTexture(*this->texture->getTexture("Customer4"));


    this->customers.back().setSprite();
    std::cout << "set customer" << std::endl;







}

void ReceivingCustomers::setCustomer(Customer &customer) {
    this->customers;
}

void ReceivingCustomers::enterTheRestaurant() {

    int i=0;
    for(auto it = this->customers.begin(); it != customers.end(); it++){

        if(i == 0)
            it->setEndingPosition(sf::Vector2f{1300, 700}, MOVING_LEFT);
        else if(i == 1)
            it->setEndingPosition(sf::Vector2f{1300, 800}, MOVING_LEFT);
        else if(i == 2)
            it->setEndingPosition(sf::Vector2f{1100, 700}, MOVING_LEFT);
        else
            it->setEndingPosition(sf::Vector2f{1100, 800}, MOVING_LEFT);

        i++;
    }
}















