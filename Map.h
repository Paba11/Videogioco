//
// Created by Paolo Sbarzagli on 02/02/23.
//

#ifndef VIDEOGIOCO_MAP_H
#define VIDEOGIOCO_MAP_H

#include "Washbasin.h"
#include "Kitchen.h"
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
    Kitchen* getKitchen() const;
    Washbasin* getWashbasin() const;
    //void setTables(std::vector<Table> allTable);
    std::vector<Table>& getAllTables();
    void initTrees();
    void initSprites();
    void render(sf::RenderTarget& target);
    void initPosTrees();
    std::vector <sf::Sprite> trees;
    int numTrees = 4;


private:
    sf::Sprite entrance;

    //Elements of the map
    //Table* table[MAX_SIZE];
    std::vector<Table> allTables;
    Washbasin* washbasin;
    Kitchen* kitchen;
    Textures* texture = new Textures;

};


#endif //VIDEOGIOCO_MAP_H
