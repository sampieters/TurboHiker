/**
 * \brief Enemy classes are entities that block the player from moving.
 * \details Multiple derived enemy classes: 1) Static 2) Competing 3) Attacking that each do other movements and prompts
 *          in the world.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#ifndef TURBOHIKER_ENEMY_H
#define TURBOHIKER_ENEMY_H

#include "./DynamicEntity.h"
#include "../../../Utils/Enum.h"
#include "../../../Singletons/RandomNumberGenerator.h"

namespace turbohiker {
    class Enemy : public DynamicEntity {
    private:
        float MoveChance;
        Response response;
        unsigned int scared_meter;
    public:
        Enemy();

        Response getResponse() const;

        void setResponse(Response response);

        Enemy(float chance);

        virtual void DoSomethingWhenYell(MovePreference preference) {};

        float getMoveChance() const;

        void setMoveChance(float moveChance);

        unsigned int getScaredMeter() const;

        void setScaredMeter(unsigned int scaredMeter);
    };

    class Static : public Enemy {
    public:
        Static();
        void DoSomethingWhenYell(MovePreference preference) override;
    };

    class Competing : public Enemy {
    public:
        Competing();
        void DoSomethingWhenYell(MovePreference preference) override;
    };

    class Attacking : public Enemy {
    public:
        Attacking();
        void DoSomethingWhenYell(MovePreference preference) override;

    };
}

#endif //TURBOHIKER_ENEMY_H