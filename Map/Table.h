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
#include "../Dish/Dish.h"
#include "../Dish/Order.h"
#include "../Dish/Recipe.h"
#include "Stool.h"
#include "../Dish/MealMenu.h"
#include "../NPC/Customer.h"
#include <queue>

enum class TableState {CHOOSING, WAITING_TO_ORDER, ORDERING, WAITING_DISHES, EATING, ENDED};

#define TIME_TO_CHOOSE 20

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
    std::shared_ptr<Order> getOrder();
    void setOrder(const std::shared_ptr<Order>& ord);
    Current getCourse() const;
    void setCourse(Current c);
    std::vector<Stool>& getStoolTable();
    void setCustomerNumber(int i);
    int getCustomerNumber();
    void setCustomers(std::vector<Customer>& cust);
    std::vector<Customer>& getCustomers();
    void setIsOccupied(bool t);
    bool getIsOccupied();
    void setIsReady(bool t);
    bool getIsReady();
    void setChosenTable(bool t);
    bool getChosenTable();
    sf::RectangleShape getInteractionSquare();

    //Initialize table
    void initStoolTable();
    void posStool(float x, float y);

    void updateBox();
    void setTable();


private:
    //Attributes of the table
    int tavNum;
    std::vector<Stool> stoolTable;
    std::queue<Dish*> dishes;
    std::vector<Customer> customers;
    TableState state;
    Current course;
    std::shared_ptr<Order> order;
    int numStoolsTable;
    int customerNumber;
    sf::Clock timer;
    bool isOccupied;
    bool isReady;

    sf::RectangleShape interactionSquare;
    sf::Color boxOpacity = {253,202,78,255};
    bool cicle;
    bool chosenTable;

};


#endif //VIDEOGIOCO_TABLE_H
