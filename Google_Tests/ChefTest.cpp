//
// Created by Paolo Sbarzagli on 10/05/23.
//
#include "../ProgramState/Game.h"
#include "TestFixture.h"
#include <gtest/gtest.h>

TEST_F(GameTest, cookTest) {

    auto* a = new Appetizer(Apt::NACHOS);
    std::shared_ptr<Order> o = std::make_shared<Order>();
    o->setCurrent(Current::MAIN_DISH);
    o->setTableNumber(0);
    chef->setOrder(o);
    chef->setDishes(*a);
    chef->setTime(1000);
    map->getKitchen()->getCounter()->setState(DishState::EMPTY);
    chef->setState(Do::COOK);

    //Execute the test
    chef->cook();

    //Control the results
    ASSERT_EQ(Do::COOK, chef->getDo());

    //Change the variables
    chef->setTime(0);

    //Execute the test
    chef->cook();

    //Control the result
    ASSERT_EQ(Do::WAIT, chef->getDo());
    ASSERT_EQ(true, chef->getIsReady());
    ASSERT_EQ(DishState::FULL, map->getKitchen()->getCounter()->getState());
    ASSERT_EQ(true, chef->getDishes().empty());
    ASSERT_EQ(nullptr, chef->getOrder());
    ASSERT_EQ(false, map->getKitchen()->getWaitingOrders().empty());
    ASSERT_EQ(true, map->getKitchen()->getBottomBar()->getIsReady());
}

TEST_F(GameTest, checkOrderTest) {

    std::shared_ptr<Order> o = std::make_shared<Order>();
    map->getKitchen()->setReadyOrder(o);
    chef->setState(Do::WAIT);

    //ExecuteTest
    chef->checkOrder();

    //Check results
    ASSERT_EQ(Do::COOK, chef->getDo());
    ASSERT_EQ(DishState::COOKING, map->getKitchen()->getState());
}

TEST_F(GameTest, createObjectTest) {

    std::shared_ptr<Order> o = std::make_shared<Order>();
    o->setPeopleNumber(1);
    o->setAppetizer(1);
    chef->setOrder(o);
    o->setCurrent(Current::APPETIZER);

    //Execute test
    chef->createObjects();

    //Check results
    ASSERT_EQ(false, chef->getDishes().empty());
}