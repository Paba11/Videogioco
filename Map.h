//
// Created by Paolo Sbarzagli on 02/02/23.
//

#ifndef VIDEOGIOCO_MAP_H
#define VIDEOGIOCO_MAP_H

#include "Washbasin.h"
#include "Kitchen.h"
#include "Entrance.h"
#include "Table.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#define MAX_SIZE 10

class Map {
public:
    //Constructor & Destructor
    Map();
    ~Map();

    //Getters & Setters
    Table& getTable(int i);
    std::vector<Table>& getAllTables();
    Kitchen* getKitchen() const;
    Washbasin* getWashbasin() const;
    Entrance* getEntrance() const;
    Table& selectFreeTable();
    //void setTables(std::vector<Table> allTable);

    //Initialize variables, update and render
    void initTrees();
    void initSprites();
    void render(sf::RenderTarget& target);
    void initPosTrees();
    std::vector <sf::Sprite> trees;
    int numTrees = 4;


private:
    sf::Sprite entrance;

    //Elements of the map
    std::vector<Table> allTables;
    std::queue<Table> occupiedTables;
    Washbasin* washbasin;
    Kitchen* kitchen;
    Entrance* entranceObj;
    Textures* texture = new Textures;
};


#endif //VIDEOGIOCO_MAP_H
