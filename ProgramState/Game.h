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
#include "EndGame.h"
#include "../Button.h"


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
    void updateInteractions();
    void updateReceivingCustomer();
    void updateOrderState();
    void updateTables();
    void updateTable();
    void updateButton();

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
    bool isFreeTable();

    //Method to manage the events
    void pollEvents();

    //Method that update the position of the mouse relative to the game window
    void updateMousePos();

    //Method to check if the window is still open, so if the game is running

    //Update the current level
    void updateLevel();
    void nextLevel();

    //Getter & Setter for the attributes
    std::shared_ptr<Map> getMap();
    std::shared_ptr<Waiter> getWaiter();
    Level* getLevel();
    std::vector<std::shared_ptr<Customer>>& getGroup();
    std::shared_ptr<Chef>& getChef();
    std::shared_ptr<Tray>& getTray();

private:
    //Group of textures uploaded in a container, each one is accessible by his own name
    //std::map<std::string, sf::Texture*> textures;
    //std::vector<Table> allTables;
    //
    sf::Vector2f mousePos;
    sf::Event ev;

    //GameCharacters and objects
    std::shared_ptr<Waiter> waiter;
    std::shared_ptr<GameCharacter> gc;
    std::shared_ptr<Chef> chef;
    std::shared_ptr<Map> map;
    std::shared_ptr<Kitchen> kitchen;
    std::shared_ptr<Counter> counter;
    std::shared_ptr<Washbasin> washbasin;
    std::shared_ptr<Customer> customer;
    std::vector<std::shared_ptr<Customer>> group;
    std::shared_ptr<DishWasher> dishWasher;
    //OrderState* orderState;
    //ReceivingCustomers* receivingCustomers;
    std::shared_ptr<BottomBar> bottomBar;
    //Table* table;
    std::shared_ptr<Tray> tray;

    //Manage Waiter States
    std::shared_ptr<OrderState> orderState;
    std::shared_ptr<ReceiveState> receiveState;
    std::shared_ptr<ActionsState> actionsState;

    //Level variables management
    Level* level;
    Score score;

    //Generate random numbers
    std::random_device rd;
    int random;
    sf::Clock clock;

    //BackGround;
    sf::Sprite background;
    //sf::Sprite table;

    //Text
    sf::Font font;
    sf::Text text;

    //Initialize all the game objects and attributes
    void initButton();
    void initWaiter();
    void initChef();
    void initBackground();
    void initTables();
    void initStates();
    void initTray();
    void initPosTables();
    void initMap();
    void initDishWasher();
    void initLevel();
    void setWaiterTexture();
    void gameOver();

    int numTables=6;
    int waiterTexture;
    std::unique_ptr<Button> button;

};


#endif //VIDEOGIOCO_GAME_H
