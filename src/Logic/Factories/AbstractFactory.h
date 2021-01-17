/**
 * \brief The AbstractFactory, a part of the AbstractFactory implementation.
 * \author Sam Pieters
 * \date 03 December 2020
 */

#ifndef TURBOHIKER_ABSTRACTFACTORY_H
#define TURBOHIKER_ABSTRACTFACTORY_H

#include "../Entities/Dynamic/Enemy.h"
#include "../Entities/Dynamic/Player.h"
#include "../Entities/Entity.h"
#include "../Entities/Static/Score.h"
#include <memory>

namespace AbstractFactory {

/** \class Factory AbstractFacotry.h "src/Logic/AbstractFactory.h"
 * \brief Class that is a part of the AbstractFactory.
 * \details Class that generates an specific entity with the corresponding function. This is the Abstractfactory that
 *          will create everything in the world (and the world itself).
 *
 *          Source(s) used: https://refactoring.guru/design-patterns/abstract-factory
 *                          https://www.tutorialspoint.com/design_pattern/abstract_factory_pattern.htm
 */
class Factory
{
public:
        /**
         * \brief Default destructor for the game.
         * \details Needs to be virtual for the concrete factory.
         */
        virtual ~Factory() {}

        /**
         * \brief Instructs this factory to create a value. In this case a World entity.
         * \param player_name: the name of the player. Needed to assign the score to the name.
         * \return A shared pointer to a World Entity.
         */
        virtual std::shared_ptr<turbohiker::Entity> CreateWorld(std::string player_name) const = 0;

        /**
         * \brief Instructs this factory to create a value. In this case a Finish entity.
         * \return A shared pointer to a Finish Entity.
         */
        virtual std::shared_ptr<turbohiker::Entity> CreateFinish() const = 0;

        /**
         * \brief Instructs this factory to create a value. In this case a Player entity.
         * \return A shared pointer to a Player Entity.
         */
        virtual std::shared_ptr<turbohiker::Entity> CreatePlayer() const = 0;

        /**
         * \brief Instructs this factory to create a value. In this case a Camera entity.
         * \param entity: A shared pointer to an entity which is the object to follow with the camera (the player in
         * this case). \param score: A shared pointer to the score so that the camera can ask the score at each time.
         * \return A shared pointer to a Camera Entity.
         */
        virtual std::shared_ptr<turbohiker::Entity> CreateCamera(std::shared_ptr<turbohiker::Entity> entity,
                                                                 std::shared_ptr<turbohiker::Score> score) const = 0;

        /**
         * \brief Instructs this factory to create a value. In this case a Competing Enemy entity.
         * \return A shared pointer to a Competing Enemy Entity.
         */
        virtual std::shared_ptr<turbohiker::Entity> CreateCompetingEnemy() const = 0;

        /**
         * \brief Instructs this factory to create a value. In this case a Static Enemy entity.
         * \return A shared pointer to a Static Enemy Entity.
         */
        virtual std::shared_ptr<turbohiker::Entity> CreateStaticEnemy() const = 0;

        /**
         * \brief Instructs this factory to create a value. In this case an Attacking Enemy entity.
         * \return A shared pointer to an Attacking Enemy Entity.
         */
        virtual std::shared_ptr<turbohiker::Entity> CreateAttackingEnemy() const = 0;

        /**
         * \brief Instructs this factory to create a value. In this case a Lane entity.
         * \return A shared pointer to a Lane Entity.
         */
        virtual std::shared_ptr<turbohiker::Entity> CreateLane() const = 0;

        /**
         * \brief Instructs this factory to create a value. In this case a Score.
         * \return A shared pointer to a Score.
         */
        virtual std::shared_ptr<turbohiker::Score> CreateScore() const = 0;
};
}

#endif // TURBOHIKER_ABSTRACTFACTORY_H
