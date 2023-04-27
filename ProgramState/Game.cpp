//
// Created by Paolo Sbarzagli on 30/01/23.
//

#include "Game.h"

Game::Game(sf::RenderWindow* window, std::stack <ProgramState*>* states, int waiterTexture) : ProgramState(window, states) {
    initLevel();
    this->waiterTexture = waiterTexture;
    initButton();
    initBackground();
    initMap();
    initTables();
    initPosTables();
    initWaiter();
    initStates();
    initTray();
    initChef();
    initDishWasher();
    generateCustomers();
    //initTexture();
    this->ev.type = sf::Event::Closed;

}

Game::~Game() {

}

void Game::update() {
    pollEvents();
    generateCustomers();
    updateCollision();
    updateCustomers();
    updateTables();
    updateInteractions();
    map->getEntrance()->updateBox();
    map->getKitchen()->update();
    map->getWashbasin()->update();
    actionsState->getTray()->update();
    updateTable();
    waiter->update();
    dishWasher->update();
    chef->update();
    score.update();
    level->update();
    checkQuit();
    updateButton();
    if(score.getQuit())
        gameOver();
    //this->updateMousePos();
}

void Game::render(sf::RenderTarget* target) {
    /*
     * Clear the window, draw the objects of the game for the related actions and placement, displays it.
     */
    window->clear();

    //Draw Game
    renderMap();

    map->getEntrance()->renderBarrier(*this->window,1);
    chef->render(*this->window);
    chef->renderBar(*this->window);
    dishWasher->render(*this->window);
    if(map->getEntrance()->getIsCustomer()) {
        for (auto & it : receiveState->getCustomers())
        {
            window->draw(it.sprite);
        }
    }
    map->getEntrance()->renderBarrier(*this->window,2);    //this->dishWasher->render(*this->window);
    waiter->render(*this->window);
    tray->render(*this->window);
    bottomBar->render(*this->window);
    button->render(*this->window);
    window->display();
}

void Game::initButton() {

    if(!this->font.loadFromFile("../Font/8-bit Arcade In.ttf")){
        std::cout << "ERROR::CAN'T LOAD FONT FILE" << std::endl;
    }

    button = std::make_unique<Button>(0,0,150,50,&this->font, "QUIT",
                                      sf::Color(70,70,70,200),
                                      sf::Color(150,150,150,255),
                                      sf::Color(20,20,20,200));
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
                if (ev.key.code == sf::Keyboard::Escape)
                    this->quit = true;
                else if (ev.key.code == sf::Keyboard::J || ev.key.code == sf::Keyboard::K
                    || ev.key.code == sf::Keyboard::L)
                {
                    //std::cout<< "PollEvent" << std::endl;
                    waiter->interact(map, ev);
                }
                break;
        }
    }
}

void Game::updateMousePos() {
    /*
     * Set the variable mousePos to the pixel in which the mouse is pointing (respect to the game window)
     */
    mousePos = window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void Game::initWaiter() {
    waiter = std::make_shared<Waiter>();
    setWaiterTexture(waiterTexture);
    gc = waiter;
}


void Game::initBackground() {
    /*
     * Initialize the map texture and connect it to a sprite
     */

    background.setTexture(*this->textures->getTexture("RestaurantMap"));
    background.setScale(2.f,2.f);

}

void Game::renderMap() {
    window->draw(this->background);
    kitchen->render(*this->window);
    counter->render(*this->window);
    washbasin->render(*this->window);
    map->getEntrance()->render(*this->window);
    map->render(*this->window);
    for(int i=0;i<numTables;i++) {
        for(int j=0; j<4;j++)
            window->draw(map->getAllTables()[i].getStoolTable()[j].sprite);

        map->getAllTables()[i].render(*this->window);
    }
}

void Game::updateCollision() {
    /*
     * Avoid the collision with the border of the map
     */
    windowsCollision();
    collision();
    if(waiter->getIsReceived())
    {
        customerCollision();
    }
    //if(this->waiter->getState() == RECEIVING_CUSTOMERS)
}

void Game::initTables() {

    for(int i=0; i<numTables; i++){
      Table t;
      //Stool s;
      t.setTavNum(i);
      t.sprite.setTexture(*this->textures->getTexture("Table"));
      score.setTable(&t);
      t.setDifficulty(level->getDifficulty());
      for(int j=0; j<4; j++)
          t.getStoolTable()[j].sprite.setTexture(*this->textures->getTexture("Stool"));
     // s.sprite.setTexture(*this->texture->getTexture("Stool"));
     // t.stoolTable.push_back(s);
      map->getAllTables().push_back(t);
  }


}

void Game::initPosTables() {

    map->getAllTables()[0].sprite.setPosition(140,320);    //60 64
    map->getAllTables()[0].posStool(80,270); //80 270
    map->getAllTables()[1].sprite.setPosition(140,590);
    map->getAllTables()[1].posStool(85,540);
    map->getAllTables()[2].sprite.setPosition(140,860);
    map->getAllTables()[2].posStool(85,810);
    map->getAllTables()[3].sprite.setPosition(550,320);
    map->getAllTables()[3].posStool(490,270);
    map->getAllTables()[4].sprite.setPosition(550,590);
    map->getAllTables()[4].posStool(490,540);
    map->getAllTables()[5].sprite.setPosition(550,860);
    map->getAllTables()[5].posStool(490,810);
    for(int i=0; i<numTables; i++) {
        map->getAllTables()[i].setTable();
        map->getAllTables()[i].sprite.setScale(2, 2);
        map->getAllTables()[i].initBar();
    }
}

void Game::windowsCollision() {

    //Left side of the map collision
    if(waiter->getBounds().left < 0.f)
    {
        collisionManagement();
    }

    //Upper side of the map collision
    if(waiter->getBounds().top < 85.f)
    {
        collisionManagement();
    }

    //Right side of the map collision
    if(waiter->getBounds().left + waiter->getBounds().width >= window->getSize().x)
    {
        collisionManagement();
    }

    //Bottom side of the map collision
    if(waiter->getBounds().top + waiter->getBounds().height >= window->getSize().y)
    {
        collisionManagement();
    }

}

void Game::collision() {

    for(int i=0; i < numTables; i++){
        if(waiter->getGlobalHitbox().intersects(map->getAllTables()[i].sprite.getGlobalBounds()))
           collisionManagement();
        for(int j=0; j < 4; j++){
            if(waiter->getGlobalHitbox().intersects(map->getAllTables()[i].getStoolTable()[j].sprite.getGlobalBounds()))
                collisionManagement();
        }

    }
    if(waiter->getGlobalHitbox().intersects(counter->getBounds()))
        collisionManagement();
    for(int i=0; i< map->numTrees; i++){
        if(waiter->getGlobalHitbox().intersects(map->trees[i].getGlobalBounds()))
            collisionManagement();
    }

    if(waiter->getPosition().y <= 230)
        collisionManagement();



}

void Game::collisionManagement() {

    sf::Vector2f prePosition;
    prePosition = waiter->getPosition();
    if (waiter->getMove() == Move::MOVING_DOWN) {
        waiter->validMovement["Down"] = false;
        prePosition.y--;
    }
    else if (waiter->getMove() == Move::MOVING_UP) {
        waiter->validMovement["Up"] = false;
        prePosition.y++;
    }
    else if (waiter->getMove() == Move::MOVING_LEFT){
        waiter->validMovement["Left"] = false;
        prePosition.x++;
    }

    else if(waiter->getMove() == Move::MOVING_RIGHT) {
        waiter->validMovement["Right"] = false;
        prePosition.x--;
    }
    waiter->setPositionW(prePosition);

}

void Game::initMap() {
    map = std::make_shared<Map>();
    kitchen.reset();
    kitchen = map->getKitchen();
    washbasin.reset();                      //fixme controllare
    washbasin = map->getWashbasin();
    counter.reset();
    counter = map->getKitchen()->getCounter();
    bottomBar.reset();
    bottomBar = map->getKitchen()->getBottomBar();
}

void Game::endState() {

    std::cout << "Exit from Game" << std::endl;
}

void Game::initDishWasher() {
    dishWasher = std::make_shared<DishWasher>();
    dishWasher->setWashbasin(map->getWashbasin());
}

void Game::initChef() {

    chef = std::make_shared<Chef>();
    chef->setKitchen(kitchen);

}

void Game::generateCustomers() {
    if(clock.getElapsedTime().asSeconds() >= level->getCustomerArrival()
    && !map->getEntrance()->getIsCustomer() && isFreeTable())
    {
        sf::Vector2f dist = map->getEntrance()->getWelcomeSquare().getPosition();
        receiveState.reset();
        receiveState = std::make_shared<ReceiveState>(map);
        std::cout << "crea nuovo receive state" << std::endl;
        waiter->setReceiveState(receiveState);
        std::cout << "Assegna receive state" << std::endl;
        generateRandom();
        while(random > 0)
        {
            std::cout << "Generating a customer" << std::endl;
            customer = std::make_shared<Customer>(dist);
            receiveState->getCustomers().push_back(*this->customer);
            group.push_back(customer); //Puntatore ai customers
            level->addTotalCustomerNumber();
            receiveState->setGeneratedCustomers(random, level->getTotalCustomerNumber());
            random--;
        }
        map->getEntrance()->setIsCustomer(true);
        map->getEntrance()->setCustomerReceived(true);
        //this->receivingCustomers->enterTheRestaurant();
        clock.restart();
        waiter->receivingTimer.restart();
    }
}

void Game::generateRandom() {
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 4);
    random = distrib(gen);
}

void Game::initLevel() {
    level = new Level();
    clock.restart();
}

void Game::nextLevel() {
    Lvl current = level->getLevel();
    switch(current)
    {
        case Lvl::FIRST:
            level->setLevel(Lvl::SECOND);
            break;
        case Lvl::SECOND:
            level->setLevel(Lvl::THIRD);
            break;
        case Lvl::THIRD:
            level->setLevel(Lvl::GAME_END);
            break;
    }
    clock.restart();
}

void Game::updateLevel() {
    /*
     * Update the variables of the level
     */
}

void Game::customerCollision() {
    for(auto & i : group)
    {
        for(int x = 0; x < numTables; x++){
            if(i->getGlobalHitbox().intersects(map->getAllTables()[x].sprite.getGlobalBounds()))
                customerCollisionManagement();
            for(int j=0; j < 4; j++){
                if(waiter->getGlobalHitbox().intersects(map->getAllTables()[x].getStoolTable()[j].sprite.getGlobalBounds()))
                    customerCollisionManagement();
            }

        }
        if(i->getGlobalHitbox().intersects(counter->getBounds()))
            customerCollisionManagement();
        for(int x = 0; x < map->numTrees; x++){
            if(i->getGlobalHitbox().intersects(map->trees[x].getGlobalBounds()))
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
    for (auto & it : receiveState->getCustomers())
    {
        it.update();
    }
}

void Game::setWaiterTexture(int waiterTexture) {
    if(waiterTexture == 0)
        waiter->initTexture(textures->getTexture("Waiter"));
    else
        waiter->initTexture(textures->getTexture("Waiter_Female_1"));
}

void Game::initStates() {
    receiveState = std::make_shared<ReceiveState>(map);
    orderState = std::make_shared<OrderState>(map->getAllTables().front());
    actionsState = std::make_shared<ActionsState>(map);
    waiter->initStates(actionsState, receiveState, orderState);
}

void Game::updateReceivingCustomer() {
    if(waiter->getState() == Actions::RECEIVING_CUSTOMERS)
    {
        if(receiveState->getIsSit())
            receiveState.reset();
        else
        {
            receiveState->update(gc);
        }
    }
}

void Game::updateInteractions() {
    updateReceivingCustomer();
    updateOrderState();
}

void Game::updateOrderState() {
    if(waiter->getState() == Actions::TAKING_ORDER)
    {

    }
}

void Game::updateTables() {
    for(auto & it : map->getAllTables())
    {
        it.update();
        it.setDifficulty(level->getDifficulty());
        if(it.getIsOccupied())
        {
            for(auto & i: it.getCustomers())
                i.update();
        }
        if(it.getIsNotSatisfied())
        {
            score.addNotSatisfied();
            it.setIsNotSatisfied(false);
        }
    }
}

void Game::updateTable() {

    for(int i = 0; i < numTables; i++){
        map->getAllTables()[i].updateBox();
    }

}

bool Game::isFreeTable() {
    bool free = false;
    for(auto & i: map->getAllTables())
    {
        if(!i.getIsOccupied())
        {
            free = true;
        }
    }
    return free;
}


void Game::initTray() {

    tray = std::make_shared<Tray>();
    actionsState->setTray(tray);
}

void Game::gameOver() {
    quit = true;
    this->states->push(new EndGame(this->window, this->states, score.getTotalPoints()));
}

void Game::updateButton() {
    updateMousePos();
    button->update(mousePos);

    if(button->isPressed())
        gameOver();
}








