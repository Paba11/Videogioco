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
     if (!this->textures["Washbasin"]->loadFromFile("../Textures/new_Textures/Lavabo.png"))
     {
         std::cout << "ERROR::Washbasin::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Kitchen"] = new sf::Texture();
     if (!this->textures["Kitchen"]->loadFromFile("../Textures/new_textures/Cucina.png"))
     {
         std::cout << "ERROR::KITCHEN::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Stool"] = new sf::Texture();
     if (!this->textures["Stool"]->loadFromFile("../Textures/new_textures/Sgabello Rosso.png"))
     {
         std::cout << "ERROR::STOOL::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Tree"] = new sf::Texture();
     if (!this->textures["Tree"]->loadFromFile("../Textures/new_textures/Albero.png"))
     {
         std::cout << "ERROR::TREE::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Entrance"] = new sf::Texture();
     if (!this->textures["Entrance"]->loadFromFile("../Textures/new_textures/Ingresso.png"))
     {
         std::cout << "ERROR::ENTRANCE::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["MainMenu"] = new sf::Texture();
     if (!this->textures["MainMenu"]->loadFromFile("../Textures/new_textures/MainMenu.png"))
     {
         std::cout << "ERROR::MAINMENU::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Chef"] = new sf::Texture();
     if (!this->textures["Chef"]->loadFromFile("../Textures/new_textures/Chef.png"))
     {
         std::cout << "ERROR::CHEF::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Counter"] = new sf::Texture();
     if (!this->textures["Counter"]->loadFromFile("../Textures/new_textures/Bancone.png"))
     {
         std::cout << "ERROR::CHEF::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Dishwasher"] = new sf::Texture();
     if (!this->textures["Dishwasher"]->loadFromFile("../Textures/new_textures/Dishwasher.png"))
     {
         std::cout << "ERROR::DISHWASHER::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Main1"] = new sf::Texture();
     if (!this->textures["Main1"]->loadFromFile("../Textures/Main1.png"))
     {
         std::cout << "ERROR::Main1::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
}

