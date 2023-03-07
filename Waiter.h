//
// Created by Paolo Sbarzagli on 31/01/23.
//

#ifndef VIDEOGIOCO_WAITER_H
#define VIDEOGIOCO_WAITER_H

#include "Dish.h"
#include "GameCharacter.h"
#include "Order.h"
#include "Map.h"
#include "Textures.h"
#include "WaiterStates.h"
#include "OrderState.h"
#include "ActionState.h"
#include "ReceiveState.h"
#include "ReceivingCustomers.h"
#include "FollowMovement.h"
#include <cmath>

#define INTERACT 1;


class Waiter final : public GameCharacter {
public:
    //Constructor & Destructor
    Waiter();
    ~Waiter() override;

    //Method to move, update and render the waiter
    void updateMovement();
    void update() override;
    void updateAnimations() override;
    Textures* texture = new Textures;
    void move();
    void setAnimation();

    //Methods to interact with the customer
    void interact(Map* map, sf::Event ev);
    void interactionManagement();
    void pickUp(Kitchen* kitchen);
    void pickUp(Table* table);
    void putDown(Table* table);
    void putDown(Washbasin* washbasin);
    void takingOrder(Table* table);
    void leavingOrder(Kitchen* kitchen);
    void receivedCustomers();


    //Getters & Setters
    Move getMove();
    //OrderState* getOrderState();
    //void setOrderState(OrderState* o);
    void setReceivingCustomers(ReceivingCustomers* rc);
    bool getIsReceived();
    void initTexture(sf::Texture* textureW);

    ActionsState* getActionState();
    OrderState* getOrderState();
    ReceiveState* getReceiveState();

    void initStates(Map* map);

protected:
    //Methods' override to initialize the texture and the sprite
    void initSprite() override;
    void initVariables();

    //Attributes of the waiter
    int ability;
    Genre genre;

    //State pattern
    ActionsState* actionsState;
    OrderState* orderState;
    ReceiveState* receiveState;

    //Attributes to take an order
    Order* order;

    //Attributes to receive the customers
    Table* targetTable;
    Customer* targetCustomer;
    ReceivingCustomers* receivingCustomers;
    std::queue<FollowMovement> direction;
    bool isReceived;
};


#endif //VIDEOGIOCO_WAITER_H
