//
// Created by Paolo Sbarzagli on 07/02/23.
//

#ifndef VIDEOGIOCO_DESSERT_H
#define VIDEOGIOCO_DESSERT_H


#include "Dish.h"

enum Dsr {CHOCOLATE_CAKE = 1, CHEESE_CAKE, JELLY};

class Dessert final : public Dish {
public:
    //Constructor & Destructor
    Dessert(int type);
    ~Dessert();

    //Methods to initialize the texture and the sprite based on the dish type
    void initTexture();

private:
    //Method to initialize the preparation time;
    void initPreparationTime();

    Dsr type;

};


#endif //VIDEOGIOCO_DESSERT_H
