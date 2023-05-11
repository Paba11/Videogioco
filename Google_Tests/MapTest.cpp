//
// Created by Paolo Sbarzagli on 21/04/23.
//

#include "gtest/gtest.h"
#include "../ProgramState/Game.h"

sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1298, 1344), "MapTest", sf::Style::Close);
std::stack<ProgramState*>* ps;
Game* game = new Game(window, ps, 1);
std::shared_ptr<Waiter> w = game->getWaiter();
std::shared_ptr<Map> m = game->getMap();

TEST(MapTest, distanceTableTest) {
    //Test the table distance algorithm
    m->setIsClose(IS_CLOSE_NOTHING);

    //Distance from every table > than needed
    w->setPositionW(0, 0);
    m->distanceTable(game->getWaiter()->getSprite());

    //Check results
    ASSERT_EQ(IS_CLOSE_NOTHING, m->getIsClose());

    //Short distance from table 0
    w->setPositionW(150, 330);
    m->distanceTable(w->getSprite());

    //Check results
    ASSERT_EQ(IS_CLOSE_TABLE, m->getIsClose());
    ASSERT_EQ(&m->getTable(0), m->distanceTable(game->getWaiter()->getSprite()));
}


TEST(MapTest, distanceKitchenTest) {
    //Test the kitchen distance algorithm
    m->setIsClose(IS_CLOSE_NOTHING);

    //Distance from the kitchen > than needed
    w->setPositionW(0, 0);
    m->distanceKitchen(game->getWaiter()->getSprite());

    //Check Results
    ASSERT_EQ(IS_CLOSE_NOTHING, m->getIsClose());

    //Short distance from the kitchen
    w->setPositionW(990,450);
    m->distanceKitchen(w->getSprite());

    //Check results
    ASSERT_EQ(IS_CLOSE_KITCHEN, m->getIsClose());
}

TEST(Map, distanceInteractionSquare) {
    //Test the distance to the interaction square

    //Wrong position
    w->setPositionW(0,0);
    ASSERT_EQ(false, m->distanceInteractionSquare(w->getSprite(), &m->getTable(0)));

    //Right position
    w->setPositionW(145,250);
    ASSERT_EQ(true, m->distanceInteractionSquare(w->getSprite(), &m->getTable(0)));
}