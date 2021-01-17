/**
 * \brief Player class is an entity that the user can control.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#ifndef TURBOHIKER_PLAYER_H
#define TURBOHIKER_PLAYER_H

#include "../../../Observer/Observable.h"
#include "../Static/Score.h"
#include "./DynamicEntity.h"

#include <memory>

namespace turbohiker {

/** \class Player Player.h "src/Logic/Entities/Dynamic/Player.h"
 * \brief The player of the game. It is used as an observabel from the observer pattern. This is the entity a user can
 * control and interact with.
 */
class Player : public DynamicEntity, public Observable
{
public:
        /**
         * The default constructor of the player.
         */
        Player();

        /**
         * \details Checks if a amount of distance (in world coördinates) is travelled by the player across the world.
         * \param lenght: The lenght that needs to be travelled for the check to return true.
         * \return A boolean that indicates if the amount is travelled or not.
         */
        bool checkDistanceTraveled(float lenght);

        /**
         * \details Gets an amount of distance travelled in world coördinates between a parameter and the current position.
         * \param point_y: The start position of where needs to be counted from.
         * \return A float that indicates the lenght that the player has travelled.
         */
        float getDistancetraveled(float point_y);

        /**
         * \details updates the players position in the world independent from the framerate. This function will also
         * notify the player's observers that he has travelled a certain amount.
         * \param elapsedTime: A double that is the time that takes care to update the player independent from the
         * framerate.
         */
        void update(double elapsedTime) override;
};
} // namespace turbohiker

#endif // TURBOHIKER_PLAYER_H