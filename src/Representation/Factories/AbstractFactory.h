//
// Created by Sam Pieters on 03/12/2020.
//

#ifndef TURBOHIKERSFML_ABSTRACTFACTORY_H
#define TURBOHIKERSFML_ABSTRACTFACTORY_H

#include "../../Logic/Factories/AbstractFactory.h"
#include "../Entities/Dynamic/Player.h"
#include "../Entities/Dynamic/Enemy.h"
#include "../Entities/Static/Finish.h"
#include "../Entities/Static/Camera.h"
#include "../Entities/Static/Lane.h"
#include <memory>

namespace AbstractFactorySFML {
    class Factory: public AbstractFactory::Factory  {
    public:
        std::shared_ptr<sf::RenderWindow> window;

        /// Destructor needs to be virtual.
        ~Factory() override {}
        /// Instructs this factory to create a value.
        std::shared_ptr<turbohiker::Entity> CreateWorld(std::string player_name) const override;

        std::shared_ptr<turbohiker::Entity> CreateFinish() const override;

        std::shared_ptr<turbohiker::Entity> CreatePlayer() const override;

        std::shared_ptr<turbohiker::Entity> CreateCamera(std::shared_ptr<turbohiker::Entity> entity, std::shared_ptr<turbohiker::Score> score) const override;

        std::shared_ptr<turbohiker::Entity> CreateCompetingEnemy() const override;

        std::shared_ptr<turbohiker::Entity> CreateStaticEnemy() const override;

        std::shared_ptr<turbohiker::Entity> CreateAttackingEnemy() const override;

        std::shared_ptr<turbohiker::Entity> CreateLane() const override;

        std::shared_ptr<turbohiker::Score> CreateScore() const override;
    };
}


#endif //TURBOHIKERSFML_ABSTRACTFACTORY_H
