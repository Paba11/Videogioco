//
// Created by Paolo Sbarzagli on 09/05/23.
//

#include "../ProgramState/Game.h"
#include <SFML/Graphics.hpp>
#include <gtest/gtest.h>

sf::RenderWindow* windowWaiter = new sf::RenderWindow(sf::VideoMode(1298, 1344), "WaiterTest", sf::Style::Close);
std::stack<ProgramState*>* psWaiter;
Game* gameWaiter = new Game(windowWaiter, psWaiter, 1);
std::shared_ptr<Waiter> wWaiter = gameWaiter->getWaiter();
std::shared_ptr<Map> mWaiter = gameWaiter->getMap();

TEST(Waiter, waiterConstructor) {

    //Test constructed variables
    ASSERT_EQ(Actions::DOING_NOTHING, wWaiter->getState());
    ASSERT_EQ(Move::STANDING, wWaiter->getMove());
    ASSERT_EQ(8, wWaiter->getSpeed());
    ASSERT_EQ(nullptr, wWaiter->getOrder());
    ASSERT_EQ(false, wWaiter->getIsReceived());

    //Test sprite
    ASSERT_EQ(25, wWaiter->getSprite().getOrigin().x);
    ASSERT_EQ(50, wWaiter->getSprite().getOrigin().y);
    ASSERT_EQ(800, wWaiter->getSprite().getPosition().x);
    ASSERT_EQ(400, wWaiter->getSprite().getPosition().y);
    ASSERT_EQ(2.20f, wWaiter->getSprite().getScale().x);
    ASSERT_EQ(2.20f, wWaiter->getSprite().getScale().y);
}

TEST(Waiter, setOrder) {

    wWaiter->setOrder(mWaiter, &mWaiter->getTable(0));

    ASSERT_EQ(TableState::WAITING_DISHES, mWaiter->getTable(0).getState());
    ASSERT_EQ(true, wWaiter->getHasOrder());
    ASSERT_EQ(Actions::DOING_NOTHING, wWaiter->getState());
}

TEST(Waiter, pickUpActionState) {
    //Pick Up Testing
    std::shared_ptr<ActionsState> act = std::make_shared<ActionsState>(mWaiter);
    act->setTray(gameWaiter->getTray());
    wWaiter->setActionState(act);
    Appetizer* a;
    int i;
    for(i = 0; i < 4; i++)
    {
        a = new Appetizer(Apt::NACHOS);
        mWaiter->getTable(0).setDish(a, i);
    }

    //Set the guard conditions
    wWaiter->getActionState()->getTray()->setState(TrayState::EMPTY_TRAY);
    mWaiter->getTable(0).setState(TableState::ENDED);

    //Call the function
    wWaiter->getActionState()->pickUp(&mWaiter->getTable(0));

    //Check the results
    ASSERT_EQ(false, mWaiter->getTable(0).getChosenTable());
    ASSERT_EQ(0, mWaiter->getTable(0).getDishes().size());
    ASSERT_EQ(TrayState::EMPTY_PLATES, wWaiter->getActionState()->getTray()->getState());
}

TEST(Waiter, putDownActionState) {
    //Put down testing
    std::shared_ptr<ActionsState> act = std::make_shared<ActionsState>(mWaiter);
    while(!gameWaiter->getTray()->getDishes().empty())
    {
        gameWaiter->getTray()->getDishes().pop();
    }
    act->setTray(gameWaiter->getTray());
    wWaiter->setActionState(act);
    Appetizer* a;
    int i;
    for(i = 0; i < 4; i++)
    {
        a = new Appetizer(Apt::NACHOS);
        a->setTavNum(0);
        wWaiter->getActionState()->getTray()->setDish(a, i);
    }

    //Set the guard conditions
    wWaiter->getActionState()->getTray()->setState(TrayState::FILLED_TRAY);
    mWaiter->getTable(0).setState(TableState::WAITING_DISHES);
    ASSERT_EQ(0, mWaiter->getTable(0).getDishes().size());
    ASSERT_EQ(4, wWaiter->getActionState()->getTray()->getDishes().size());

    //Call the function
    wWaiter->getActionState()->putDown(&mWaiter->getTable(0));

    //Check the results
    ASSERT_EQ(4, mWaiter->getTable(0).getDishes().size());
    ASSERT_EQ(TableState::EATING, mWaiter->getTable(0).getState());
    ASSERT_EQ(TrayState::EMPTY_TRAY, wWaiter->getActionState()->getTray()->getState());

    delete windowWaiter;
    delete psWaiter;
    delete gameWaiter;
}

