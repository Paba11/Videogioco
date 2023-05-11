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

TEST(Customer, generateCustomerTest) {
    //Test the way customers are generated
    game->getLevel()->setCustomerArrival(0);
    m->getEntrance()->setIsCustomer(false);

    game->generateCustomers();

    //Check results
    ASSERT_EQ(false, game->getGroup().empty());
    ASSERT_EQ(game->getLevel()->getTotalCustomerNumber(), game->getGroup().size());
    ASSERT_EQ(true, m->getEntrance()->getIsCustomer());
}

TEST(Customer, movingTest) {
    game->generateCustomers();
    std::vector<std::shared_ptr<Customer>> customer = game->getGroup();

    //Call the moving functions and check is working
    for(int i = 0; i < 50; i ++)
    {
        for(auto & it : customer)
        {
            it->setMovingStatus(Move::MOVING_UP);
            it->move();
            ASSERT_EQ(Move::MOVING_UP, it->getInvertedPath().top());
            it->setMovingStatus(Move::MOVING_DOWN);
            it->move();
            ASSERT_EQ(Move::MOVING_DOWN, it->getInvertedPath().top());
            it->setMovingStatus(Move::MOVING_LEFT);
            it->move();
            ASSERT_EQ(Move::MOVING_LEFT, it->getInvertedPath().top());
            it->setMovingStatus(Move::MOVING_RIGHT);
            it->move();
            ASSERT_EQ(Move::MOVING_RIGHT, it->getInvertedPath().top());
        }

    }
}