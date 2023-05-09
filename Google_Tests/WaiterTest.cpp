//
// Created by Paolo Sbarzagli on 09/05/23.
//

#include "../Waiter/Waiter.h"
#include "../Map/Map.h"
#include <SFML/Graphics.hpp>
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

TEST(Waiter, setOrder) {
    std::shared_ptr<Map> m;
    m = std::make_shared<Map>();

    w->setOrder(m, &m->getTable(0));

    ASSERT_EQ(TableState::WAITING_DISHES, m->getTable(0).getState());
    ASSERT_EQ(true, w->getHasOrder());
    ASSERT_EQ(Actions::DOING_NOTHING, w->getState());
}

TEST()


/*
TEST(Waiter, interactionFunction){
    std::shared_ptr<Map> m;
    m = std::make_shared<Map>();
    sf::Event ev;

    //Set to receive customers
    ev.key.code = sf::Keyboard::J;
    m->setIsClose(IS_CLOSE_ENTRANCE);
    m->getEntrance()->setIsCustomer(true);
    w->getReceiveState()->setPo;
    w->interact(m, ev);
    ASSERT_EQ()
}
 */