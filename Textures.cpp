//
// Created by Ettore Righi on 14/02/23.
//

#include <iostream>
#include "Textures.h"

Textures::Textures() {
    loadTexture();
}

Textures::~Textures() {

}

sf::Texture* Textures::getTexture(std::string name) {
    // See if we have already loaded this texture
    return textures[name];
}


 void Textures::loadTexture() {

    textures["RestaurantMap"] = new sf::Texture();
    if(!textures["RestaurantMap"]->loadFromFile("../Textures/new_textures/Mappa.png"))
    {
        std::cout << "ERROR::GAME::CAN'T LOAD TEXTURE MAP FILE" << std::endl;
    }
    textures["Table"] = new sf::Texture();
    if(!textures["Table"]->loadFromFile("../Textures/new_textures/Tavolo.png"))
    {
        std::cout << "ERROR::GAME::CAN'T LOAD TEXTURE TABLE FILE" << std::endl;
    }
     textures["Waiter"] = new sf::Texture();
     if (!this->textures["Waiter"]->loadFromFile("../Textures/new_textures/Waiter_Male_1.png"))
     {
         std::cout << "ERROR::WAITER::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Washbasin"] = new sf::Texture();
     if (!this->textures["Washbasin"]->loadFromFile("../Textures/new_Textures/Cucina.png"))
     {
         std::cout << "ERROR::Washbasin::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Kitchen"] = new sf::Texture();
     if (!this->textures["Kitchen"]->loadFromFile("../Textures/new_textures/Bancone.png"))
     {
         std::cout << "ERROR::KITCHEN::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
}

