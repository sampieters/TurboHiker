/**
 * \brief Dynamic entity class, every derived class from this class can move in the world.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#ifndef TURBOHIKER_DYNAMICENTITY_H
#define TURBOHIKER_DYNAMICENTITY_H

#include "../../../Utils/CONST.h"
#include "../Entity.h"
#include "../Static/Lane.h"

#include <memory>

namespace turbohiker {

/** \class DynamicEntity DynamicEntity.h "src/Logic/Entities/Dynamic/DynamicEntity.h"
  * \brief The dynamic entity. This entity can move on and to lanes and can yell when being yelled at or when someting
  * is in the way.
 */
class DynamicEntity : public Entity
{
private:
        std::shared_ptr<Lane> lane;
        double TimeSindsYelling;
        std::string yelling;
        float speed;
        bool yell;

public:
        /**
         * Default constructor of the Dynamic entity.
         */
        DynamicEntity();

        /**
         * \brief The functionality to move a player up in the world.
         * \param elapsedTime: The time that takes care of the independent movement from the framerate.
         */
        void MoveUp(double elapsedTime);

        /**
         * \brief The functionality to move a player down in the world.
         * \param elapsedTime: The time that takes care of the independent movement from the framerate.
         */
        void MoveDown(double elapsedTime);

        /**
         * \brief The functionality to move a player left in the world thus to another lane.
         */
        void MoveLeft();

        /**
         * \brief The functionality to move a player right in the world thus to another lane.
         */
        void MoveRight();

        /**
         * \brief The functionality to speed up a player in the world.
         */
        void SpeedUp();

        /**
         * \brief The functionality to slow down a player in the world.
         */
        void SlowDown();

        /**
         * \details updates the dynamic entity's position in the world independent from the framerate.
         * \param elapsedTime: A double that is the time that takes care to update the dynamic entity independent from the
         * framerate.
         */
        void update(double elapsedTime) override;

        /**
         * \brief Gets the back of the dynamic entity in the world. Makes the implementation of the collision detection
         * easier.
         * \return A pair of floats representing the back of a dynamic entity in world coördinates.
         */
        std::pair<float, float> GetBack();

        /**
         * \brief Gets the front of the dynamic entity in the world. Makes the implementation of the collision detection
         * easier.
         * \return A pair of floats representing the front of a dynamic entity in world coördinates.
         */
        std::pair<float, float> GetFront();

        /**
         * \brief Gets the left side of the dynamic entity in the world. Makes the implementation of the collision detection
         * easier.
         * \return A pair of floats representing the left side of a dynamic entity in world coördinates.
         */
        std::pair<float, float> GetLeftSide();

        /**
         * \brief Gets the right side of the dynamic entity in the world. Makes the implementation of the collision detection
         * easier.
         * \return A pair of floats representing the right side of a dynamic entity in world coördinates.
         */
        std::pair<float, float> GetRightSide();

        /**
         * \brief Get the words a dynamic entity is yelling.
         * \return A string that is the sentence the entity is yelling.
         */
        const std::string& getYelling() const;

        /**
         * \brief Set the yell of a dynamic entity.
         * \param yelling: the string that is being yelled.
         */
        void setYelling(const std::string& yelling);

        /**
         * \brief Checks if the dynamic entity is yelling.
         * \return boolean that indicates if a dynamic entity is yelling.
         */
        bool isYell() const;

        /**
         * \brief sets if the player is yelling or not.
         * @param yell: boolean that says if the entity is yelling.
         */
        void setYell(bool yell);

        /**
         * \brief Get the amount of time that is passed since the entity yelled. Sort of cool down period.
         * \return A double that is the time since the last yell.
         */
        double getTimeSinceYelling() const;

        /**
         * \brief Set the amount of time between a yelling.
         * \param timeSindsYelling: The time that is passed since the last yell.
         */
        void setTimeSinceYelling(double timeSindsYelling);

        /**
         * \brief Get the lane the dynamic entity is currently on.
         * \return The lane.
         */
        const std::shared_ptr<Lane>& getLane() const;

        /**
         * \brief Set the lane that the dynamic entity is on at that moment.
         * \param lane: The (new) lane to be on.
         */
        void setLane(const std::shared_ptr<Lane>& lane);

        /**
         * \brief Get the speed of the dynamic entity.
         * \return The speed as a float value.
         */
        float getSpeed() const;

        /**
         * \brief Set the speed that the dynamic entity is going in the world.
         * \param speed: float that is the (new) speed of the entity.
         */
        void setSpeed(float speed);
};
} // namespace turbohiker

#endif // TURBOHIKER_DYNAMICENTITY_H