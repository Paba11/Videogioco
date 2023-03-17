//
// Created by Paolo Sbarzagli on 07/03/23.
//

#ifndef VIDEOGIOCO_RECEIVESTATE_H
#define VIDEOGIOCO_RECEIVESTATE_H

#include "WaiterStates.h"
#include "../Map/Map.h"
#include <cmath>

#define INITIAL_MOVES 70
#define TOTAL_OFFSET 50

class ReceiveState : public WaiterStates {
public:
    ReceiveState(Map* map);
    ~ReceiveState();

    void handleInput(GameCharacter& gc, sf::Event ev) override;
    void update(GameCharacter& gc) override;

    //Methods to receive the customer
    Table* pickEmptyTable();
    void setGeneratedCustomers(int numberCustomer, int textureNumber);

    //Move to the table
    void move();
    void addToPath(Move dir);
    void moveToTable();

    //Getters & Setters
    void setTable(Table* t);
    Table* getTable();
    void setCustomer(Customer* c);
    Customer* getCustomer();
    void setCustomers(Customer& c);
    std::vector<Customer>& getCustomers();

private:
    Textures* texture = new Textures();
    Map* map;
    Table* table;
    Customer* customer;
    std::vector<Customer> customers;

};


#endif //VIDEOGIOCO_RECEIVESTATE_H