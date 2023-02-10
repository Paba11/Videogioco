//
// Created by Paolo Sbarzagli on 07/02/23.
//

#ifndef VIDEOGIOCO_MAINCOURSE_H
#define VIDEOGIOCO_MAINCOURSE_H

#include "Dish.h"

enum Mn {HAMBURGER = 1, MEAT, MEATBALLS, CHICKEN};

class MainCourse final : public Dish {
public:
    //Constructor & Destructor
    MainCourse(int Type);
    ~MainCourse();

    //Methods to initialize the texture and the sprite based on the dish type
    void initTexture();

private:
    //Method to initialize the preparation time;
    void initPreparationTime();

    Mn type;

};


#endif //VIDEOGIOCO_MAINCOURSE_H
