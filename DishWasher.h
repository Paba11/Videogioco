//
// Created by Paolo Sbarzagli on 07/02/23.
//

#ifndef VIDEOGIOCO_DISHWASHER_H
#define VIDEOGIOCO_DISHWASHER_H

#include "GameCharacter.h"

class DishWasher final : public GameCharacter {
public:
    DishWasher();
    ~DishWasher();

private:
    //Methods' override to init the texture and the sprite
    void initTexture() override;
    void initSprite() override;

};


#endif //VIDEOGIOCO_DISHWASHER_H
