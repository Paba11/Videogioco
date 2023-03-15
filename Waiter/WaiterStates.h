//
// Created by Paolo Sbarzagli on 24/02/23.
//

#ifndef VIDEOGIOCO_WAITERSTATES_H
#define VIDEOGIOCO_WAITERSTATES_H

#include "../GameCharacter.h"

enum Genre {BOY, GIRL};

class WaiterStates {
public:
    WaiterStates();
    ~WaiterStates();

    virtual void handleInput(GameCharacter& gc, sf::Event ev);
    virtual void update(GameCharacter& gc);
};

#endif //VIDEOGIOCO_WAITERSTATES_H
