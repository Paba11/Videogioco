//
// Created by Paolo Sbarzagli on 23/02/23.
//

#ifndef VIDEOGIOCO_BILL_H
#define VIDEOGIOCO_BILL_H

#include "Map/Table.h"
#include "Dish/Appetizer.h"
#include "Dish/MainCourse.h"
#include "Dish/Dessert.h"

class Bill {
public:
    //Constructor & Destructor
    Bill();
    ~Bill();

    //Set the animations to calculate the bill
    void calculateCorrectTotal();
    bool calculateTotal();
    void update();
    void render();

    //Getters & Setters
    void setAppetizers(Apt apt);
    void setMainDishes(Mn mn);
    void setDesserts(Dsr dsr);
    void setDrinks(Drk drk);
    void setFinishedOrder(std::shared_ptr<Order>& o);


private:
    Table* table;
    std::vector<Apt> appetizers;
    std::vector<Mn> mainDishes;
    std::vector<Dsr> desserts;
    std::vector<Drk> drinks;
    std::unique_ptr<Appetizer> a;
    std::unique_ptr<MainCourse> m;
    std::unique_ptr<Dessert> ds;
    std::vector<std::shared_ptr<Order>> finishedOrders;
    int calculatedTotal;
    int correctTotal;
    bool isCorrect;

};


#endif //VIDEOGIOCO_BILL_H
