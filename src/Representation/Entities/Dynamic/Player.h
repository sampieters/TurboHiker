//
// Created by Sam Pieters on 01/12/2020.
//

#ifndef TURBOHIKERSFML_PLAYER_H
#define TURBOHIKERSFML_PLAYER_H

#include "../../../Logic/Entities/Dynamic/Player.h"
#include "../Entity.h"

#include <memory>

namespace turbohikerSFML {
class Player : public Entity, public turbohiker::Player
{
private:
        sf::Sound response;

public:
        Player();

        void display() override;
};
} // namespace turbohikerSFML

#endif // TURBOHIKERSFML_PLAYER_H