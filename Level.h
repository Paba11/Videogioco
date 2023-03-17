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
#include <list>
#include <random>


class Level {
public:
    Level();
    ~Level();

    //Set level Variables
    void initLevel(Lvl l);
    void initVariables();

    //Getters & Setters
    Lvl getLevel();
    void setLevel(Lvl l);
    bool getIsPassed();
    void setIsPassed(bool t);
    float getCustomerArrival();
    void setCustomerArrival(float c);
    int getTotalCustomerNumber();
    void reduceTotalCustomerNumber();

private:
    int totalCustomerNumber;
    float initialHumor;
    float customerArrival;
    int maxTables;
    Customer* customer;
    std::vector<Customer> customers;
    sf::Clock clock;
    Lvl lvl;
    bool isPassed;

};


#endif //VIDEOGIOCO_FIRSTLEVEL_H
