//
// Created by Paolo Sbarzagli on 10/05/23.
//
#include "../ProgramState/Game.h"
#include <gtest/gtest.h>

sf::RenderWindow* windowCustomer = new sf::RenderWindow(sf::VideoMode(1298, 1344), "WaiterTest", sf::Style::Close);
std::stack<ProgramState*>* psCustomer;
Game* gameCustomer = new Game(windowCustomer, psCustomer, 1);
std::shared_ptr<Waiter> wCustomer = gameCustomer->getWaiter();
std::shared_ptr<Map> mCustomer = gameCustomer->getMap();

TEST(Customer, generateCustomerTest) {
    //Test the way customers are generated
    gameCustomer->getLevel()->setCustomerArrival(0);
    mCustomer->getEntrance()->setIsCustomer(false);

    gameCustomer->generateCustomers();

    //Check results
    ASSERT_EQ(false, gameCustomer->getGroup().empty());
    ASSERT_EQ(gameCustomer->getLevel()->getTotalCustomerNumber(), gameCustomer->getGroup().size());
    ASSERT_EQ(true, mCustomer->getEntrance()->getIsCustomer());
}

TEST(Customer, movingTest) {
    gameCustomer->generateCustomers();
    std::vector<std::shared_ptr<Customer>> customer = gameCustomer->getGroup();

    //Call the moving functions and check is working
    for(int i = 0; i < 50; i ++)
    {
        for(auto & it : customer)
        {
            it->setMovingStatus(Move::MOVING_UP);
            it->move();
            ASSERT_EQ(Move::MOVING_DOWN, it->getInvertedPath().top());
            it->setMovingStatus(Move::MOVING_DOWN);
            it->move();
            ASSERT_EQ(Move::MOVING_UP, it->getInvertedPath().top());
            it->setMovingStatus(Move::MOVING_LEFT);
            it->move();
            ASSERT_EQ(Move::MOVING_RIGHT, it->getInvertedPath().top());
            it->setMovingStatus(Move::MOVING_RIGHT);
            it->move();
            ASSERT_EQ(Move::MOVING_LEFT, it->getInvertedPath().top());
        }

    }
    delete windowCustomer;
    delete psCustomer;
    delete gameCustomer;
}