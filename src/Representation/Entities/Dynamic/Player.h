/**
 * \brief The player visualization class, a class that allows to show a player on a screen.
 * \author Sam Pieters
 * \date 01 December 2020
 */

#ifndef TURBOHIKERSFML_PLAYER_H
#define TURBOHIKERSFML_PLAYER_H

#include "../../../Logic/Entities/Dynamic/Player.h"
#include "../Entity.h"

#include <memory>

namespace turbohikerSFML {

/** \class Player Player.h "src/Representation/Dynamic/PLayer.h"
 * \brief Visualization and audio of the player. This allows to draw the player on the window and play sound prompts with
 * a corresponding action.
 */
class Player : public Entity, public turbohiker::Player
{
private:
        sf::Sound response;

public:
        /**
         * \brief Default constructor for the Player representation.
         */
        Player();

        /**
         * \brief Function that displays the player on the window.
         */
        void display() override;
};
}

#endif // TURBOHIKERSFML_PLAYER_H