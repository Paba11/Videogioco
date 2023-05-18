//
// Created by Paolo Sbarzagli on 21/04/23.
//

#include "gtest/gtest.h"
#include "TestFixture.h"
#include "../ProgramState/Game.h"

TEST_F(GameTest, distanceTableTest) {

    //Test the table distance algorithm
    map->setIsClose(IS_CLOSE_NOTHING);

    //Distance from every table > than needed
    waiter->setPositionW(0, 0);
    map->distanceTable(game->getWaiter()->getSprite());

    //Check results
    ASSERT_EQ(IS_CLOSE_NOTHING, map->getIsClose());

    //Short distance from table 0
    waiter->setPositionW(150, 330);
    map->distanceTable(waiter->getSprite());

    //Check results
    ASSERT_EQ(IS_CLOSE_TABLE, map->getIsClose());
    ASSERT_EQ(&map->getTable(0), map->distanceTable(game->getWaiter()->getSprite()));
}


TEST_F(GameTest, distanceKitchenTest) {
    //Test the kitchen distance algorithm
    map->setIsClose(IS_CLOSE_NOTHING);

    //Distance from the kitchen > than needed
    waiter->setPositionW(0, 0);
    map->distanceKitchen(game->getWaiter()->getSprite());

    //Check Results
    ASSERT_EQ(IS_CLOSE_NOTHING, map->getIsClose());

    //Short distance from the kitchen
    waiter->setPositionW(990,450);
    map->distanceKitchen(waiter->getSprite());

    //Check results
    ASSERT_EQ(IS_CLOSE_KITCHEN, map->getIsClose());
}


TEST_F(GameTest, distanceInteractionSquare) {
    //Test the distance to the interaction square

    //Wrong position
    waiter->setPositionW(0,0);
    ASSERT_EQ(false, map->distanceInteractionSquare(waiter->getSprite(), &map->getTable(0)));

    //Right position
    waiter->setPositionW(145,250);
    ASSERT_EQ(true, map->distanceInteractionSquare(waiter->getSprite(), &map->getTable(0)));

}