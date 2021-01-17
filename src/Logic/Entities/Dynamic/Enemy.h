/**
 * \brief Enemy classes are entities that block the player from moving.
 * \details Multiple derived enemy classes: 1) Static 2) Competing 3) Attacking that each do other movements and prompts
 *          in the world.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#ifndef TURBOHIKER_ENEMY_H
#define TURBOHIKER_ENEMY_H

#include "../../../Singletons/RandomNumberGenerator.h"
#include "../../../Utils/Enum.h"
#include "./DynamicEntity.h"

#include <memory>

namespace turbohiker {

/** \class Enemy Enemy.h "src/Logic/Entities/Dynamic/Enemy.h"
 * \brief The enemies of that game. Every enemy can respond to a yelling of the player and gets scared to keep particpating.
 * Every type of enemy has a spcific chance to move when being yelled at.
 */
class Enemy : public DynamicEntity
{
private:
        float MoveChance;
        Response response;
        unsigned int scared_meter;

public:
        /**
         * Default constructor of the Enemy class.
         */
        Enemy();

        /**
         * \brief Constructor
         * \param chance: The chance that a player will move when being yelled at.
         */
        Enemy(float chance);

        /**
         * \details When an enemy is being yelled at the enemy can response to it. The enemy can obey, defy, have pain or
         * die depending on the move chance.
         * \return The final response that the enemy will give.
         */
        Response getResponse() const;

        /**
         * \details Sets the response the enemy has to give back when being yelled at.
         * \param response: An enumerator that corresponds with a response that the enemy can give back.
         */
        void setResponse(Response response);

        /**
         * \brief Will generate an outcome depending on the move chance and the possibilities of movements of the enemy in
         * the world.
         * \param preference: The possibilities of movements the enemy can make from its current position in the world.
         */
        virtual void DoSomethingWhenYell(MovePreference preference){};

        /**
         * \brief Gets the move chance of the enemy when being yelled at.
         * \return A value between 0 and 100.
         */
        float getMoveChance() const;

        /**
         * \brief Sets the move chance of the enemy.
         * \param moveChance: The move chance as value between 0 and 100.
         */
        void setMoveChance(float moveChance);

        /**
         * \brief Gets the scared meter of the enemy.
         * \return A value between 0 and the maximum set value of the scared meter on initialization.
         */
        unsigned int getScaredMeter() const;

        /**
         * \brief Sets the scared meter of an enemy.
         * \param scaredMeter: A value between 0 and the maximum value on initialization.
         */
        void setScaredMeter(unsigned int scaredMeter);
};

/** \class Static Enemy.h "src/Logic/Entities/Dynamic/Enemy.h"
 * \brief The Static enemy. This is an enemy that can only move from a lane to another neighboring lane and thus will
 * never move forwards or backwards.
 */
class Static : public Enemy
{
public:
        /**
         * The default constructor of a Static Enemy.
         */
        Static();

        /**
         * \brief Will generate an outcome depending on the move chance and the possibilities of movements of the enemy in
         * the world.
         * \param preference: The possibilities of movements the enemy can make from its current position in the world.
         */
        void DoSomethingWhenYell(MovePreference preference) override;
};

/** \class Competing Enemy.h "src/Logic/Entities/Dynamic/Enemy.h"
 * \brief The Competing enemy. This is an enemy that will compete with the player and thus will move forward. It can move
 * forward, backward or from a lane to a neighboring lane.
 */
class Competing : public Enemy
{
public:
        /**
         * Default constructor of the Competing Enemy.
         */
        Competing();

        /**
         * \brief Will generate an outcome depending on the move chance and the possibilities of movements of the enemy in
         * the world.
         * \param preference: The possibilities of movements the enemy can make from its current position in the world.
         */
        void DoSomethingWhenYell(MovePreference preference) override;
};

/** \class Attacking Enemy.h "src/Logic/Entities/Dynamic/Enemy.h"
  * \brief The Attacking enemy. This is an enemy that will attack the player and thus will move in the opposite direction
  * the player is moving. It can move backward or from a lane to a neighboring lane. This is also the only enemy that
  * doesn't collide with all the dynamic entities of the game. The attacking player will hover over a static enemy.
 */
class Attacking : public Enemy
{
public:
        /**
         * The default constrcutor of the Attacking Enemy.
         */
        Attacking();

        /**
         * \brief Will generate an outcome depending on the move chance and the possibilities of movements of the enemy in
         * the world.
         * \param preference: The possibilities of movements the enemy can make from its current position in the world.
         */
        void DoSomethingWhenYell(MovePreference preference) override;
};
} // namespace turbohiker

#endif // TURBOHIKER_ENEMY_H