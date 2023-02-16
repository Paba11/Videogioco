//
// Created by Paolo Sbarzagli on 02/02/23.
//

#include "Map.h"

Map::Map() {
    this->kitchen = new Kitchen();
    this->washbasin = new Washbasin();
    //initSprites();
}

Map::~Map() {
    delete this->washbasin;
    delete this->kitchen;
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

Kitchen *Map::getKitchen() const {
    return this->kitchen;
}

Washbasin *Map::getWashbasin() const {
    return this->washbasin;
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
    entrance.setPosition(1235.f,820.f);
    entrance.setScale(4.f,3.f);
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
            trees[3].setPosition(1235,680);
    }
}

std::vector<Table>& Map::getAllTables() {
    return this->allTables;
}


