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

enum TableState {CHOOSING, WAITING_TO_ORDER, WAITING_DISHES, EATING, ENDED};
enum ActualCourse {APPETIZER, MAINCOURSE, DESSERT};


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
    Dish* getDish(int i);
    void setDish(int i, Dish* dish);
    TableState getState();
    void setState(int i);
    Order* getOrder() const;
    void setOrder();
    ActualCourse getCourse() const;
    void setCourse(int i);
    std::vector <Stool> stoolTable;
    void initStoolTable();
    void posStool(float x, float y);
private:
    //Attributes of the table
    int tavNum;
    Dish* dish[MAX_DISHES];
    TableState state;
    ActualCourse course;
    Order* order;
    int numStoolsTable = 4;

};


#endif //VIDEOGIOCO_TABLE_H
