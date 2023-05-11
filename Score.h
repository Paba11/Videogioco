//
// Created by Paolo Sbarzagli on 23/02/23.
//

#ifndef VIDEOGIOCO_SCORE_H
#define VIDEOGIOCO_SCORE_H

#include "Map/Table.h"
#include "Dish/Appetizer.h"
#include "Dish/MainCourse.h"
#include "Dish/Dessert.h"

class Score {
public:
    //Constructor & Destructor
    Score();
    ~Score();

    //Set the animations to calculate the bill
    void update();
    void render();

    //Getters & Setters
    void addPoints(int i);
    void setTable(Table* t);
    void addNotSatisfied();
    [[nodiscard]] bool getQuit() const;
    [[nodiscard]] int getTotalPoints() const;

private:
    std::vector<Table*> table;
    int totalPoints;

    int notSatisfiedTables;
    bool quit;
};


#endif //VIDEOGIOCO_SCORE_H
