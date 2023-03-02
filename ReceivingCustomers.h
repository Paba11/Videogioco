//
// Created by Paolo Sbarzagli on 24/02/23.
//

#ifndef VIDEOGIOCO_RECEIVINGCUSTOMERS_H
#define VIDEOGIOCO_RECEIVINGCUSTOMERS_H

#include "Map.h"
#include "WaiterStates.h"
#include "Customer.h"
#include "Textures.h"
#include "FollowMovement.h"

#define DISTANCE 4;
#define MOVEMENT 0.1;

class ReceivingCustomers {
public:
    ReceivingCustomers(Map* map);
    ~ReceivingCustomers();

    //Methods to receive the customer
    Table* pickEmptyTable();
    void setGeneratedCustomers(int numberCustomer, int textureNumber);
    void enterTheRestaurant();
    Move checkState(float distX, float distY);
    void update();

    bool receive();
    void collisionManagement();
    void moveToChair(std::queue<FollowMovement>& movement);
    void move(FollowMovement customerMovement);
    void follow(sf::Vector2f prePosition, sf::Vector2f finalPosition, Move status);

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
