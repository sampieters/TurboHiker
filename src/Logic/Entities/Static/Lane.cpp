/**
 * \brief Lane class used to position every entity in the world.
 * \details This class is used to move every dynamic entity over the world. It keeps it right and left lane.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#include "Lane.h"

turbohiker::Lane::Lane() {
    this->setSize({(abs(CONST::WORLD::LEFT_BOUNDARY) + abs(CONST::WORLD::RIGHT_BOUNDARY)) / CONST::WORLD::NR_OF_LANES, abs(CONST::WORLD::LOWER_BOUNDARY) + abs(CONST::WORLD::UPPER_BOUNDARY)});
    this->setType(EntityType::Lane);

}

float turbohiker::Lane::GetMiddle() {
    return getPosition().first;
}

const std::shared_ptr<turbohiker::Lane> &turbohiker::Lane::getPrevious() const {
    return previous;
}

void turbohiker::Lane::setPrevious(const std::shared_ptr<Lane> &previous) {
    Lane::previous = previous;
}

const std::shared_ptr<turbohiker::Lane> &turbohiker::Lane::getNext() const {
    return next;
}

void turbohiker::Lane::setNext(const std::shared_ptr<Lane> &next) {
    Lane::next = next;
}
