//
// Created by Paolo Sbarzagli on 07/02/23.
//

#ifndef VIDEOGIOCO_MAINCOURSE_H
#define VIDEOGIOCO_MAINCOURSE_H

#include "Dish.h"


class MainCourse final : public Dish {
public:
    //Constructor & Destructor
    MainCourse(int Type);
    ~MainCourse();

    //Methods to initialize the texture and the sprite based on the dish type
    void initTexture() override;

private:
    //Method to initialize the preparation time;
    void initPreparationTime() override;

    Mn type;

};


#endif //VIDEOGIOCO_MAINCOURSE_H
