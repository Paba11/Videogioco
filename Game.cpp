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
    delete this->map;
    delete this->customer;
    delete this ->dish;

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
                    //this->waiter->updateMovement();
                    //this->waiter->interact(this->map);
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
    this->map->render(*this->window);
    for(int i=0;i<numTables;i++) {
        this->window->draw(this->map->getAllTables()[i].sprite);
        for(int j=0; j<4;j++)
            this->window->draw(this->map->getAllTables()[i].stoolTable[j].sprite);
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
      this->map->getAllTables().push_back(t);
  }


}

void Game::initPosTables() {

    this->map->getAllTables()[0].sprite.setPosition(85,270);
    this->map->getAllTables()[0].posStool(85,270);
    this->map->getAllTables()[1].sprite.setPosition(85,540);
    this->map->getAllTables()[1].posStool(85,540);
    this->map->getAllTables()[2].sprite.setPosition(85,810);
    this->map->getAllTables()[2].posStool(85,810);
    this->map->getAllTables()[3].sprite.setPosition(490,270);
    this->map->getAllTables()[3].posStool(490,270);
    this->map->getAllTables()[4].sprite.setPosition(490,540);
    this->map->getAllTables()[4].posStool(490,540);
    this->map->getAllTables()[5].sprite.setPosition(490,810);
    this->map->getAllTables()[5].posStool(490,810);
    for(int i=0; i<numTables; i++)
        this->map->getAllTables()[i].sprite.setScale(2, 2);

}

void Game::windowsCollision() {

    //Left side of the map collision
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
        if(this->waiter->getGlobalHitbox().intersects(this->map->getAllTables()[i].sprite.getGlobalBounds()))
           collisionManagement();
        for(int j=0; j < 4; j++){
            if(this->waiter->getGlobalHitbox().intersects(this->map->getAllTables()[i].stoolTable[j].sprite.getGlobalBounds()))
                collisionManagement();
        }

    }
    if(this->waiter->getGlobalHitbox().intersects(this->kitchen->getBounds()))
        collisionManagement();
    for(int i=0; i< map->numTrees; i++){
        if(this->waiter->getGlobalHitbox().intersects(this->map->trees[i].getGlobalBounds()))
            collisionManagement();
    }



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
    this->kitchen = this->map->getKitchen();
    this->washbasin = this->map->getWashbasin();
}

void Game::initTexture() {
    this->texture = new Textures();
}





