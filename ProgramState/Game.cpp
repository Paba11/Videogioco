//
// Created by Paolo Sbarzagli on 30/01/23.
//

#include "Game.h"

Game::Game(sf::RenderWindow* window, std::stack <ProgramState*>* states, int waiterTexture) : ProgramState(window, states) {
    initLevel();
    this->waiterTexture = waiterTexture;
    initVariables();
    initBackground();
    initMap();
    initTables();
    initPosTables();
    initWaiter();
    initStates();
    initChef();
    initDishWasher();
    generateCustomers();
    //initTexture();
    this->ev.type = sf::Event::Closed;

}

Game::~Game() {
    delete this->waiter;
    delete this->chef;
    delete this->map;
    delete this->customer;
    //delete this->dish;    //TODO: add the dishes
    delete this->counter;
    delete this->dishWasher;

    //FIXME check all pointer

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
    generateCustomers();
    updateCollision();
    updateCustomers();
    updateTables();
    updateInteractions();
    this->map->getEntrance()->updateBox();
    updateTable();
    this->waiter->update();
    this->dishWasher->update();
    this->chef->update();
    this->checkQuit();

    //this->updateMousePos();
}

void Game::render(sf::RenderTarget* target) {
    /*
     * Clear the window, draw the objects of the game for the related actions and placement, displays it.
     */
    this->window->clear();

    //Draw Game
    renderMap();

    this->map->getEntrance()->renderBarrier(*this->window,1);
    this->chef->render(*this->window);
    this->dishWasher->render(*this->window);
    if(this->map->getEntrance()->getIsCustomer()) {
        for (auto & it : this->receiveState->getCustomers())
        {
            this->window->draw(it.sprite);
        }
    }
    this->map->getEntrance()->renderBarrier(*this->window,2);    //this->dishWasher->render(*this->window);
    this->waiter->render(*this->window);
    this->window->display();
}

void Game::initVariables() {

    this->maxNumberCustomers = this->level->getTotalCustomerNumber();
    this->bottomBar = new BottomBar();
    //initWaiter();
    //initChef();

}


void Game::pollEvents() {
    /*
     * Manage the events
     */
    //FIXME check after git update
    while (this->window->pollEvent(this->ev))
    {


        switch (this->ev.type)
        {
            case sf::Event::Closed:
                this->quit = true;
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->quit = true;
                else if (this->ev.key.code == sf::Keyboard::J || this->ev.key.code == sf::Keyboard::K
                    || this->ev.key.code == sf::Keyboard::L)
                {
                    //std::cout<< "PollEvent" << std::endl;
                    this->waiter->interact(this->map, this->ev);
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
    setWaiterTexture(this->waiterTexture);
}


void Game::initBackground() {
    /*
     * Initialize the map texture and connect it to a sprite
     */

    this->background.setTexture(*this->textures->getTexture("RestaurantMap"));
    this->background.setScale(2.f,2.f);

}

void Game::renderMap() {
    this->window->draw(this->background);
    this->kitchen->render(*this->window);
    this->counter->render(*this->window);
    this->washbasin->render(*this->window);
    this->bottomBar->render(*this->window);
    this->map->getEntrance()->render(*this->window);
    this->map->render(*this->window);
    for(int i=0;i<numTables;i++) {
        this->map->getAllTables()[i].render(*this->window);
        for(int j=0; j<4;j++)
            this->window->draw(this->map->getAllTables()[i].getStoolTable()[j].sprite);
    }
}

void Game::updateCollision() {
    /*
     * Avoid the collision with the border of the map
     */
    windowsCollision();
    collision();
    if(this->waiter->getIsReceived())
    {
        customerCollision();
    }
    //if(this->waiter->getState() == RECEIVING_CUSTOMERS)
}

void Game::initTables() {

    for(int i=0; i<numTables; i++){
      Table t;
      //Stool s;
      t.sprite.setTexture(*this->textures->getTexture("Table"));
      for(int j=0; j<4; j++)
          t.getStoolTable()[j].sprite.setTexture(*this->textures->getTexture("Stool"));
     // s.sprite.setTexture(*this->texture->getTexture("Stool"));
     // t.stoolTable.push_back(s);
      this->map->getAllTables().push_back(t);
  }


}

void Game::initPosTables() {

    this->map->getAllTables()[0].sprite.setPosition(140,334);    //60 64
    this->map->getAllTables()[0].posStool(80,270); //80 270
    this->map->getAllTables()[1].sprite.setPosition(140,604);
    this->map->getAllTables()[1].posStool(85,540);
    this->map->getAllTables()[2].sprite.setPosition(140,874);
    this->map->getAllTables()[2].posStool(85,810);
    this->map->getAllTables()[3].sprite.setPosition(550,334);
    this->map->getAllTables()[3].posStool(490,270);
    this->map->getAllTables()[4].sprite.setPosition(550,604);
    this->map->getAllTables()[4].posStool(490,540);
    this->map->getAllTables()[5].sprite.setPosition(550,874);
    this->map->getAllTables()[5].posStool(490,810);
    for(int i=0; i<numTables; i++) {
        this->map->getAllTables()[i].setTable();
        this->map->getAllTables()[i].sprite.setScale(2, 2);
    }
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
            if(this->waiter->getGlobalHitbox().intersects(this->map->getAllTables()[i].getStoolTable()[j].sprite.getGlobalBounds()))
                collisionManagement();
        }

    }
    if(this->waiter->getGlobalHitbox().intersects(this->counter->getBounds()))
        collisionManagement();
    for(int i=0; i< map->numTrees; i++){
        if(this->waiter->getGlobalHitbox().intersects(this->map->trees[i].getGlobalBounds()))
            collisionManagement();
    }



}

void Game::collisionManagement() {

    sf::Vector2f prePosition;
    prePosition = this->waiter->getPosition();
    if (this->waiter->getMove() == Move::MOVING_DOWN) {
        this->waiter->validMovement["Down"] = false;
        prePosition.y--;
    }
    else if (this->waiter->getMove() == Move::MOVING_UP) {
        this->waiter->validMovement["Up"] = false;
        prePosition.y++;
    }
    else if (this->waiter->getMove() == Move::MOVING_LEFT){
        this->waiter->validMovement["Left"] = false;
        prePosition.x++;
    }

    else if(this->waiter->getMove() == Move::MOVING_RIGHT) {
        this->waiter->validMovement["Right"] = false;
        prePosition.x--;
    }
    this->waiter->setPositionW(prePosition);

}

void Game::initMap() {
    this->map = new Map();
    this->kitchen = this->map->getKitchen();
    this->washbasin = this->map->getWashbasin();
    this->counter = this->map->getKitchen()->getCounter();
}

void Game::endState() {

    std::cout << "Exit from Game" << std::endl;
}

void Game::initDishWasher() {
    this->dishWasher = new DishWasher();
    this->dishWasher->setWashbasin(*this->map->getWashbasin());
}

void Game::initChef() {

    this->chef = new Chef();
    this->chef->setKitchen(this->kitchen);

}

void Game::generateCustomers() {
    if(clock.getElapsedTime().asSeconds() >= level->getCustomerArrival()
    && !map->getEntrance()->getIsCustomer() && level->getTotalCustomerNumber() > 0)
    {
        sf::Vector2f dist = map->getEntrance()->getWelcomeSquare().getPosition();
        receiveState = std::make_shared<ReceiveState>(map);
        waiter->setReceiveState(receiveState);
        generateRandom();
        while(this->random > 0)
        {
            std::cout << "Generating a customer" << std::endl;
            this->customer = new Customer(dist);
            this->receiveState->getCustomers().push_back(*this->customer);
            this->group.push_back(this->customer); //Puntatore ai customers
            this->level->reduceTotalCustomerNumber();
            this->receiveState->setGeneratedCustomers(random, this->maxNumberCustomers - this->level->getTotalCustomerNumber());
            this->random--;
        }
        std::cout << "Total customers left: " << this->level->getTotalCustomerNumber() << std::endl;
        this->map->getEntrance()->setIsCustomer(true);
        this->map->getEntrance()->setCustomerReceived(true);
        //this->receivingCustomers->enterTheRestaurant();
        this->clock.restart();
    }
}

void Game::generateRandom() {
    std::mt19937 gen(this->rd());
    std::uniform_int_distribution<> distrib(1, 4);
    this->random = distrib(gen);
}

void Game::initLevel() {
    this->level = new Level();
    this->clock.restart();
}

void Game::nextLevel() {
    this->level->setIsPassed(false);
    Lvl current = this->level->getLevel();
    switch(current)
    {
        case FIRST:
            this->level->setLevel(SECOND);
        case SECOND:
            this->level->setLevel(THIRD);
        case THIRD:
            this->level->setLevel(GAME_END);
    }
    this->clock.restart();
}

void Game::updateLevel() {
    /*
     * Update the variables of the level
     */
}

void Game::customerCollision() {
    for(auto & i : this->group)
    {
        for(int x = 0; x < numTables; x++){
            if(i->getGlobalHitbox().intersects(this->map->getAllTables()[x].sprite.getGlobalBounds()))
                customerCollisionManagement();
            for(int j=0; j < 4; j++){
                if(this->waiter->getGlobalHitbox().intersects(this->map->getAllTables()[x].getStoolTable()[j].sprite.getGlobalBounds()))
                    customerCollisionManagement();
            }

        }
        if(i->getGlobalHitbox().intersects(this->counter->getBounds()))
            customerCollisionManagement();
        for(int x = 0; x < map->numTrees; x++){
            if(i->getGlobalHitbox().intersects(this->map->trees[x].getGlobalBounds()))
                customerCollisionManagement();
        }
    }
}

void Game::customerCollisionManagement() {

    sf::Vector2f prePosition;
    for(auto & i : this->group)
    {
        prePosition = i->getPosition();
        if (i->getMovingStatus() == Move::MOVING_DOWN) {               //Confront the move of the waiter because it moves in the same direction
            i->validMovement["Down"] = false;
            prePosition.y--;
        } else if (i->getMovingStatus() == Move::MOVING_UP) {
            i->validMovement["Up"] = false;
            prePosition.y++;
        } else if (i->getMovingStatus() == Move::MOVING_LEFT) {
            i->validMovement["Left"] = false;
            prePosition.x++;
        } else if (i->getMovingStatus() == Move::MOVING_RIGHT) {
            i->validMovement["Right"] = false;
            prePosition.x--;
        }
        i->setPositionW(prePosition);
    }
}

std::shared_ptr<ReceiveState> Game::getReceiveState() {
    return this->receiveState;
}


void Game::updateCustomers() {
    for (auto & it : this->receiveState->getCustomers())
    {
        it.update();
    }
}

void Game::setWaiterTexture(int waiterTexture) {
    if(waiterTexture == 0)
        this->waiter->initTexture(this->textures->getTexture("Waiter"));
    else
        this->waiter->initTexture(this->textures->getTexture("Waiter_Female_1"));
}

void Game::initStates() {
    receiveState = std::make_shared<ReceiveState>(map);
    orderState = std::make_shared<OrderState>(map->getAllTables().front());
    actionsState = std::make_shared<ActionsState>(map);
    waiter->initStates(actionsState, receiveState, orderState);
}

void Game::updateReceivingCustomer() {
    if(this->waiter->getState() == Actions::RECEIVING_CUSTOMERS)
    {
        this->receiveState->update(*this->waiter);
    }
}

void Game::updateInteractions() {
    updateReceivingCustomer();
    updateOrderState();
}

void Game::updateOrderState() {
    if(this->waiter->getState() == Actions::TAKING_ORDER)
    {
        this->orderState->update(*this->waiter);
    }
}

void Game::updateTables() {
    for(auto & it : this->map->getAllTables())
    {
        it.update();
        if(it.getState() == TableState::WAITING_TO_ORDER && !it.getIsReady())
        {
            this->orderState = std::make_shared<OrderState>(it);
            this->waiter->setOrderState(this->orderState);
            it.setIsReady(true);
        }
    }
}

void Game::updateTable() {

    for(int i = 0; i < numTables; i++){
        if(map->getAllTables()[i].getChosenTable())
            map->getAllTables()[i].updateBox();
    }


}








