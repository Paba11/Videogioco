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
#include "MealMenu.h"

class Order {
public:
    //Constructor & Destructor
    Order();
    explicit Order(Order* o);
    ~Order();


    //Getters & Setters
    std::vector<Apt>& getAppetizers();
    void setAppetizer(int i);
    std::vector<Mn>& getMainCourses();
    void setMainCourse(int i);
    std::vector<Dsr>& getDesserts();
    void setDessert(int i);
    std::vector<Drk>& getDrinks();
    int getTableNumber() const;
    void setTableNumber(int i);
    Current getCurrent();
    void setCurrent(Current c);
    int getPeopleNumber() const;
    void setPeopleNumber(int i);

private:
    int tableNumber;
    int peopleNumber;

    //Attributes that stores the time to complete the preparation of each table course
    std::vector<Apt> appetizers;
    std::vector<Mn> mainCourse;
    std::vector<Dsr> desserts;
    std::vector<Drk> drinks;
    std::unique_ptr<Apt> apt;
    std::unique_ptr<Mn> mn;
    std::unique_ptr<Dsr> dsr;
    std::unique_ptr<Drk> drk;
    Current current;

};



#endif //VIDEOGIOCO_ORDER_H
