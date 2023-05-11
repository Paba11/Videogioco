//
// Created by Paolo Sbarzagli on 07/02/23.
//

#ifndef VIDEOGIOCO_APPETIZER_H
#define VIDEOGIOCO_APPETIZER_H

#include "Dish.h"
#include "MealMenu.h"

class Appetizer final : public Dish {
public:
    //Constructor & Destructor
    explicit Appetizer(Apt type);
    ~Appetizer() override;


    //Calculate the correct price & preparation time
    void calculateTime() override;

private:
    Apt type;

    //Method to initialize the preparation time;
    void setTexture() override;
};


#endif //VIDEOGIOCO_APPETIZER_H
