//
// Created by Paolo Sbarzagli on 07/02/23.
//

#ifndef VIDEOGIOCO_DESSERT_H
#define VIDEOGIOCO_DESSERT_H

#include "Dish.h"


class Dessert final : public Dish {
public:
    //Constructor & Destructor
    Dessert(int type);
    ~Dessert();

    //Methods to initialize the texture and the sprite based on the dish type
    void initTexture() override;

private:
    //Method to initialize the preparation time;
    void initPreparationTime() override;

    Dsr type;

};


#endif //VIDEOGIOCO_DESSERT_H
