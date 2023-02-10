//
// Created by Paolo Sbarzagli on 02/02/23.
//

#include "Map.h"

Map::Map() {
    this->kitchen = new Kitchen();
    this->washbasin = new Washbasin();

}

Map::~Map() {
    delete this->washbasin;
    delete this->kitchen;
    for(int i = 0; i < MAX_SIZE; i++)
    {
        delete this->table[i];
    }

}

Table *Map::getTable(int i) const {
    return this->table[i];
}

Kitchen *Map::getKitchen() const {
    return this->kitchen;
}

Washbasin *Map::getWashbasin() const {
    return this->washbasin;
}
