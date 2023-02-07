//
// Created by Paolo Sbarzagli on 07/02/23.
//

#ifndef VIDEOGIOCO_TABLE_H
#define VIDEOGIOCO_TABLE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Dish.h"
#include "Order.h"


class Table {
public:
    //Constructor & Destructor
    Table();
    ~Table();

    //Getters & Setters
    int getTavNum();
    void setTavNum(int tavNum);

private:
    int tavNum;

};


#endif //VIDEOGIOCO_TABLE_H
