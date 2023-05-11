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
    explicit Dessert(Dsr d);
    ~Dessert() override;

    //Methods to initialize the texture and the sprite based on the dish type
    void setTexture() override;

    //Calculate the correct price & preparation time
    void calculateTime() override;

private:
    //Method to initialize the preparation time;

    Dsr type;

};


#endif //VIDEOGIOCO_DESSERT_H
