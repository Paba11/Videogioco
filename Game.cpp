//
// Created by Paolo Sbarzagli on 30/01/23.
//

#include "Game.h"

Game::Game() {
    initVariables();
    initWindow();
    initTexture();
    initBackground();
    initMap();
    initWaiter();
    initTables();
    initPosTables();
    initTexture();
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
    this->waiter->update();
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

    videoMode.width = 1298;
    videoMode.height = 1344;
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
                else {
                    //this->waiter->interact(this->ev, *this->map);
                }
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
    this->waiter->setMap(this->map);
}


// void Game::initTexture() {
    /*
     * Allocate space on the pointer for each specific instance.
     * Load the texture from the file
    */

    //Load the texture of the background
 /*   this->textures["RestaurantMap"] = new sf::Texture;
    if(!textures["RestaurantMap"]->loadFromFile("../Textures/new_textures/Mappa.png"))
    {
        std::cout << "ERROR::GAME::CAN'T LOAD TEXTURE MAP FILE" << std::endl;
    }
    this->textures["Table"] = new sf::Texture;
    if(!textures["Table"]->loadFromFile("../Textures/new_textures/Tavolo.png"))
    {
        std::cout << "ERROR::GAME::CAN'T LOAD TEXTURE TABLE FILE" << std::endl;
    }
*/
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
// }


void Game::initBackground() {
    /*
     * Initialize the map texture and connect it to a sprite
     */

    this->background.setTexture(*this->texture->getTexture("RestaurantMap"));
    this->background.setScale(2.f,2.f);

}

void Game::renderMap() {
    this->window->draw(this->background);
    this->kitchen->render(*this->window);
    this->washbasin->render(*this->window);
    for(int i=0;i<numTables;i++) {
        this->window->draw(this->allTable[i].sprite);
        for(int j=0; j<4;j++)
            this->window->draw(this->allTable[i].stoolTable[j].sprite);
    }
}

void Game::updateCollision() {
    /*
     * Avoid the collision with the border of the map
     */
    windowsCollision();
    collision();



}

void Game::initTables() {

    for(int i=0; i<numTables; i++){
      Table t;
      //Stool s;
      t.sprite.setTexture(*this->texture->getTexture("Table"));
      for(int j=0; j<4; j++)
          t.stoolTable[j].sprite.setTexture(*this->texture->getTexture("Stool"));
     // s.sprite.setTexture(*this->texture->getTexture("Stool"));
     // t.stoolTable.push_back(s);
      allTable.push_back(t);
  }


}

void Game::initPosTables() {

    allTable[0].sprite.setPosition(85,270);
    allTable[0].posStool(85,270);
    allTable[1].sprite.setPosition(85,540);
    allTable[1].posStool(85,540);
    allTable[2].sprite.setPosition(85,810);
    allTable[2].posStool(85,810);
    allTable[3].sprite.setPosition(490,270);
    allTable[3].posStool(490,270);
    allTable[4].sprite.setPosition(490,540);
    allTable[4].posStool(490,540);
    allTable[5].sprite.setPosition(490,810);
    allTable[5].posStool(490,810);
    for(int i=0; i<numTables; i++)
        allTable[i].sprite.setScale(2, 2);


}

void Game::windowsCollision() {

    if(this->waiter->getBounds().left < 0.f)
    {
        this->waiter->setPositionW(0.f, this->waiter->getPosition().y);
    }

    //Upper side of the map collision
    if(this->waiter->getBounds().top < 85.f)
    {
        this->waiter->setPositionW(this->waiter->getPosition().x, 85.f);
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

void Game::collision() {

    for(int i=0; i < numTables; i++){
        if(this->waiter->getGlobalHitbox().intersects(allTable[i].sprite.getGlobalBounds()))
           collisionManagement();
        for(int j=0; j < 4; j++){
            if(this->waiter->getGlobalHitbox().intersects(allTable[i].stoolTable[j].sprite.getGlobalBounds()))
                collisionManagement();
        }

    }
    if(this->waiter->getGlobalHitbox().intersects(this->kitchen->getBounds()))
        collisionManagement();


}

void Game::collisionManagement() {

    sf::Vector2f prePosition;
    prePosition = this->waiter->getPosition();
    if (this->waiter->getState() == MOVING_DOWN) {
        this->waiter->validMovement["Down"] = false;
        prePosition.y--;
    }
    else if (this->waiter->getState() == MOVING_UP) {
        this->waiter->validMovement["Up"] = false;
        prePosition.y++;
    }
    else if (this->waiter->getState() == MOVING_LEFT){
        this->waiter->validMovement["Left"] = false;
        prePosition.x++;
    }

    else if(this->waiter->getState() == MOVING_RIGHT) {
        this->waiter->validMovement["Right"] = false;
        prePosition.x--;
    }
    this->waiter->setPositionW(prePosition);

}

void Game::initMap() {
    this->map = new Map();
    this->map->setTables(this->allTable);
    this->kitchen = this->map->getKitchen();
    this->washbasin = this->map->getWashbasin();
}

void Game::initTexture() {
    this->texture = new Textures();
}







