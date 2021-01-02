/**
 * \brief Player class is an entity that the user can control.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#include "Player.h"

turbohiker::Player::Player() {
    this->setSpeed(CONST::PLAYER::MIN_SPEED);
    this->setPosition(CONST::PLAYER::START_POSITION);
    this->setSize(CONST::PLAYER::SIZE);
    this->setYelling(CONST::PLAYER::TO_YELL);
    this->setType(EntityType::Player);
}

float turbohiker::Player::getDistancetraveled(float point_y) {
    return this->getPosition().second - point_y;
}

bool turbohiker::Player::checkDistanceTraveled(float lenght) {
    static float begin = CONST::PLAYER::START_POSITION.second;
    if(getDistancetraveled(begin) > lenght) {
        begin = this->getPosition().second;
        return true;
    } else {
        return false;
    }
}

void turbohiker::Player::update(double elapsedTime) {
    this->MoveUp(elapsedTime);
    if(checkDistanceTraveled(0.001)) {
        this->NotifyObservers(Event::MOVE);
    }
}