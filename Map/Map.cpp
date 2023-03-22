//
// Created by Paolo Sbarzagli on 02/02/23.
//

#include "Map.h"

Map::Map() {
    this->kitchen = std::make_shared<Kitchen>();
    this->washbasin = std::make_shared<Washbasin>();
    this->entranceObj = new Entrance();
    this->counter = new Counter();
    this->isClose = IS_CLOSE_NOTHING;
    initSprites();
    //Temporary code
    this->entranceObj->setSprite(entrance);
    //TODO: DEFINE THE ENTRANCE AND MOVE HIS SPRITE IN THE PROPER CLASS

}

Map::~Map() {
    delete this->entranceObj;
    /*
    for(int i = 0; i < MAX_SIZE; i++)
    {
        delete this->table[i];
    }
    */
}

Table& Map::getTable(int i) {
    return this->allTables[i];
}

std::shared_ptr<Kitchen>& Map::getKitchen() {
    return kitchen;
}

std::shared_ptr<Washbasin>& Map::getWashbasin(){
    return washbasin;
}

/*
void Map::setTables(std::vector<Table> allTables) {

     * Assign the table stored inside the vector to the array pointer of tables

    for(int i=0; i < MAX_TABLES; i++)
    {
        if(i < allTables.size())
            this->table[i] = &allTables[i];
        else
            this->table[i] = nullptr;
    }
}
*/

void Map::initSprites() {

    for(int i=0; i < numTrees; i++){
        sf::Sprite tree;
        tree.setTexture(*this->texture->getTexture("Tree"));
        tree.setScale(2.f,2.f);
        trees.push_back(tree);
    }
    initPosTrees();

    entrance.setTexture(*this->texture->getTexture("Entrance"));
    entrance.setPosition(1275.f,900.f);
    entrance.setScale(1.f,1.f);

}

void Map::render(sf::RenderTarget &target) {
    for(int i=0; i < numTrees; i++)
        target.draw(this->trees[i]);

    target.draw(this->entrance);


}

void Map::initPosTrees() {

    for(int i=0; i < numTrees; i++){
        if(i==0)
            trees[i].setPosition(0,100);
        else if(i==1)
            trees[1].setPosition(970,100);
        else if(i==2)
            trees[2].setPosition(0,1020);
        else if(i==3)
            trees[3].setPosition(1235,710);
    }
}

std::vector<Table>& Map::getAllTables() {
    return allTables;
}

Entrance *Map::getEntrance() const {
    return entranceObj;
}

Table& Map::selectFreeTable() {
    if(!this->allTables.empty())
    {
    this->occupiedTables.push(this->allTables.back());
    this->allTables.pop_back();
    }
    else
    {
        //TODO: INSERT A SCREEN MESSAGE (ALL THE TABLES OCCUPIED)
    }

    return this->occupiedTables.back();
}

bool Map::distanceSpecificTable(Table *t, sf::Sprite& gc) {
    float dist;
    bool isCloseTable = false;

    dist = std::sqrt(std::pow(t->sprite.getPosition().x - gc.getPosition().x, 2) +
                     std::pow(t->sprite.getPosition().y - gc.getPosition().y, 2));

    if(dist <= 20)
    {
        isCloseTable = true;
    }

    return isCloseTable;
}

Entrance* Map::distanceEntrance(sf::Sprite& gc) {
    float dist;

    dist = std::sqrt(std::pow(this->entranceObj->getWelcomeSquare().getPosition().x - gc.getPosition().x, 2) +
                     std::pow(this->entranceObj->getWelcomeSquare().getPosition().y - gc.getPosition().y, 2));

    std::cout << "Entrance distance: " << dist << std::endl;

    if(dist <= 20)
    {
        this->isClose = IS_CLOSE_ENTRANCE;
    }
    return this->entranceObj;
}

const std::shared_ptr<Washbasin>& Map::distanceWashbasin(sf::Sprite& gc) {
    /*
     * Calculate the position of the waiter from the Washbasin
     */

    float dist;

    //std::cout << std::endl << " posX: " << w->getSprite().getPosition().x << " PosY: " <<
    //        w->getSprite().getPosition().y << std::endl;

    dist = std::sqrt(std::pow(this->washbasin->getSprite().getPosition().x - gc.getPosition().x, 2) +
                     std::pow(this->washbasin->getSprite().getPosition().y - gc.getPosition().y, 2));

    std::cout << "Washbasin dist: " << dist << std::endl;

    if(dist <= 200)
    {
        this->isClose = IS_CLOSE_DISHWASHER;
    }

    return washbasin;
}

const std::shared_ptr<Kitchen>& Map::distanceKitchen(sf::Sprite& gc) {


    float dist;

    dist = std::sqrt(std::pow(this->kitchen->getSprite().getPosition().x - gc.getPosition().x, 2) +
                     std::pow(this->kitchen->getSprite().getPosition().y - gc.getPosition().y, 2));

    std::cout << "Kitchen Dist: " << dist << std::endl;

    if(dist <= 200)
    {
        this->isClose = IS_CLOSE_KITCHEN;
    }

    return this->kitchen;
}

Table* Map::distanceTable(sf::Sprite& gc) {
    /*
     * Calculate the position of the waiter from the Tables
     */

    float dist;
    /*
    for(int i = 0; i < this->map->getAllTables().size(); i++)
    {
        std::cout << std::endl << "table: " << i << " position: " << this->map->getTable(i).getPosition().x
        << ", " << this->map->getTable(i).getPosition().y << std::endl;
    }
    */
    for(int i = 0; i < this->allTables.size() && this->isClose != IS_CLOSE_TABLE; i++)
    {

        this->table = &getTable(i);
        dist = std::sqrt(std::pow(table->sprite.getPosition().x - gc.getPosition().x, 2) +
                         std::pow(table->sprite.getPosition().y - gc.getPosition().y, 2));

        //std::cout << std::endl << "table " << i; //<< " posX: " << t->sprite.getPosition().x << " PosY:" <<
        // << t->sprite.getPosition().y << std::endl;
        //std::cout << " dist: " << dist << std::endl;

        if (dist <= 130 )
        {
            //std::cout << "dist <= 130 table: " << i << std::endl;
            //t = &this->map->getTable(i);
            this->isClose = IS_CLOSE_TABLE;
        }

    }
    return table;
}

Position Map::getIsClose() {
    return this->isClose;
}

void Map::setIsClose(Position pos) {
    this->isClose = pos;
}

Table *Map::getTableToPickUp() {
    return this->table;
}

sf::RectangleShape *Map::distanceDirtyDishes(sf::Sprite &gc) {

    float dist;

    dist = std::sqrt(std::pow(this->kitchen->getCounter()->getPlaceDirtyDishes().getPosition().x - gc.getPosition().x, 2) +
                     std::pow(this->kitchen->getCounter()->getPlaceDirtyDishes().getPosition().y - gc.getPosition().y, 2));

    std::cout << "Dirty Dish Dist: " << dist << std::endl;

    if(dist <= 200)
    {
        this->isClose = IS_CLOSE_DIRTY_DISHES;
    }

    return &this->kitchen->getCounter()->getPlaceDirtyDishes();
}

std::vector<sf::RectangleShape> Map::distanceChefDishes(sf::Sprite &gc) {

    float dist;
    int i=0;
    for (auto &it: this->kitchen->getCounter()->getPlaceChefDishes()){

        dist = std::sqrt(std::pow(this->kitchen->getCounter()->getPlaceChefDishes()[i].getPosition().x - gc.getPosition().x, 2) +
                         std::pow(this->kitchen->getCounter()->getPlaceChefDishes()[i].getPosition().y - gc.getPosition().y, 2));

        /*
        std::cout << "Chef Dish " << i <<" Dist: " << dist << std::endl;
         */
        i++;
    }
    /*
    if(dist <= 200)
    {
        this->isClose = IS_CLOSE_DIRTY_DISHES;
    }
    */ //TODO: create a new value for isClose
    return this->kitchen->getCounter()->getPlaceChefDishes();
}

bool Map::distanceInteractionSquare(sf::Sprite &gc, Table *t) {
    bool ret = false;
    float dist;
    std::cout << "Table num: " << t->getTavNum();
    dist = std::sqrt(std::pow(t->getInteractionSquare().getPosition().x - gc.getPosition().x, 2) +
                     std::pow(t->getInteractionSquare().getPosition().y - gc.getPosition().y, 2));

    std::cout << "Square distance: " << dist << std::endl;

    if(dist <= 30)
    {
        this->isClose = IS_CLOSE_TABLE;
        ret = true;
    }

    return ret;
}


