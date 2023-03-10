//
// Created by Paolo Sbarzagli on 07/02/23.
//

#ifndef VIDEOGIOCO_DESSERT_H
#define VIDEOGIOCO_DESSERT_H


#include "Dish.h"
#include "MealMenu.h"

class Dessert final : public Dish {
public:
    //Constructor & Destructor
    Dessert(Dsr d);
    ~Dessert();

    //Methods to initialize the texture and the sprite based on the dish type
    void initTexture();

    //Calculate the correct price
    void calculatePrice();

    //Getters & Setters
    int getPrice();

private:
    //Method to initialize the preparation time;
    void initPreparationTime();

    Dsr type;
    int price;

};


#endif //VIDEOGIOCO_DESSERT_H
