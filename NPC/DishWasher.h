//
// Created by Paolo Sbarzagli on 07/02/23.
//

#ifndef VIDEOGIOCO_DISHWASHER_H
#define VIDEOGIOCO_DISHWASHER_H

#include "../GameCharacter.h"
#include "../Textures.h"
#include "../Map/Kitchen.h"
#include "../Map/Washbasin.h"


class DishWasher final : public GameCharacter {
public:
    //Constructor & Destructor
    DishWasher();
    ~DishWasher();

    void update() override;
    void updateWashing();
    void updateAnimations() override;
    void setAnimation();
    void updateVariables();
    void move();

    //Getters & Setters
    void setWashbasin(Washbasin& washbasin);
    Washbasin* getWashbasin();

private:
    //Methods' override to init the texture and the sprite
    void initTexture() override;
    void initSprite() override;
    Textures* texture = new Textures;

    sf::Time time;
    sf::Clock clock;
    Washbasin* washbasin;
    float timer;
    bool isWashing;
    int numPlates;
};


#endif //VIDEOGIOCO_DISHWASHER_H
