//
// Created by Paolo Sbarzagli on 07/02/23.
//

#ifndef VIDEOGIOCO_MAINCOURSE_H
#define VIDEOGIOCO_MAINCOURSE_H

#include "Dish.h"
#include "MealMenu.h"

class MainCourse final : public Dish {
public:
    //Constructor & Destructor
    MainCourse(Mn t);
    ~MainCourse();

    //Methods to initialize the texture and the sprite based on the dish type
    void setTexture();

    //Calculate the correct price & preparation time
    void calculatePrice() override;
    void calculateTime() override;


private:
    //Method to initialize the preparation time;
    void initPreparationTime() override;

    Mn type;
    int price;

};


#endif //VIDEOGIOCO_MAINCOURSE_H
