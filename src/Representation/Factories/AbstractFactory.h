/**
 * \brief The ConcreteFactory, a part of the AbstractFactory implementation.
 * \author Sam Pieters
 * \date 03 December 2020
 */

#ifndef TURBOHIKERSFML_ABSTRACTFACTORY_H
#define TURBOHIKERSFML_ABSTRACTFACTORY_H

#include "../../Logic/Factories/AbstractFactory.h"
#include "../Entities/Dynamic/Enemy.h"
#include "../Entities/Dynamic/Player.h"
#include "../Entities/Static/Camera.h"
#include "../Entities/Static/Finish.h"
#include "../Entities/Static/Lane.h"
#include <memory>

namespace AbstractFactorySFML {
/** \class Factory AbstractFactory.h "src/Representation/Factories/AbstractFacotry.h"
 * \brief Class that is a part of the AbstractFactory.
 * \details Class that generates an specific entity with the corresponding function. This is the ConcreteFactory that
 *          will create everything in the world (and the world itself).
 *
 *          Source(s) used: https://refactoring.guru/design-patterns/abstract-factory
 *                          https://www.tutorialspoint.com/design_pattern/abstract_factory_pattern.htm
 */
class Factory : public AbstractFactory::Factory
{
public:
        std::shared_ptr<sf::RenderWindow> window;

        /**
         * \brief Default destructor for the game.
         * \details overrides the destructor from the "src/Logic/Factories/AbstractFactory.h"
         */
        ~Factory() override {}

        /**
         * \brief Instructs this factory to create a value. In this case a World entity.
         * \param player_name: the name of the player. Needed to assign the score to the name.
         * \return A shared pointer to a World Entity.
         */
        std::shared_ptr<turbohiker::Entity> CreateWorld(std::string player_name) const override;

        /**
         * \brief Instructs this factory to create a value. In this case a Finish entity.
         * \return A shared pointer to a Finish Entity.
         */
        std::shared_ptr<turbohiker::Entity> CreateFinish() const override;

        /**
         * \brief Instructs this factory to create a value. In this case a Player entity.
         * \return A shared pointer to a Player Entity.
         */
        std::shared_ptr<turbohiker::Entity> CreatePlayer() const override;

        /**
         * \brief Instructs this factory to create a value. In this case a Camera entity.
         * \param entity: A shared pointer to an entity which is the object to follow with the camera (the player in
         * this case). \param score: A shared pointer to the score so that the camera can ask the score at each time.
         * \return A shared pointer to a Camera Entity.
         */
        std::shared_ptr<turbohiker::Entity> CreateCamera(std::shared_ptr<turbohiker::Entity> entity,
                                                         std::shared_ptr<turbohiker::Score> score) const override;

        /**
         * \brief Instructs this factory to create a value. In this case a Competing Enemy entity.
         * \return A shared pointer to a Competing Enemy Entity.
         */
        std::shared_ptr<turbohiker::Entity> CreateCompetingEnemy() const override;

        /**
         * \brief Instructs this factory to create a value. In this case a Static Enemy entity.
         * \return A shared pointer to a Static Enemy Entity.
         */
        std::shared_ptr<turbohiker::Entity> CreateStaticEnemy() const override;

        /**
         * \brief Instructs this factory to create a value. In this case an Attacking Enemy entity.
         * \return A shared pointer to an Attacking Enemy Entity.
         */
        std::shared_ptr<turbohiker::Entity> CreateAttackingEnemy() const override;

        /**
         * \brief Instructs this factory to create a value. In this case a Lane entity.
         * \return A shared pointer to a Lane Entity.
         */
        std::shared_ptr<turbohiker::Entity> CreateLane() const override;

        /**
         * \brief Instructs this factory to create a value. In this case a Score.
         * \return A shared pointer to a Score.
         */
        std::shared_ptr<turbohiker::Score> CreateScore() const override;
};
}

#endif // TURBOHIKERSFML_ABSTRACTFACTORY_H
