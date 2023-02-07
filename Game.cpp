//
// Created by Paolo Sbarzagli on 30/01/23.
//

#include "Game.h"

Game::Game() {
    initVariables();
    initWindow();
    initTexture();
    initBackground();
    initWaiter();
}

Game::~Game() {
    delete this->window;
    delete this->waiter;

    /*
    //Delete Textures
    for(auto &i : this->textures)
    {
        delete i.second;
    }
     */
}

void Game::update() {
    pollEvents();
    updateCollision();
    //this->updateMousePos();
}

void Game::render() {
    /*
     * Clear the window, draw the objects of the game for the related actions and placement, displays it.
     */
    this->window->clear();

    //Draw Game
    renderMap();

    this->waiter->render(*this->window);

    this->window->display();
}

void Game::initVariables() {
    this->window = nullptr;
}

void Game::initWindow() {
    /*
     * Initialize the window of the game with a specific size and a name on the toolbar
     * It also limits the speed rate of the computer in order to not overflow the game
     * and not disable the vertical synchronization
     */

    videoMode.width = 1164;
    videoMode.height = 882;
    this->window = new sf::RenderWindow(videoMode, "VideoGame");
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

const bool Game::getWindowIsOpen() {
    return this->window->isOpen();
}

void Game::pollEvents() {
    /*
     * Manage the events
     */
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                else
                    waiter->updateMovement(this->ev);
                break;
        }
    }

}

void Game::updateMousePos() {
    /*
     * Set the variable mousePos to the pixel in which the mouse is pointing (respect to the game window)
     */
    this->mousePos = sf::Mouse::getPosition(*this->window);
}

void Game::initWaiter() {
    this->waiter = new Waiter();
}


void Game::initTexture() {
    /*
     * Allocate space on the pointer for each specific instance.
     * Load the texture from the file
    */

    //Load the texture of the background
    this->textures["RestaurantMap"] = new sf::Texture;
    if(!textures["RestaurantMap"]->loadFromFile("../Textures/RestaurantMap.png"))
    {
        std::cout << "ERROR::GAME::CAN'T LOAD TEXTURE MAP FILE" << std::endl;
    }

    /*
    //Load the Appetizers
    this->textures["Appetizer1"] = new sf::Texture;
    if(!this->textures["Appetizer1"]->loadFromFile("../Textures/Appetizer1.png"))
        {
            std::cout << "ERROR::GAME::CAN'T LOAD TEXTURE FILE" << std::endl;
        }
    this->textures["Appetizer2"] = new sf::Texture;
    if(!this->textures["Appetizer2"]->loadFromFile("../Textures/Appetizer2.png"))
    {
        std::cout << "ERROR::GAME::CAN'T LOAD TEXTURE FILE" << std::endl;
    }
    this->textures["Appetizer3"] = new sf::Texture;
    if(!this->textures["Appetizer3"]->loadFromFile("../Textures/Appetizer3.png"))
    {
        std::cout << "ERROR::GAME::CAN'T LOAD TEXTURE FILE" << std::endl;
    }

    //Load the Main Courses
    this->textures["Main1"] = new sf::Texture;
    if(!this->textures["Main1"]->loadFromFile("../Textures/Main1.png"))
    {
        std::cout << "ERROR::GAME::CAN'T LOAD TEXTURE FILE" << std::endl;
    }
    this->textures["Main2"] = new sf::Texture;
    if(!this->textures["Main2"]->loadFromFile("../Textures/Main2.png"))
    {
        std::cout << "ERROR::GAME::CAN'T LOAD TEXTURE FILE" << std::endl;
    }
    this->textures["Main3"] = new sf::Texture;
    if(!this->textures["Main3"]->loadFromFile("../Textures/Main3.png"))
    {
        std::cout << "ERROR::GAME::CAN'T LOAD TEXTURE FILE" << std::endl;
    }
    this->textures["Main4"] = new sf::Texture;
    if(!this->textures["Main4"]->loadFromFile("../Textures/Main4.png"))
    {
        std::cout << "ERROR::GAME::CAN'T LOAD TEXTURE FILE" << std::endl;
    }
     */
}

std::map<std::string, sf::Texture *> &Game::getTextures() {
    return this->textures;
}

void Game::initBackground() {
    /*
     * Initialize the map texture and connect it to a sprite
     */

    this->background.setTexture(*this->textures["RestaurantMap"]);
    this->background.setScale(3.f,3.f);

}

void Game::renderMap() {
    this->window->draw(this->background);
}

void Game::updateCollision() {
    /*
     * Avoid the collision with the border of the map
     */

    //Left side of the map collision
    if(this->waiter->getBounds().left < 0.f)
    {
        this->waiter->setPositionW(0.f, this->waiter->getPosition().y);
    }

    //Upper side of the map collision
    if(this->waiter->getBounds().top < 0.f)
    {
        this->waiter->setPositionW(this->waiter->getPosition().x, 0.f);
    }

    //Right side of the map collision
    if(this->waiter->getBounds().left + this->waiter->getBounds().width >= this->window->getSize().x)
    {
        this->waiter->setPositionW(this->window->getSize().x - this->waiter->getBounds().width,
                                   this->waiter->getPosition().y);
    }

    //Bottom side of the map collision
    if(this->waiter->getBounds().top + this->waiter->getBounds().height >= this->window->getSize().y)
    {
        this->waiter->setPositionW(this->waiter->getPosition().x,
                                   this->window->getSize().y - this->waiter->getBounds().height);
    }
}



