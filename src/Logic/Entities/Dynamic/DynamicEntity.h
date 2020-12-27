/**
 * \brief Dynamic entity class, every derived class from this class can move in the world.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#ifndef TURBOHIKER_DYNAMICENTITY_H
#define TURBOHIKER_DYNAMICENTITY_H

#include "../Entity.h"
#include "../Static/Lane.h"
#include "../../../Utils/CONST/CONST.h"

namespace turbohiker {
    class DynamicEntity: public Entity {
    private:
        double TimeSindsYelling;
        std::string yelling;
    public:
        const std::shared_ptr<Lane> &getLane() const;

        void setLane(const std::shared_ptr<Lane> &lane);

    private:
        std::shared_ptr<Lane> lane;
        float speed;
        bool yell;
    public:
        // CONSTRUCTOR
        DynamicEntity();

        // GETTERS AND SETTERS
        float getSpeed() const;

        void setSpeed(float speed);

        // MY FUNCTIONS
        void MoveUp(double elapsedTime);

        void MoveDown(double elapsedTime);

        void MoveLeft();

        void MoveRight();

        void SpeedUp();

        void SlowDown();

        std::pair<float, float> GetBack();

        std::pair<float, float> GetFront();

        std::pair<float, float> GetLeftSide();

        std::pair<float, float> GetRightSide();

        const std::string &getYelling() const;

        void setYelling(const std::string &yelling);

        bool isYell() const;

        void setYell(bool yell);

        double getTimeSindsYelling() const;

        void setTimeSindsYelling(double timeSindsYelling);

        void update(double elapsedTime) override;
    };
}

#endif //TURBOHIKER_DYNAMICENTITY_H