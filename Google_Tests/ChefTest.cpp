//
// Created by Paolo Sbarzagli on 10/05/23.
//
#include "../ProgramState/Game.h"
#include <gtest/gtest.h>

sf::RenderWindow* chefWindow = new sf::RenderWindow(sf::VideoMode(1298, 1344), "WaiterTest", sf::Style::Close);
std::stack<ProgramState*>* chefPs;
Game* gameChef = new Game(chefWindow, chefPs, 1);
std::shared_ptr<Waiter> wChef = gameChef->getWaiter();
std::shared_ptr<Map> mChef = gameChef->getMap();
std::shared_ptr<Chef> cChef = gameChef->getChef();

TEST(Chef, cookTest) {
    auto* a = new Appetizer(Apt::NACHOS);
    std::shared_ptr<Order> o = std::make_shared<Order>();
    o->setCurrent(Current::MAIN_DISH);
    o->setTableNumber(0);
    cChef->setOrder(o);
    cChef->setDishes(*a);
    cChef->setTime(1000);
    mChef->getKitchen()->getCounter()->setState(DishState::EMPTY);
    cChef->setState(Do::COOK);

    //Execute the test
    cChef->cook();

    //Control the results
    ASSERT_EQ(Do::COOK, cChef->getDo());

    //Change the variables
    cChef->setTime(0);

    //Execute the test
    cChef->cook();

    //Control the result
    ASSERT_EQ(Do::WAIT, cChef->getDo());
    ASSERT_EQ(true, cChef->getIsReady());
    ASSERT_EQ(DishState::FULL, mChef->getKitchen()->getCounter()->getState());
    ASSERT_EQ(true, cChef->getDishes().empty());
    ASSERT_EQ(nullptr, cChef->getOrder());
    ASSERT_EQ(false, mChef->getKitchen()->getWaitingOrders().empty());
    ASSERT_EQ(true, mChef->getKitchen()->getBottomBar()->getIsReady());
}

TEST(Chef, checkOrderTest) {
    std::shared_ptr<Order> o = std::make_shared<Order>();
    mChef->getKitchen()->setReadyOrder(o);
    cChef->setState(Do::WAIT);

    //ExecuteTest
    cChef->checkOrder();

    //Check results
    ASSERT_EQ(Do::COOK, cChef->getDo());
    ASSERT_EQ(DishState::COOKING, mChef->getKitchen()->getState());
}

TEST(Customer, createObjectTest) {
    std::shared_ptr<Order> o = std::make_shared<Order>();
    o->setPeopleNumber(1);
    o->setAppetizer(1);
    cChef->setOrder(o);
    o->setCurrent(Current::APPETIZER);

    //Execute test
    cChef->createObjects();

    //Check results
    ASSERT_EQ(false, cChef->getDishes().empty());

    delete chefWindow;
    delete chefPs;
    delete gameChef;
}