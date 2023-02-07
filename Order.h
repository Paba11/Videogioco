//
// Created by Paolo Sbarzagli on 02/02/23.
//

#ifndef VIDEOGIOCO_ORDER_H
#define VIDEOGIOCO_ORDER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Dish.h"
#include "Order.h"
#include "Table.h"

class Order {
public:
    //Constructor & Destructor
    Order();
    ~Order();

    //Getters & Setters
    int getAppetizerTime();
    void setAppetizerTime()

private:
    Table* table;

    //Attributes that stores the time to complete the preparation of each table course
    int appetizerTime;
    int mainCourseTime;
    int dessertTime;

};


#endif //VIDEOGIOCO_ORDER_H
