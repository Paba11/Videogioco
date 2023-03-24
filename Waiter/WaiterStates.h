//
// Created by Paolo Sbarzagli on 24/02/23.
//

#ifndef VIDEOGIOCO_WAITERSTATES_H
#define VIDEOGIOCO_WAITERSTATES_H

#include "../GameCharacter.h"
//TODO:: CHANGE THE GAME CHARACTER IN A SHARED POINTER

class WaiterStates {
public:
    WaiterStates();
    ~WaiterStates();

    virtual void handleInput(GameCharacter* gc, sf::Event ev) = 0;
    virtual void update(GameCharacter* gc) = 0;
};

#endif //VIDEOGIOCO_WAITERSTATES_H
