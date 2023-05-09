//
// Created by Paolo Sbarzagli on 09/05/23.
//

#include "../Waiter/Waiter.h"
#include <gtest/gtest.h>

Waiter* w = new Waiter();

TEST(Waiter, waiterConstructor) {

    //Test constructed variables
    ASSERT_EQ(Actions::DOING_NOTHING, w->getState());
    ASSERT_EQ(Move::STANDING, w->getMove());
    ASSERT_EQ(8, w->getSpeed());
    ASSERT_EQ(nullptr, w->getOrder());
    ASSERT_EQ(false, w->getIsReceived());

    //Test sprite
    ASSERT_EQ(25, w->getSprite().getOrigin().x);
    ASSERT_EQ(50, w->getSprite().getOrigin().y);
    ASSERT_EQ(800, w->getSprite().getPosition().x);
    ASSERT_EQ(400, w->getSprite().getPosition().y);
    ASSERT_EQ(2.20f, w->getSprite().getScale().x);
    ASSERT_EQ(2.20f, w->getSprite().getScale().y);
}

