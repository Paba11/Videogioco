//
// Created by Paolo Sbarzagli on 24/02/23.
//

#ifndef VIDEOGIOCO_FIRSTLEVEL_H
#define VIDEOGIOCO_FIRSTLEVEL_H


#include <map>
#include <vector>
#include "Waiter/Waiter.h"
#include "NPC/DishWasher.h"
#include "Map/Map.h"
#include "NPC/Customer.h"
#include "Map/Table.h"
#include "Textures.h"
#include "ProgramState/ProgramState.h"
#include "NPC/Chef.h"
#include "Map/Counter.h"
#include "LevelHeader.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Score.h"
#include <list>
#include <random>


class Level {
public:
    Level();
    ~Level();

    //Updates
    void update();

    //Set level Variables
    void initLevel(Lvl l);
    void initVariables();

    //Getters & Setters
    Lvl getLevel();
    void setLevel(Lvl l);
    float getCustomerArrival();
    void setCustomerArrival(float c);
    int getTotalCustomerNumber();
    void addTotalCustomerNumber();
    float getDifficulty();

private:
    int totalCustomerNumber;
    float difficulty;
    float customerArrival;
    std::shared_ptr<Customer> customer;
    std::vector<Customer> customers;
    sf::Clock clock;
    Lvl lvl;

};


#endif //VIDEOGIOCO_FIRSTLEVEL_H
