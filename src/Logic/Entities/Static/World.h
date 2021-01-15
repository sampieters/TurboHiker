/**
 * \brief World class that implements all the functions the game can request.
 * \details This class has al the info used to create a world to play in.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#include <vector>
#include <memory>
#include <utility>
#include <algorithm>
#include "Finish.h"
#include "../../../Singletons/RandomNumberGenerator.h"
#include "../../Factories/AbstractFactory.h"
#include "../../../Utils/CONST.h"
#include "../../../Utils/Enum.h"
#include "../Entity.h"

namespace turbohiker {
    class World : public turbohiker::Entity {
    private:
        std::shared_ptr<AbstractFactory::Factory> ConcreteFactory;
        std::vector<std::shared_ptr<turbohiker::Entity>> entities;
        std::shared_ptr<Score> score;
        std::string player_name;
        std::vector<float> boundaries;
    public:
        const std::shared_ptr<Score> &getScore() const;

        void setScore(const std::shared_ptr<Score> &score);

        World(std::string player_name);

        void InitWorld();

        void display() override;

        void update(double elapsedTime) override;

        void handlePlayerInput(InputCode code, bool pressed);

        void handleStates(double elapsedTime);

        void generateLanes();

        void generateRandomStaticEnemies();

        void generateRandomAttackingEnemies();

        void CheckWhereToMove(const std::shared_ptr<Enemy>& enemy);

        void CompetingAi(const std::shared_ptr<Enemy>& enemy);

        bool checkFinished(const std::shared_ptr<turbohiker::DynamicEntity>& to_check);

        bool isStop();

        /**
         * Getters
         */

        const std::shared_ptr<AbstractFactory::Factory> &getConcreteFactory() const;

        void setConcreteFactory(const std::shared_ptr<AbstractFactory::Factory> &concreteFactory);

        const std::vector<std::shared_ptr<turbohiker::Entity>> &getEntities() const;

        bool HorizontalOutOfBoundaries(float y);

        bool IsCollision(const std::shared_ptr<DynamicEntity>& to_check);

        std::shared_ptr<Enemy> GetClosestEnemy(const std::shared_ptr<DynamicEntity>& player);
    };
}

#endif //TURBOHIKER_WORLD_H