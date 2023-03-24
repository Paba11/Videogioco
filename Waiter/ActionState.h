//
// Created by Paolo Sbarzagli on 07/03/23.
//

#ifndef VIDEOGIOCO_ACTIONSTATE_H
#define VIDEOGIOCO_ACTIONSTATE_H

#include "WaiterStates.h"
#include "../GameCharacter.h"
#include "../Map/Map.h"

#include <cmath>

class ActionsState final : public WaiterStates {
public:
    explicit ActionsState(const std::shared_ptr<Map>& map);
    ~ActionsState();

    void handleInput(GameCharacter* waiter, sf::Event ev) override;
    void update(GameCharacter* waiter) override;
    void actionManagement();

    //Methods to interact
    void pickUp(std::shared_ptr<Kitchen>& kitchen);
    void pickUp(Table* table);
    void putDown(Table* table);
    void putDown(std::shared_ptr<Washbasin>& washbasin);
    void leavingOrder(std::shared_ptr<Kitchen>& kitchen);

    //Getters & setters
    Tray* getTray();
    void setTray(const std::shared_ptr<Tray>& t);
    void setIsOrder(bool t);
    bool getIsOrder();
    void setOrder(std::shared_ptr<Order>& o);

private:
    std::shared_ptr<GameCharacter> waiter;
    std::shared_ptr<Map> map;
    std::shared_ptr<Order> order;
    bool isOrder;
    sf::Event event;

    //Pointer to the plates carrying in a specific moment
    std::shared_ptr<Tray> tray;
};

#endif //VIDEOGIOCO_ACTIONSTATE_H
