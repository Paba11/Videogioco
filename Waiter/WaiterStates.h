//
// Created by Paolo Sbarzagli on 24/02/23.
//

#ifndef VIDEOGIOCO_WAITERSTATES_H
#define VIDEOGIOCO_WAITERSTATES_H

#include "../GameCharacter.h"

class WaiterStates {
public:
    WaiterStates();
    virtual ~WaiterStates();

    virtual void handleInput(std::shared_ptr<GameCharacter>& gc, sf::Event ev) = 0;
    virtual void update(std::shared_ptr<GameCharacter>& gc) = 0;
};

#endif //VIDEOGIOCO_WAITERSTATES_H
