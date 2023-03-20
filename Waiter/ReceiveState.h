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
    ReceiveState(const std::shared_ptr<Map>& map);
    ~ReceiveState();

    void handleInput(GameCharacter* gc, sf::Event ev) override;
    void update(GameCharacter* gc) override;

    //Methods to receive the customer
    Table* pickEmptyTable();
    void setGeneratedCustomers(int numberCustomer, int textureNumber);

    //Move to the table
    void move();
    void addToPath(Move dir);
    void addToPathSingleCustomer(Move dir, Customer& c);
    void moveToTable();
    void pathToTable();

    //Getters & Setters
    void setTable(Table* t);
    Table* getTable();
    void setCustomer(const std::shared_ptr<Customer>& c);
    const std::shared_ptr<Customer>& getCustomer();
    void setCustomers(Customer& c);
    std::vector<Customer>& getCustomers();
    void setIsAtTable(bool t);
    bool getIsAtTable();
    bool checkPos();

private:
    Textures* texture = new Textures();
    std::shared_ptr<Map> map;
    Table* table;
    std::shared_ptr<Customer> customer;
    std::vector<Customer> customers;
    bool isAtTable;

};


#endif //VIDEOGIOCO_RECEIVESTATE_H
