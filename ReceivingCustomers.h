//
// Created by Paolo Sbarzagli on 24/02/23.
//

#ifndef VIDEOGIOCO_RECEIVINGCUSTOMERS_H
#define VIDEOGIOCO_RECEIVINGCUSTOMERS_H

#include "Map.h"
#include "WaiterStates.h"
#include "Customer.h"
#include "Textures.h"

class ReceivingCustomers {
public:
    ReceivingCustomers(Map* map);
    ~ReceivingCustomers();

    //
    Table* pickEmptyTable();
    void setGeneratedCustomers(int numberCustomer, int textureNumber);
    void enterTheRestaurant();

    bool receive();

    //Getters & Setters
    void setCustomers(std::vector<Customer>& customers);
    void setCustomer(Customer& customer);
    std::vector<Customer>& getCustomers();




private:
    Textures* texture = new Textures();
    Map* map;
    Table* table;
    Customer* customer;
    std::vector<Customer> customers;
    bool isClose;


};


#endif //VIDEOGIOCO_RECEIVINGCUSTOMERS_H