//
// Created by Paolo Sbarzagli on 07/02/23.
//

#ifndef VIDEOGIOCO_DRINK_H
#define VIDEOGIOCO_DRINK_H

#include "Dish.h"
#include "MealMenu.h"

class Drink final : public Dish {
public:
    //Constructor & Destructor
    Drink(Drk d);
    ~Drink();

    //Methods to initialize the texture and the sprite based on the dish type
    void initTexture();

    //Calculate price
    void calculatePrice();

    //Getters & Setters
    int getPrice();

private:

    Drk type;
    int price;

};


#endif //VIDEOGIOCO_DRINK_H
