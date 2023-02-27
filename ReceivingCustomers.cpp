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
        this->customers.back().sprite.setPosition(1000, 700);
        std::cout << "4" << std::endl;
    }
    else if(numberCustomer == 3) {
        this->customers.back().sprite.setPosition(1000, 800);
        std::cout << "3" << std::endl;

    }
    else if(numberCustomer == 2) {
        this->customers.back().sprite.setPosition(1100, 700);
        std::cout << "2" << std::endl;

    }
    else if(numberCustomer == 1) {
        this->customers.back().sprite.setPosition(1100, 800);
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















