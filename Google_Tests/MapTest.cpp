//
// Created by Paolo Sbarzagli on 21/04/23.
//

#include "gtest/gtest.h"
#include "../ProgramState/Game.h"

sf::RenderWindow* rwMap = new sf::RenderWindow(sf::VideoMode(1298, 1344), "MapTest", sf::Style::Close);
std::stack<ProgramState*>* psMap;
Game* gameMap = new Game(rwMap, psMap, 1);
std::shared_ptr<Waiter> wMap = gameMap->getWaiter();
std::shared_ptr<Map> mMap = gameMap->getMap();

TEST(MapTest, distanceTableTest) {
    //Test the table distance algorithm
    mMap->setIsClose(IS_CLOSE_NOTHING);

    //Distance from every table > than needed
    wMap->setPositionW(0, 0);
    mMap->distanceTable(gameMap->getWaiter()->getSprite());

    //Check results
    ASSERT_EQ(IS_CLOSE_NOTHING, mMap->getIsClose());

    //Short distance from table 0
    wMap->setPositionW(150, 330);
    mMap->distanceTable(wMap->getSprite());

    //Check results
    ASSERT_EQ(IS_CLOSE_TABLE, mMap->getIsClose());
    ASSERT_EQ(&mMap->getTable(0), mMap->distanceTable(gameMap->getWaiter()->getSprite()));
}


TEST(MapTest, distanceKitchenTest) {
    //Test the kitchen distance algorithm
    mMap->setIsClose(IS_CLOSE_NOTHING);

    //Distance from the kitchen > than needed
    wMap->setPositionW(0, 0);
    mMap->distanceKitchen(gameMap->getWaiter()->getSprite());

    //Check Results
    ASSERT_EQ(IS_CLOSE_NOTHING, mMap->getIsClose());

    //Short distance from the kitchen
    wMap->setPositionW(990,450);
    mMap->distanceKitchen(wMap->getSprite());

    //Check results
    ASSERT_EQ(IS_CLOSE_KITCHEN, mMap->getIsClose());
}


TEST(Map, distanceInteractionSquare) {
    //Test the distance to the interaction square

    //Wrong position
    wMap->setPositionW(0,0);
    ASSERT_EQ(false, mMap->distanceInteractionSquare(wMap->getSprite(), &mMap->getTable(0)));

    //Right position
    wMap->setPositionW(145,250);
    ASSERT_EQ(true, mMap->distanceInteractionSquare(wMap->getSprite(), &mMap->getTable(0)));
}