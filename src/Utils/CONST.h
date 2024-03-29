/**
 * \brief Contains all the constants used in this project. Only change values here for changing the world.
 * \author Sam Pieters
 * \date 24 December 2020
 */

#ifndef GAME_CONST_H
#define GAME_CONST_H

#include <cmath>
#include <iostream>
#include <vector>

namespace CONST {
namespace WINDOW {
const unsigned int WIDTH = 1920;
const unsigned int HEIGHT = 1080;
} // namespace WINDOW

namespace WORLD {
const double LEFT_BOUNDARY = -4;
const double RIGHT_BOUNDARY = 4;
const double UPPER_BOUNDARY = 3;
const double LOWER_BOUNDARY = -3;
const std::pair<double, double> SIZE = {abs(LEFT_BOUNDARY) + abs(RIGHT_BOUNDARY),
                                        abs(LOWER_BOUNDARY) + abs(UPPER_BOUNDARY)};

const unsigned int NR_OF_LANES = 6;
const double LANE_SIZE = SIZE.first/NR_OF_LANES;
const float MIN_DISTANCE_BETWEEN_ENEMIES = 7;
} // namespace WORLD

namespace FINISH {
const std::pair<double, double> SIZE = {CONST::WORLD::SIZE.first, 0.3};
const std::pair<double, double> POSITION = {(CONST::WORLD::LEFT_BOUNDARY + CONST::WORLD::RIGHT_BOUNDARY) /2, CONST::WORLD::UPPER_BOUNDARY - (SIZE.second/2)};
} // namespace FINISH

namespace PLAYER {
const float MIN_SPEED = 0.03;
const float MAX_SPEED = 0.16;
const float ACCELERATION = 0.01;
const unsigned int BEGIN_LANE = 1;

const std::pair<double, double> START_POSITION = {WORLD::LEFT_BOUNDARY + (WORLD::LANE_SIZE/2.0) + (WORLD::LANE_SIZE * BEGIN_LANE), -2.5};
const std::pair<double, double> SIZE = {0.3, 0.3};
const std::string TO_YELL = "OUT OF MY WAY!";
} // namespace PLAYER

namespace ENEMIES {
const std::pair<double, double> SIZE = {0.3, 0.3};
namespace COMPETING {
const float MIN_SPEED = 0.13;
const float MAX_SPEED = 0.2;
const float ACCELERATION = 0.01;
const int STRENGTH = 250;
const float MOVE_CHANCE = 100;
const unsigned int NUMBER = 3;
const std::vector<float> LANE = {0, 2, 5};
} // namespace COMPETING
namespace STATIC {
const std::pair<unsigned int, unsigned int> AMOUNT = {3, 10};
const float MOVE_CHANCE = 50;
const int STRENGTH = 100;
} // namespace STATIC
namespace ATTACKING {
const std::pair<unsigned int, unsigned int> AMOUNT = {3, 10};
const float MIN_SPEED = -0.13;
const float MAX_SPEED = -0.2;
const float ACCELERATION = 0.01;
const int STRENGTH = 100;
const float MOVE_CHANCE = 50;
const float SLOW_DOWN = 50;
} // namespace ATTACKING

} // namespace ENEMIES

namespace TIME {
const unsigned int MAX_CYCLES_PER_SECOND = 30;
const double SCALE = 1000000000.0;
const double MIN_TIME_PER_CYCLE = SCALE / MAX_CYCLES_PER_SECOND;
} // namespace TIME
} // namespace CONST

#endif // GAME_CONST_H