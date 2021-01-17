/**
 * \brief The Camera visualization class, a class that allows to show a camera on a screen.
 * \author Sam Pieters
 * \date 14 December 2020
 */

#ifndef TURBOHIKERSFML_CAMERA_H
#define TURBOHIKERSFML_CAMERA_H

#include "../../../Logic/Entities/Static/Camera.h"
#include "../Entity.h"

#include <memory>

namespace turbohikerSFML {

/** \class Camera Camera.h "src/Representation/Static/Camera.h"
 * \brief Visualization of the camera. The camera's position will be updated to the players position.
 */
class Camera : public Entity, public turbohiker::Camera
{
public:
        /**
         * \brief Default constructor for the Lane representation.
         * \param score: The score that the window will hold to display it to the user.
         * \param player: The player to follow.
         * \param window: The window the camera has to be in.
         */
        Camera(std::shared_ptr<turbohiker::Score> score, std::shared_ptr<turbohiker::Player> player,
               const std::shared_ptr<sf::RenderWindow>& window);

        /**
         * \brief Function that displays the camera on the window.
         */
        void display() override;
};
}

#endif // TURBOHIKERSFML_CAMERA_H
