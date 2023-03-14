//
// Created by Paolo Sbarzagli on 07/03/23.
//

#ifndef VIDEOGIOCO_ACTIONSTATE_H
#define VIDEOGIOCO_ACTIONSTATE_H

#include "WaiterStates.h"
#include "GameCharacter.h"
#include "Map.h"

#include <cmath>

class ActionsState final : public WaiterStates {
public:
    ActionsState(Map* map);
    ~ActionsState();

    void handleInput(GameCharacter& waiter, sf::Event ev) override;
    void update(GameCharacter& waiter) override;
    void actionManagement();

    //Methods to interact
    void pickUp(Kitchen* kitchen);
    void pickUp(Table* table);
    void putDown(Table* table);
    void putDown(Washbasin* washbasin);
    void leavingOrder(Kitchen* kitchen);

    //Getters & setters
    Tray* getTray();
    void setIsOrder(bool t);
    bool getIsOrder();

private:
    GameCharacter* waiter;
    Map* map;
    Order* order;
    bool isOrder;
    sf::Event event;

    //Pointer to the plates carrying in a specific moment
    Tray* tray;
};

#endif //VIDEOGIOCO_ACTIONSTATE_H
