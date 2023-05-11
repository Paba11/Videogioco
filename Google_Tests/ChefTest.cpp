//
// Created by Paolo Sbarzagli on 10/05/23.
//
#include "../ProgramState/Game.h"
#include <gtest/gtest.h>

sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1298, 1344), "WaiterTest", sf::Style::Close);
std::stack<ProgramState*>* ps;
Game* game = new Game(window, ps, 1);
std::shared_ptr<Waiter> w = game->getWaiter();
std::shared_ptr<Map> m = game->getMap();
std::shared_ptr<Chef> c = game->getChef();

TEST(Chef, cookTest) {
    auto* a = new Appetizer(Apt::NACHOS);
    std::shared_ptr<Order> o = std::make_shared<Order>();
    o->setCurrent(Current::MAIN_DISH);
    o->setTableNumber(0);
    c->setOrder(o);
    c->setDishes(*a);
    c->setTime(1000);
    m->getKitchen()->getCounter()->setState(DishState::EMPTY);
    c->setState(Do::COOK);

    //Execute the test
    c->cook();

    //Control the results
    ASSERT_EQ(Do::COOK, c->getDo());

    //Change the variables
    c->setTime(0);

    //Execute the test
    c->cook();

    //Control the result
    ASSERT_EQ(Do::WAIT, c->getDo());
    ASSERT_EQ(true, c->getIsReady());
    ASSERT_EQ(DishState::FULL, m->getKitchen()->getState());
    ASSERT_EQ(true, c->getDishes().empty());
    ASSERT_EQ(nullptr, c->getOrder());
    ASSERT_EQ(false, m->getKitchen()->getWaitingOrders().empty());
    ASSERT_EQ(true, m->getKitchen()->getBottomBar()->getIsReady());
}

TEST(Chef, checkOrderTest) {
    std::shared_ptr<Order> o = std::make_shared<Order>();
    m->getKitchen()->setReadyOrder(o);
    c->setState(Do::WAIT);

    //ExecuteTest
    c->checkOrder();

    //Check results
    ASSERT_EQ(Do::COOK, c->getDo());
    ASSERT_EQ(DishState::COOKING, m->getKitchen()->getState());
}

TEST(Customer, createObjectTest) {
    std::shared_ptr<Order> o = std::make_shared<Order>();
    o->setPeopleNumber(1);
    o->setAppetizer(1);
    c->setOrder(o);
    o->setCurrent(Current::APPETIZER);

    //Execute test
    c->createObjects();

    //Check results
    ASSERT_EQ(false, c->getDishes().empty());
}