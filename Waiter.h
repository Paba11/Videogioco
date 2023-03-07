//
// Created by Paolo Sbarzagli on 31/01/23.
//

#ifndef VIDEOGIOCO_WAITER_H
#define VIDEOGIOCO_WAITER_H

#include "Dish.h"
#include "GameCharacter.h"
#include "Order.h"
#include "Tray.h"
#include "Map.h"
#include "Textures.h"
#include "OrderState.h"
#include "WaiterStates.h"
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
    Actions getState();
    Move getMove();
    OrderState* getOrderState();
    void setOrderState(OrderState* o);
    void setReceivingCustomers(ReceivingCustomers* rc);
    bool getIsReceived();
    void initTexture(sf::Texture* textureW);


protected:
    //Methods' override to initialize the texture and the sprite
    void initSprite() override;

    //Attributes of the waiter

    int ability;
    Genre genre;

    Actions state;

    //Attributes to take an order
    Order* order;
    OrderState* orderState;

    //Pointer to the plates carrying in a specific moment
    Tray* tray;

    //Attributes to receive the customers
    Table* targetTable;
    Customer* targetCustomer;
    ReceivingCustomers* receivingCustomers;
    std::queue<FollowMovement> direction;
    bool isReceived;
};


#endif //VIDEOGIOCO_WAITER_H
