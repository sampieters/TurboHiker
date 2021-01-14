/**
 * \brief Contains all the constants used in this project. Only change values here for changing the world.
 * \author Sam Pieters
 * \date 24 December 2020
 */

#ifndef GAME_CONST_H
#define GAME_CONST_H

#include <iostream>
#include <cmath>
#include <vector>

namespace CONST{
    namespace WINDOW{
        const unsigned int WIDTH = 1920;
        const unsigned int HEIGHT = 1080;
    }

    namespace WORLD{
        const double LEFT_BOUNDARY = -4;
        const double RIGHT_BOUNDARY = 4;
        const double UPPER_BOUNDARY = 3;
        const double LOWER_BOUNDARY = -3;
        const std::pair<double, double> SIZE = {abs(LEFT_BOUNDARY) + abs(RIGHT_BOUNDARY),
                                                abs(LOWER_BOUNDARY) + abs(UPPER_BOUNDARY)};

        const unsigned int NR_OF_LANES = 4;
        const float MIN_DISTANCE_BETWEEN_ENEMIES = 7;
    }

    namespace PLAYER{
        const float MIN_SPEED = 0.03;
        const float MAX_SPEED = 0.16;
        const float ACCELERATION = 0.01;
        const unsigned int BEGIN_LANE = 2;
        const std::pair<double, double> START_POSITION = {-1, -2.5};
        const std::pair<double, double> SIZE = {0.3, 0.3};
        const std::string TO_YELL = "MOVEEEE!";
    }

    namespace  ENEMIES {
        namespace COMPETING {
            const float MIN_SPEED = 0.13;
            const float MAX_SPEED = 0.2;
            const float ACCELERATION = 0.01;
            const int STRENGTH = 250;
            const float MOVE_CHANCE = 100;
            const unsigned int NUMBER = 3;
            const std::vector<float> LANE = {0, 2, 3};
        }
        namespace STATIC {
            const float MOVE_CHANCE = 50;
            const int STRENGTH = 100;
        }
        namespace ATTACKING {
            const float MIN_SPEED = 0.13;
            const float MAX_SPEED = 0.2;
            const float ACCELERATION = 0.01;
            const int STRENGTH = 100;
            const float MOVE_CHANCE = 50;
            const float SLOW_DOWN = 50;
        }

    }

    namespace TIME {
        const unsigned int MAX_CYCLES_PER_SECOND = 30;
        const double SCALE = 1000000000.0;
        const double MIN_TIME_PER_CYCLE = SCALE / MAX_CYCLES_PER_SECOND;
    }
}

#endif //GAME_CONST_H