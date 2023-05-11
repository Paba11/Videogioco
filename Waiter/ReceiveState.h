//
// Created by Paolo Sbarzagli on 07/03/23.
//

#ifndef VIDEOGIOCO_RECEIVESTATE_H
#define VIDEOGIOCO_RECEIVESTATE_H

#include "WaiterStates.h"
#include "../Map/Map.h"
#include <cmath>

#define INITIAL_MOVES 70

class ReceiveState : public WaiterStates {
public:
    explicit ReceiveState(const std::shared_ptr<Map>& map);
    ~ReceiveState() override;

    void handleInput(std::shared_ptr<GameCharacter>& gc, sf::Event ev) override;
    void update(std::shared_ptr<GameCharacter>& gc) override;

    //Methods to receive the customer
    Table* pickEmptyTable();
    void setGeneratedCustomers(int numberCustomer, int textureNumber);

    //Move to the table
    void move();
    void addToPath(Move dir);
    static void addToPathSingleCustomer(Move dir, Customer& c);
    void moveToTable();
    void pathToTable();


    //Getters & Setters
    Table* getTable();
    std::vector<Customer>& getCustomers();
    bool checkPos();
    bool getIsSit() const;
    void setAtTable();

private:
    Textures* texture = new Textures();
    std::shared_ptr<Map> map;
    Table* table;
    std::shared_ptr<Customer> customer;
    std::vector<Customer> customers;
    bool isAtTable;
    bool isSit;
};


#endif //VIDEOGIOCO_RECEIVESTATE_H
