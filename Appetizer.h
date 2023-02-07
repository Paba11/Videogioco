//
// Created by Paolo Sbarzagli on 07/02/23.
//

#ifndef VIDEOGIOCO_APPETIZER_H
#define VIDEOGIOCO_APPETIZER_H

#include "Dish.h"



class Appetizer final : public Dish {
public:
    //Constructor & Destructor
    Appetizer(int type);
    ~Appetizer();

    //Methods to initialize the texture and the sprite based on the dish type
    void initTexture() override;

private:
    Apt type;

    //Method to initialize the preparation time;
    void initPreparationTime() override;



};


#endif //VIDEOGIOCO_APPETIZER_H
