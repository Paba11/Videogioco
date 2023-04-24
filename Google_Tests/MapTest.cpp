//
// Created by Paolo Sbarzagli on 21/04/23.
//

#include "gtest/gtest.h"
#include "../Map/Map.h"
#include "../Waiter/Waiter.h"


Map* map = new Map();
Waiter* waiter = new Waiter();
Table* table = new Table();
Kitchen* kitchen = new Kitchen();
Entrance* entrance = new Entrance();


TEST(MapTest, LongDistanceTableTest) {
    table->sprite.setPosition(100, 100);
    waiter->getSprite().setPosition(300, 300);
    map->distanceTable(waiter->getSprite());
    ASSERT_EQ(!IS_CLOSE_TABLE, map->getIsClose());
}

/*
TEST(MapTest, ShortDistanceTableTest) {
    table.sprite.setPosition(100, 100);
    waiter.getSprite().setPosition(110, 110);
    map.distanceTable(waiter.getSprite())
    ASSERT_EQ()
}
*/