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
#include "Recipe.h"
#include "MealMenu.h"


class Order {
public:
    //Constructor & Destructor
    Order();
    ~Order();

    void initPointersToNull();

    //Getters & Setters
    Apt getAppetizer(int i);
    std::vector<Apt>& getAppetizers();
    void setAppetizer(int i);
    Mn getMainCourse(int i);
    std::vector<Mn>& getMainCourses();
    void setMainCourse(int i);
    Dsr getDessert(int i);
    std::vector<Dsr>& getDesserts();
    void setDessert(int i);
    Drk getDrink(int i);
    std::vector<Drk>& getDrinks();
    void setDrink(int i);
    const int getTableNumber();
    void setTableNumber(int i);
    Current getCurrent();
    void setCurrent(Current c);


private:
    int tableNumber;

    //Attributes that stores the time to complete the preparation of each table course
    std::vector<Apt> appetizers;
    std::vector<Mn> mainCourse;
    std::vector<Dsr> desserts;
    std::vector<Drk> drinks;
    Apt* apt;
    Mn* mn;
    Dsr* dsr;
    Drk* drk;
    Current current;

};



#endif //VIDEOGIOCO_ORDER_H
