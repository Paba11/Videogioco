//
// Created by Paolo Sbarzagli on 07/02/23.
//

#ifndef VIDEOGIOCO_DISHWASHER_H
#define VIDEOGIOCO_DISHWASHER_H

#include "GameCharacter.h"
#include "Textures.h"
#include "Kitchen.h"
#include "Washbasin.h"


class DishWasher final : public GameCharacter {
public:
    //Constructor & Destructor
    DishWasher();
    ~DishWasher();

    void update() override;
    void updateWashing();
    void updateAnimations() override;
    void updateVariables();

    //Getters & Setters
    void setWashbasin(Washbasin& washbasin);

private:
    //Methods' override to init the texture and the sprite
    void initTexture() override;
    void initSprite() override;
    Textures* texture = new Textures;
    Washbasin* washbasin;

    unsigned long timer;
    bool isPlates;
    bool isWashing;
};


#endif //VIDEOGIOCO_DISHWASHER_H
