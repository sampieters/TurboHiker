//
// Created by Sam Pieters on 14/12/2020.
//

#ifndef TURBOHIKERSFML_CAMERA_H
#define TURBOHIKERSFML_CAMERA_H

#include "../../../Logic/Entities/Static/Camera.h"
#include "../Entity.h"

#include <memory>

namespace turbohikerSFML {
class Camera : public Entity, public turbohiker::Camera
{
public:
        Camera(std::shared_ptr<turbohiker::Score> score, std::shared_ptr<turbohiker::Player> player,
               const std::shared_ptr<sf::RenderWindow>& window);

        void display() override;
};
} // namespace turbohikerSFML

#endif // TURBOHIKERSFML_CAMERA_H
