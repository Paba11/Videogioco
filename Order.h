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
#include "Recipe.h"

enum Apt {NACHOS};
enum Mn {HAMBURGER, MEAT, MEATBALLS, CHICKEN};
enum Dsr {CHOCOLATE_CAKE, CHEESE_CAKE, JELLY};
enum Drk {WATER, WINE, BEER, COKE};
enum Current {APPETIZER, MAIN_DISH, DESSERT};

#define MAX_DISHES 4


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
    const int getTavNum();
    Current getCurrent();
    void setCurrent(Current c);

private:
    int tableNumber;

    //Attributes that stores the time to complete the preparation of each table course
    std::vector<Apt> appetizers;
    std::vector<Mn> mainCourse;
    std::vector<Dsr> desserts;
    std::vector<Drk> drinks;
    Current current;

};


#endif //VIDEOGIOCO_ORDER_H
