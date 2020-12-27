/**
 * \brief Camera class used to let you see part of the world.
 * \details This class keeps track of the players position to view the player at all time. And keeps the score to display it.
 * \author Sam Pieters
 * \date 27 December 2020
 */


#ifndef TURBOHIKER_CAMERA_H
#define TURBOHIKER_CAMERA_H

#include "../Entity.h"
#include "../Dynamic/Player.h"
#include "Score.h"

namespace turbohiker {
    class Camera: public Entity {
    private:
        std::shared_ptr<turbohiker::Player> player;
        std::shared_ptr<turbohiker::Score> score;
    public:
        Camera(std::shared_ptr<turbohiker::Score> score, std::shared_ptr<turbohiker::Player> player);

        const std::shared_ptr<turbohiker::Score> &getScore() const;

        void setScore(const std::shared_ptr<turbohiker::Score> &score);

        void update(double elapsedTime) override;

        const std::shared_ptr<turbohiker::Player> &getPlayer() const;

        void setPlayer(const std::shared_ptr<turbohiker::Player> &player);
    };
}

#endif //TURBOHIKER_CAMERA_H