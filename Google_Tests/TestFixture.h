//
// Created by Paolo Sbarzagli on 18/05/23.
//

#ifndef VIDEOGIOCO_TESTFIXTURE_H
#define VIDEOGIOCO_TESTFIXTURE_H
#include <gtest/gtest.h>
#include <cstdlib>
#include "../ProgramState/Game.h"
#include "../Map/Map.h"
#include "../ProgramState/ProgramState.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class GameTest: public ::testing::Test {
    public:

    void SetUp() override {
        waiter = game->getWaiter();
        map = game->getMap();
        chef = game->getChef();
    };

    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1298, 1344), "Tests", sf::Style::Close);
    std::stack<ProgramState*>* chefPs;
    Game* game = new Game(window, chefPs, 1);
    std::shared_ptr<Waiter> waiter;
    std::shared_ptr<Map> map;
    std::shared_ptr<Chef> chef;
};

#endif //VIDEOGIOCO_TESTFIXTURE_H
