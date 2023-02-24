//
// Created by Paolo Sbarzagli on 23/02/23.
//

#ifndef VIDEOGIOCO_BILL_H
#define VIDEOGIOCO_BILL_H

#include "Table.h"
#include "Drink.h"
#include "Appetizer.h"
#include "MainCourse.h"
#include "Dessert.h"

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


private:
    Table* table;
    std::vector<Apt> appetizers;
    std::vector<Mn> mainDishes;
    std::vector<Dsr> desserts;
    std::vector<Drk> drinks;
    Drink* d;
    Appetizer* a;
    MainCourse* m;
    Dessert* ds;
    int calculatedTotal;
    int correctTotal;
    bool isCorrect;

};


#endif //VIDEOGIOCO_BILL_H
