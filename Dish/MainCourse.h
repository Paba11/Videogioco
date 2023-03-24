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
    void initTexture();

    //Calculate the correct price & preparation time
    void calculatePrice();
    void calculateTime() override;

    //Getters & Setters
    int getPrice();

private:
    //Method to initialize the preparation time;
    void initPreparationTime();

    Mn type;
    int price;

};


#endif //VIDEOGIOCO_MAINCOURSE_H
