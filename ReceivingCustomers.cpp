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

void ReceivingCustomers::generateCustomers() {

}

void ReceivingCustomers::setCustomer(Customer &customer) {
    this->customers;
}

