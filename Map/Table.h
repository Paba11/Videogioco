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
#include "Stool.h"
#include "../Dish/MealMenu.h"
#include "../NPC/Customer.h"
#include "../LevelHeader.h"
#include <queue>

enum class TableState {CHOOSING, WAITING_TO_ORDER, WAITING_DISHES, EATING, ENDED, IS_LEAVING, LEFT};

#define INITIAL_HUMOR 10000

class Table {
public:
    //Constructor & Destructor
    Table();
    ~Table();
    void update();
    void updateBar();

    void render(sf::RenderTarget& target);
    void renderDishes(sf::RenderTarget& target);
    void renderBar(sf::RenderTarget& target);

    sf::Sprite sprite;

    //Table actions
    void receivingCustomers(std::vector<Customer>& customer);
    void ordering();
    void eating();
    void updateHumor();
    void reInitTable();
    void leaveTable();

    //Getters & Setters
    int getTavNum() const;
    void setTavNum(int tavNum);
    const sf::Vector2f& getPosition() const;
    Dish* getDish();
    void setDish(Dish* dish, int n);
    std::queue<Dish*> getDishes();
    TableState getState();
    void setState(TableState s);
    void setOrder(const std::shared_ptr<Order>& ord);
    Current getCourse() const;
    void setCourse(Current c);
    std::vector<Stool>& getStoolTable();
    int getCustomerNumber() const;
    void setCustomers(std::vector<Customer>& cust);
    std::vector<Customer>& getCustomers();
    void setIsOccupied(bool t);
    bool getIsOccupied() const;
    void setChosenTable(bool t);
    bool getChosenTable() const;
    sf::RectangleShape getInteractionSquare();
    void restartTimer();
    void restartScoreTimer();
    void setIsSit(bool t);
    bool getIsSetFinalScore() const;
    void setIsSetFinalScore(bool t);
    void setHumor(int i);
    int getHumor() const;
    bool getIsNotSatisfied() const;
    void setIsNotSatisfied(bool t);
    bool getIsMarked();
    void setIsMarked(bool t);

    //Initialize table
    void initStoolTable();
    void posStool(float x, float y);

    void updateBox();
    void setTable();
    void setDishesPlace();

    void changeDishesSprite();
    void initBar();


    void setDifficulty(float i);

private:

    void initTexture();
    void initSprite();
    void updateCornerSprite();

    //Attributes of the table
    int tavNum;
    std::vector<Stool> stoolTable;
    std::vector<sf::RectangleShape> dishesPlace;
    sf::Vector2f dishHitbox = {40.f,40.f};
    std::queue<Dish*> dishes;
    std::vector<Customer> customers;
    TableState state;
    Current course;
    std::shared_ptr<Order> order;
    int numStoolsTable;
    int customerNumber;
    sf::Clock timer;
    bool isOccupied;
    bool isSit;
    Textures* texture;
    sf::RectangleShape interactionSquare;
    sf::Color boxOpacity = {253,202,78,255};
    bool cicle;
    bool chosenTable;
    sf::Sprite cornerSprite;
    float eatingTime = 20;


    sf::RectangleShape greyBar;
    sf::RectangleShape greenBar;
    float totalBarIteration = 30;
    float actualBarIteration = 0;

    float difficulty;

    int humor;
    bool isMarked;
    sf::Clock scoreTimer;
    bool isSetFinalScore;
    bool isNotSatisfied;
};


#endif //VIDEOGIOCO_TABLE_H
