//
// Created by Paolo Sbarzagli on 23/02/23.
//

#include "Score.h"


Score::Score() {
    totalPoints = 0;
}

Score::~Score() {

}

void Score::update() {
    for(auto &i: table)
    {
        if(i->getState() == TableState::ENDED)
        {
            if(!i->getIsSetFinalScore())
            {
                addPoints(i->getHumor());
                i->setIsSetFinalScore(true);
                i->setHumor(500);
            }
        }
    }
}

void Score::render() {

}

void Score::addPoints(int i) {
    totalPoints += i;
}

void Score::setTable(Table *t, int i) {
    table[i] = t;
}
