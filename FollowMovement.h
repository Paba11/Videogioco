//
// Created by Paolo Sbarzagli on 28/02/23.
//

#ifndef VIDEOGIOCO_FOLLOWMOVEMENT_H
#define VIDEOGIOCO_FOLLOWMOVEMENT_H

#include "WaiterStates.h"
#include "GameCharacter.h"

class FollowMovement {
public:
    FollowMovement();
    ~FollowMovement();

    void initDistance();
    float distanceTwoCharacters(GameCharacter* g1, GameCharacter* g2);

private:
    int dist;
    Direction direction;

};


#endif //VIDEOGIOCO_FOLLOWMOVEMENT_H
