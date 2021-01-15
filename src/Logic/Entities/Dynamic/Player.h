/**
 * \brief Player class is an entity that the user can control.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#ifndef TURBOHIKER_PLAYER_H
#define TURBOHIKER_PLAYER_H

#include "../../../Observer/Observable.h"
#include "../Static/Score.h"
#include "./DynamicEntity.h"

#include <memory>

namespace turbohiker {
class Player : public DynamicEntity, public Observable
{
public:
        Player();

        bool checkDistanceTraveled(float lenght);

        float getDistancetraveled(float point_y);

        void update(double elapsedTime) override;
};
} // namespace turbohiker

#endif // TURBOHIKER_PLAYER_H