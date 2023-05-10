//
// Created by Paolo Sbarzagli on 09/05/23.
//

#include "../Waiter/Waiter.h"
#include "../Map/Map.h"
#include <SFML/Graphics.hpp>
#include <gtest/gtest.h>

sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1100, 620), "Waiter", sf::Style::Close);
Waiter* w = new Waiter();
std::shared_ptr<Map> m = std::make_shared<Map>();

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

TEST(Waiter, setOrder) {

    w->setOrder(m, &m->getTable(0));

    ASSERT_EQ(TableState::WAITING_DISHES, m->getTable(0).getState());
    ASSERT_EQ(true, w->getHasOrder());
    ASSERT_EQ(Actions::DOING_NOTHING, w->getState());
}

TEST(Waiter, pickUpActionState) {
    //Pick Up Testing
    std::shared_ptr<ActionsState> act = std::make_shared<ActionsState>(m);
    w->setActionState(act);
    Appetizer* a;
    int i;
    for(i = 0; i < 4; i++)
    {
        a = new Appetizer(Apt::NACHOS);
        m->getTable(0).setDish(a, i);
    }

    //Set the guard conditions
    w->getActionState()->getTray()->setState(TrayState::EMPTY_TRAY);
    m->getTable(0).setState(TableState::ENDED);

    //Call the function
    w->getActionState()->pickUp(&m->getTable(0));

    //Check the results
    ASSERT_EQ(false, m->getTable(0).getChosenTable());
    ASSERT_EQ(4, m->getTable(0).getDishes().size());
    ASSERT_EQ(TrayState::EMPTY_PLATES, w->getActionState()->getTray()->getState());
}

TEST(Waiter, putDownActionState) {
    //Put down testing
    std::shared_ptr<ActionsState> act = std::make_shared<ActionsState>(m);
    w->setActionState(act);
    Appetizer* a;
    int i;
    for(i = 0; i < 4; i++)
    {
        a = new Appetizer(Apt::NACHOS);
        a->setTavNum(0);
        w->getActionState()->getTray()->setDish(a, i);
    }

    //Set the guard conditions
    w->getActionState()->getTray()->setState(TrayState::FILLED_TRAY);
    m->getTable(0).setState(TableState::WAITING_DISHES);

    //Check the results
    ASSERT_EQ(4, m->getTable(0).getDishes().size());
    ASSERT_EQ(TableState::EATING, m->getTable(0).getState());
    ASSERT_EQ(TrayState::EMPTY_TRAY, w->getActionState()->getTray()->getState());

}

