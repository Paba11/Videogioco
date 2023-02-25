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
#include "MealMenu.h"
#include "Customer.h"
#include <queue>

enum TableState {CHOOSING, WAITING_TO_ORDER, WAITING_DISHES, EATING, ENDED};

#define TIME_TO_CHOOSE 15;

class Table {
public:
    //Constructor & Destructor
    Table();
    ~Table();
    void update();
    void render(sf::RenderTarget& target);
    void initSprite();
    sf::Sprite sprite;

    //Table actions
    void receivingCustomers(std::vector<Customer>& customer);
    void ordering();


    //Getters & Setters
    int getTavNum();
    void setTavNum(int tavNum);
    const sf::Vector2f& getPosition() const;
    Dish* getDish();
    void setDish(Dish* dish);
    std::queue<Dish*> getDishes();
    TableState getState();
    void setState(TableState s);
    Order* getOrder() const;
    void setOrder();
    Current getCourse() const;
    void setCourse(Current c);
    std::vector <Stool> stoolTable;
    void setCustomerNumber(int i);
    int getCustomerNumber();
    void setCustomers(std::vector<Customer>& cust);
    std::vector<Customer>& getCustomers();
    void setIsOccupied(bool t);
    bool getIsOccupied();

    //Initialize table
    void initStoolTable();
    void posStool(float x, float y);

private:
    //Attributes of the table
    int tavNum;
    std::queue<Dish*> dishes;
    std::vector<Customer> customers;
    TableState state;
    Current course;
    Order* order;
    int numStoolsTable;
    int customerNumber;
    sf::Clock timer;
    bool isOccupied;

};


#endif //VIDEOGIOCO_TABLE_H
