//
// Created by Paolo Sbarzagli on 23/02/23.
//

#include "Score.h"


Score::Score() {
    totalPoints = 0;
    notSatisfiedTables = 0;
}

Score::~Score() {

}

void Score::update() {
    if(notSatisfiedTables > 3)
    {
        gameOver();
    }
    for(auto &i: table)
    {
        if(i->getState() == TableState::ENDED)
        {
            if(!i->getIsSetFinalScore())
            {
                addPoints((i->getHumor()/10));
                i->setIsSetFinalScore(true);
                i->setHumor(500);
            }
            std::cout << "XP gained: " << i->getHumor()/10 << " XP total: " << totalPoints << std::endl;
        }
    }
}

void Score::render() {

}

void Score::addPoints(int i) {
    totalPoints += i;
}

void Score::setTable(Table *t) {
    table.push_back(t);
}

void Score::gameOver() {
    //When the number of tables that left the restaurant is bigger than three, end the game
}

void Score::addNotSatisfied() {
    notSatisfiedTables += 1;
}
