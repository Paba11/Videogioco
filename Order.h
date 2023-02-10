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
#include "Recipe.h"


class Order {
public:
    //Constructor & Destructor
    Order();
    ~Order();

    //Getters & Setters
    Apt getAppetizers(int i);
    Mn getMainCourse(int i);
    Dsr getDesserts(int i);
    Drk getDrinks(int i);

private:
    Table* table;

    //Attributes that stores the time to complete the preparation of each table course
    Apt appetizers[MAX_DISHES];
    Mn mainCourse[MAX_DISHES];
    Dsr desserts[MAX_DISHES];
    Drk drinks[MAX_DISHES];

};


#endif //VIDEOGIOCO_ORDER_H
