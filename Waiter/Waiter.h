//
// Created by Paolo Sbarzagli on 31/01/23.
//

#ifndef VIDEOGIOCO_WAITER_H
#define VIDEOGIOCO_WAITER_H

#include "../Score.h"
#include "../Dish/Dish.h"
#include "../GameCharacter.h"
#include "../Dish/Order.h"
#include "../Map/Map.h"
#include "../Textures.h"
#include "WaiterStates.h"
#include "OrderState.h"
#include "ActionState.h"
#include "ReceiveState.h"
#include <cmath>


class Waiter final : public GameCharacter {
public:
    //Constructor & Destructor
    Waiter();
    ~Waiter() override;

    //Method to move, update and render the waiter
    void updateMovement();
    void update() override;
    void updateState();
    void updateAnimations() override;
    void move();
    void setAnimation();

    //Methods to interact with the customer
    void interact(const std::shared_ptr<Map>& map, sf::Event ev);
    void checkReceiving();
    void leaveAtTable();
    void setOrder(const std::shared_ptr<Map>& map, Table* t);
    void setReceive(const std::shared_ptr<Map>& map, sf::Event ev);

    //Getters & Setters
    Move getMove();
    bool getIsReceived() const;
    void initTexture(sf::Texture* textureW);
    std::shared_ptr<ActionsState> getActionState();
    void setActionState(const std::shared_ptr<ActionsState>& as);
    void setReceiveState(const std::shared_ptr<ReceiveState>& rs);
    std::shared_ptr<Order>& getOrder();
    void setOrder(Order* o);
    bool getHasOrder() const;

    void initStates(const std::shared_ptr<ActionsState>& as, const std::shared_ptr<ReceiveState>& rs, const std::shared_ptr<OrderState>& os);

    sf::Clock receivingTimer;

protected:
    //Methods' override to initialize the texture and the sprite
    void initSprite() override;
    void initVariables();

    //Attributes of the waiter
    std::shared_ptr<GameCharacter> gc;

    //State pattern
    std::shared_ptr<ActionsState> actionsState;
    std::shared_ptr<OrderState> orderState;
    std::shared_ptr<ReceiveState> receiveState;

    //Attributes to take an order
    std::shared_ptr<Order> order;
    bool hasOrder;

    //Attributes to receive the customers
    bool isReceived;
};


#endif //VIDEOGIOCO_WAITER_H
