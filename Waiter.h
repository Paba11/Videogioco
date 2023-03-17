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

#define INTERACT 1

enum class Genre {BOY, GIRL};

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
    std::shared_ptr<ActionsState> getActionState();
    std::shared_ptr<OrderState> getOrderState();
    std::shared_ptr<ReceiveState> getReceiveState();
    void setActionState(std::shared_ptr<ActionsState> as);
    void setOrderState(std::shared_ptr<OrderState> os);
    void setReceiveState(std::shared_ptr<ReceiveState> rs);
    std::shared_ptr<Order> getOrder();
    void setOrder(std::shared_ptr<Order> o);

    void initStates(std::shared_ptr<ActionsState> as, std::shared_ptr<ReceiveState> rs, std::shared_ptr<OrderState> os);

protected:
    //Methods' override to initialize the texture and the sprite
    void initSprite() override;
    void initVariables();

    //Attributes of the waiter
    Genre genre;

    //State pattern
    std::shared_ptr<ActionsState> actionsState;
    std::shared_ptr<OrderState> orderState;
    std::shared_ptr<ReceiveState> receiveState;

    //Attributes to take an order
    std::shared_ptr<Order> order;

    //Attributes to receive the customers
    bool isReceived;
};


#endif //VIDEOGIOCO_WAITER_H
