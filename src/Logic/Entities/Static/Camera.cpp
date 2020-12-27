/**
 * \brief Camera class used to let you see part of the world.
 * \details This class keeps track of the players position to view the player at all time. And keeps the score to display it.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#include "Camera.h"

#include <utility>

turbohiker::Camera::Camera(std::shared_ptr<turbohiker::Score> score, std::shared_ptr<turbohiker::Player> player): score(std::move(score)) {
    this->setPlayer(player);
    this->setPosition({0, this->getPlayer()->getPosition().second + (this->getSize().second/2) - 0.5});
    this->setSize({8, 2.5});
}

void turbohiker::Camera::update(double elapsedTime) {
    this->setPosition({0, this->getPlayer()->getPosition().second + (this->getSize().second/2) - 0.5});
}

const std::shared_ptr<turbohiker::Player> &turbohiker::Camera::getPlayer() const {
    return player;
}

void turbohiker::Camera::setPlayer(const std::shared_ptr<turbohiker::Player> &player) {
    Camera::player = player;
}

const std::shared_ptr<turbohiker::Score> &turbohiker::Camera::getScore() const {
    return score;
}

void turbohiker::Camera::setScore(const std::shared_ptr<turbohiker::Score> &score) {
    Camera::score = score;
}
