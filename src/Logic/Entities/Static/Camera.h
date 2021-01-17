/**
 * \brief Camera class used to let you see part of the world.
 * \details This class keeps track of the players position to view the player at all time. And keeps the score to
 * display it.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#ifndef TURBOHIKER_CAMERA_H
#define TURBOHIKER_CAMERA_H

#include "../Dynamic/Player.h"
#include "../Entity.h"
#include "Score.h"
#include <memory>

namespace turbohiker {

/** \class Camera Camera.h "src/Logic/Entities/Static/Camera.h"
 * \brief A Camera is the users view of the world. The camera needs to track the player at any time.
 * \details There is only one camera in the world, this is the one that will follow the player at any time. The camera's
 * position gets updated when the player moves and will only stop tracking the player when the camera is going out of bounds.
 * The camera will hold the score of the player to make it visible to the user at any time.
 */
class Camera : public Entity
{
private:
        std::shared_ptr<turbohiker::Player> player;
        std::shared_ptr<turbohiker::Score> score;

public:
        /**
         * \brief Default constructor of the Camera.
         * \param score: The score of the player that the camera will hold.
         * \param player: The player that the camera will follow while the game is playing.
         */
        Camera(std::shared_ptr<turbohiker::Score> score, std::shared_ptr<turbohiker::Player> player);

        /**
         * \brief Gets the score of the player.
         * \return A score.
         */
        const std::shared_ptr<turbohiker::Score>& getScore() const;

        /**
         * \brief Sets the score.
         * \param score: The score for the camera.
         */
        void setScore(const std::shared_ptr<turbohiker::Score>& score);

        /**
         * \brief This function will update the position (in world coördinates) of the camera to ensure that it follows
         * the player at any time.
         * \param elapsedTime: The time that is elapsed in a loop. Ensures that the movement is frame independent.
         */
        void update(double elapsedTime) override;

        /**
         * \brief Gets the player that the camera is following.
         * \return A shared pointer to the player.
         */
        const std::shared_ptr<turbohiker::Player>& getPlayer() const;

        void setPlayer(const std::shared_ptr<turbohiker::Player>& player);
};
}

#endif // TURBOHIKER_CAMERA_H