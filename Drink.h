//
// Created by Paolo Sbarzagli on 07/02/23.
//

#ifndef VIDEOGIOCO_DRINK_H
#define VIDEOGIOCO_DRINK_H

#include "Dish.h"

enum Drk {WATER = 1, WINE, BEER, COKE};

class Drink final : public Dish {
public:
    //Constructor & Destructor
    Drink(int type);
    ~Drink();

    //Methods to initialize the texture and the sprite based on the dish type
    void initTexture();

private:

    Drk type;

};


#endif //VIDEOGIOCO_DRINK_H
