//
// Created by Paolo Sbarzagli on 23/02/23.
//

#include "Score.h"


Score::Score() {
    totalPoints = 0;
    notSatisfiedTables = 0;
    quit = false;
}

Score::~Score() = default;

void Score::update() {
    if(notSatisfiedTables > 2)
    {
        quit = true;
    }
    for(auto &i: map->getAllTables())
    {
        if(i.getState() == TableState::IS_LEAVING && !i.getIsSetFinalScore())
        {
            addPoints((i.getHumor()/10));
            i.setIsSetFinalScore(true);
            i.setHumor(500);
            std::cout << "XP gained: " << i.getHumor()/10 << " XP total: " << totalPoints << std::endl;
        }
    }
}

void Score::addPoints(int i) {
    totalPoints += i;
}

void Score::setTable(std::shared_ptr<Table>& t) {
    table.push_back(t);
}

void Score::addNotSatisfied() {
    notSatisfiedTables += 1;
}

bool Score::getQuit() const {
    return quit;
}

int Score::getTotalPoints() const {
    return totalPoints;
}

void Score::setMap(std::shared_ptr<Map>& m) {
    map.reset();
    map = m;
}
