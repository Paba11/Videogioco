//
// Created by Paolo Sbarzagli on 12/05/23.
//

#include "gtest/gtest.h"
#include "../ProgramState/Game.h"

sf::RenderWindow* rwScore = new sf::RenderWindow(sf::VideoMode(1298, 1344), "MapTest", sf::Style::Close);
std::stack<ProgramState*>* psScore;
Game* gameScore = new Game(rwScore, psScore, 1);
std::shared_ptr<Waiter> wScore = gameScore->getWaiter();
std::shared_ptr<Map> mScore = gameScore->getMap();

TEST(Score, finalScoreTest) {
    for(int i = 0; i < 4; i++)
        mScore->getAllTables()[i].setState(TableState::IS_LEAVING);
    gameScore->getScore().update();

    ASSERT_EQ(40000, gameScore->getScore().getTotalPoints());
}

TEST(Score, gameOverTest) {
    for(int i = 0; i < 4; i++)
        gameScore->getScore().addNotSatisfied();
    gameScore->getScore().update();

    ASSERT_EQ(true, gameScore->getScore().getQuit());

    delete rwScore;
    delete psScore;
    delete gameScore;
}

