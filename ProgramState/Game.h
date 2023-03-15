//
// Created by Paolo Sbarzagli on 30/01/23.
//

#ifndef VIDEOGIOCO_GAME_H
#define VIDEOGIOCO_GAME_H


#include <map>
#include <vector>
#include "../Waiter/Waiter.h"
#include "../NPC/DishWasher.h"
#include "../Map/Map.h"
#include "../NPC/Customer.h"
#include "../Map/Table.h"
#include "ProgramState.h"
#include "../NPC/Chef.h"
#include "../Map/Counter.h"
#include "../Level.h"
#include "../BottomBar.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include <random>

class Game : public ProgramState {
public:
    //Constructor & Destructor
    Game(sf::RenderWindow* window, std::stack <ProgramState*>* states, int waiterTexture);
    ~Game() override;

    //Method to initialize all the textures needed inside the game
   // void initTexture();

    void endState() override;

    //Methods to update the game
    void update() override;
    void updateCustomers();
    void updateReceivingCustomer();

    //Methods to display the correct images
    void render(sf::RenderTarget* target) override;
    void renderMap();

    //Methods for handling the collision
    void updateCollision();
    void windowsCollision();
    void collision();
    void collisionManagement();
    void customerCollisionManagement();
    void customerCollision();

    //Generate Customers and random numbers
    void generateCustomers();
    void generateRandom();

    //Method to manage the events
    void pollEvents();
    ReceiveState* getReceiveState();

    //Method that update the position of the mouse relative to the game window
    void updateMousePos();

    //Method to check if the window is still open, so if the game is running

    //Update the current level
    void updateLevel();
    void nextLevel();

    //Getter & Setter for the attributes


private:
    //Group of textures uploaded in a container, each one is accessible by his own name
    //std::map<std::string, sf::Texture*> textures;
    //std::vector<Table> allTables;
    //
    sf::Vector2i mousePos;
    sf::Event ev;

    //GameCharacters and objects
    Waiter* waiter;
    Chef* chef;
    Dish* dish;
    Map* map;
    Kitchen* kitchen;
    Counter* counter;
    Washbasin* washbasin;
    Customer* customer;
    std::vector<Customer*> group;
    DishWasher* dishWasher;
    //OrderState* orderState;
    //ReceivingCustomers* receivingCustomers;
    BottomBar* bottomBar;
    //Table* table;

    //Manage Waiter States
    OrderState* orderState;
    ReceiveState* receiveState;
    ActionsState* actionsState;

    //Level variables management
    Level* level;

    //Generate random numbers
    std::random_device rd;
    int random;
    int maxNumberCustomers;
    sf::Clock clock;

    //BackGround;
    sf::Sprite background;
    //sf::Sprite table;

    //Text
    sf::Font font;
    sf::Text text;

    //Initialize all the game objects and attributes
    void initVariables();
    void initWaiter();
    void initChef();
    void initBackground();
    void initTables();
    void initStates();
    void initPosTables();
    void initMap();
    void initDishWasher();
    void initLevel();
    void setWaiterTexture(int waiterTexture);
    int numTables=6;
    int waiterTexture;

};


#endif //VIDEOGIOCO_GAME_H
