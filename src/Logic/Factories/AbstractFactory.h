//
// Created by Sam Pieters on 03/12/2020.
//

#ifndef TURBOHIKER_ABSTRACTFACTORY_H
#define TURBOHIKER_ABSTRACTFACTORY_H

#include "../Entities/Entity.h"
#include "../Entities/Dynamic/Player.h"
#include "../Entities/Dynamic/Enemy.h"
#include "../Entities/Static/Score.h"


namespace AbstractFactory {
    class Factory {
    public:
        /// Destructor needs to be virtual.
        virtual ~Factory() {}

        /// Instructs this factory to create a value.
        virtual std::shared_ptr<turbohiker::Entity> CreateWorld(std::string player_name) const = 0;

        virtual std::shared_ptr<turbohiker::Entity> CreateFinish() const = 0;

        virtual std::shared_ptr<turbohiker::Entity> CreatePlayer() const = 0;

        virtual std::shared_ptr<turbohiker::Entity> CreateCamera(std::shared_ptr<turbohiker::Entity> entity, std::shared_ptr<turbohiker::Score> score) const = 0;

        virtual std::shared_ptr<turbohiker::Entity> CreateCompetingEnemy() const = 0;

        virtual std::shared_ptr<turbohiker::Entity> CreateStaticEnemy() const = 0;

        virtual std::shared_ptr<turbohiker::Entity> CreateAttackingEnemy() const = 0;

        virtual std::shared_ptr<turbohiker::Entity> CreateLane() const = 0;

        virtual std::shared_ptr<turbohiker::Score> CreateScore() const = 0;
    };
}


#endif //TURBOHIKER_ABSTRACTFACTORY_H
