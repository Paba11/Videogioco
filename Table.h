//
// Created by Ettore Righi on 04/02/23.
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
#include "Recipe.h"
#include "Stool.h"
#include <queue>

enum TableState {CHOOSING, WAITING_TO_ORDER, WAITING_DISHES, EATING, ENDED};
enum ActualCourse {APPET, MAINCOURSE, DESS, END};


class Table {
public:
    //Constructor & Destructor
    Table();
    ~Table();
    void update();
    void render(sf::RenderTarget& target);
    void initSprite();
    sf::Sprite sprite;

    //Getters & Setters
    int getTavNum();
    void setTavNum(int tavNum);
    const sf::Vector2f& getPosition() const;
    Dish* getDish();
    void setDish(Dish* dish);
    std::queue<Dish*> getDishes();
    TableState getState();
    void setState(int i);
    Order* getOrder() const;
    void setOrder();
    ActualCourse getCourse() const;
    void setCourse(int i);
    std::vector <Stool> stoolTable;
    void setCustomerNumber(int i);
    int getCustomerNumber();

    //Initialize table
    void initStoolTable();
    void posStool(float x, float y);

private:
    //Attributes of the table
    int tavNum;
    std::queue<Dish*> dishes;
    TableState state;
    ActualCourse course;
    Order* order;
    int numStoolsTable = 4;
    int customerNumber;

};


#endif //VIDEOGIOCO_TABLE_H
