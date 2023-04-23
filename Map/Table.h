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
#include <queue>

enum class TableState {CHOOSING, WAITING_TO_ORDER, WAITING_DISHES, EATING, ENDED};

#define TIME_TO_CHOOSE 5.f

class Table {
public:
    //Constructor & Destructor
    Table();
    ~Table();
    void update();
    void render(sf::RenderTarget& target);

    sf::Sprite sprite;

    //Table actions
    void receivingCustomers(std::vector<Customer>& customer);
    void ordering();
    void updateHumor();
    void reInitTable();

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
    void setChosenTable(bool t);
    bool getChosenTable();
    sf::RectangleShape getInteractionSquare();
    void restartTimer();
    std::vector<sf::RectangleShape> getDishesPlace();
    void setIsSit(bool t);
    bool getIsSetFinalScore();
    void setIsSetFinalScore(bool t);
    void setHumor(int i);
    int getHumor();

    //Initialize table
    void initStoolTable();
    void posStool(float x, float y);

    void updateBox();
    void setTable();
    void setDishesPlace();

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

    int humor;
    sf::Clock scoreTimer;
    bool isSetFinalScore;
};


#endif //VIDEOGIOCO_TABLE_H
