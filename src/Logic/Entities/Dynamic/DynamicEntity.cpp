/**
 * \brief Dynamic entity class, every derived class from this class can move in the world.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#include "DynamicEntity.h"

float turbohiker::DynamicEntity::getSpeed() const {
    return speed;
}

void turbohiker::DynamicEntity::setSpeed(float speed) {
    DynamicEntity::speed = speed;
}

void turbohiker::DynamicEntity::MoveUp(double elapsedTime) {
    float new_second = getPosition().second + (speed * elapsedTime);
    setPosition({getPosition().first, new_second});
}

void turbohiker::DynamicEntity::MoveDown(double elapsedTime) {
    float new_second = getPosition().second - (speed * elapsedTime);
    setPosition({getPosition().first, new_second});
}

void turbohiker::DynamicEntity::MoveLeft() {
    if(this->lane->getPrevious() != nullptr) {
        auto prev = this->lane->getPrevious();
        this->lane = prev;
    }
    setPosition({this->lane->GetMiddle(), getPosition().second});
}

void turbohiker::DynamicEntity::MoveRight() {
    if(this->lane->getNext() != nullptr) {
        auto next = this->lane->getNext();
        this->lane = next;
    }
    setPosition({this->lane->GetMiddle(), getPosition().second});
}

void turbohiker::DynamicEntity::SpeedUp() {
    speed += CONST::PLAYER::ACCELERATION;
    if(speed > CONST::PLAYER::MAX_SPEED) {
        speed = CONST::PLAYER::MAX_SPEED;
    }
}

void turbohiker::DynamicEntity::SlowDown() {
    speed -= CONST::PLAYER::ACCELERATION;
    if(speed < CONST::PLAYER::MIN_SPEED) {
        speed = CONST::PLAYER::MIN_SPEED;
    }
}

turbohiker::DynamicEntity::DynamicEntity() = default;

void turbohiker::DynamicEntity::update(double elapsedTime) {
    this->MoveUp(elapsedTime);
}

std::pair<float, float> turbohiker::DynamicEntity::GetFront() {
    return {this->getPosition().first, this->getPosition().second + (this->getSize().second/2)};
}

std::pair<float, float> turbohiker::DynamicEntity::GetBack() {
    return {this->getPosition().first, this->getPosition().second - (this->getSize().second/2)};
}

std::pair<float, float> turbohiker::DynamicEntity::GetLeftSide() {
    return {this->getPosition().first - (this->getSize().first/2), this->getPosition().second};
}

std::pair<float, float> turbohiker::DynamicEntity::GetRightSide() {
    return {this->getPosition().first + (this->getSize().first/2), this->getPosition().second};
}

const std::string &turbohiker::DynamicEntity::getYelling() const {
    return yelling;
}

void turbohiker::DynamicEntity::setYelling(const std::string &yelling) {
    DynamicEntity::yelling = yelling;
}

bool turbohiker::DynamicEntity::isYell() const {
    return yell;
}

void turbohiker::DynamicEntity::setYell(bool yell) {
    DynamicEntity::yell = yell;
}

double turbohiker::DynamicEntity::getTimeSindsYelling() const {
    return TimeSindsYelling;
}

void turbohiker::DynamicEntity::setTimeSindsYelling(double timeSindsYelling) {
    TimeSindsYelling = timeSindsYelling;
}

const std::shared_ptr<turbohiker::Lane> &turbohiker::DynamicEntity::getLane() const {
    return lane;
}

void turbohiker::DynamicEntity::setLane(const std::shared_ptr<Lane> &lane) {
    DynamicEntity::lane = lane;
}
