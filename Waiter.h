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
    void checkReceiving();

    //Getters & Setters
    Move getMove();
    bool getIsReceived();
    void initTexture(sf::Texture* textureW);
    ActionsState* getActionState();
    OrderState* getOrderState();
    ReceiveState* getReceiveState();
    void setActionState(ActionsState* as);
    void setOrderState(OrderState* os);
    void setReceiveState(ReceiveState* rs);
    Order* getOrder();
    void setOrder(Order* o);

    void initStates(ActionsState* as, ReceiveState* rs, OrderState* os);

protected:
    //Methods' override to initialize the texture and the sprite
    void initSprite() override;
    void initVariables();

    //Attributes of the waiter
    Genre genre;

    //State pattern
    ActionsState* actionsState;
    OrderState* orderState;
    ReceiveState* receiveState;

    //Attributes to take an order
    Order* order;

    //Attributes to receive the customers
    bool isReceived;
};


#endif //VIDEOGIOCO_WAITER_H
