//
// Created by Paolo Sbarzagli on 23/02/23.
//

#ifndef VIDEOGIOCO_SCORE_H
#define VIDEOGIOCO_SCORE_H

#include "Map/Map.h"
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

    //Getters & Setters
    void addPoints(int i);
    void setTable(std::shared_ptr<Table>& t);
    void setMap(std::shared_ptr<Map>& m);
    void addNotSatisfied();
    [[nodiscard]] bool getQuit() const;
    [[nodiscard]] int getTotalPoints() const;

private:
    std::vector<std::shared_ptr<Table>> table;
    int totalPoints;
    std::shared_ptr<Map> map;
    int notSatisfiedTables;
    bool quit;
};


#endif //VIDEOGIOCO_SCORE_H
