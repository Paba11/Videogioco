//
// Created by Paolo Sbarzagli on 07/03/23.
//

#ifndef VIDEOGIOCO_RECEIVESTATE_H
#define VIDEOGIOCO_RECEIVESTATE_H

#include "WaiterStates.h"
#include "Map.h"

class ReceiveState : public WaiterStates {
public:
    ReceiveState(Map* map);
    ~ReceiveState();

    void handleInput(GameCharacter& gc, sf::Event ev) override;
    void update(GameCharacter& gc) override;

    //Methods to receive the customer
    Table* pickEmptyTable();
    Move checkState(float distX, float distY);
    void update();

    //Move to the table
    void move(FollowMovement customerMovement);
    void follow(sf::Vector2f prePosition, sf::Vector2f finalPosition, Move status);

private:
    Map* map;
    Table* table;
};


#endif //VIDEOGIOCO_RECEIVESTATE_H
