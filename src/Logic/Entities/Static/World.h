/**
 * \brief World class that implements all the functions the game can request.
 * \details This class has al the info used to create a world to play in.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#include "../../../Singletons/RandomNumberGenerator.h"
#include "../../../Utils/CONST.h"
#include "../../../Utils/Enum.h"
#include "../../Factories/AbstractFactory.h"
#include "../Entity.h"
#include "Finish.h"
#include <algorithm>
#include <memory>
#include <utility>
#include <vector>

namespace turbohiker {

/** \class World World.h "src/Logic/Entities/Static/World.h"
 * \brief Class that is the world of the game.
 * \details This class implements everything a world needs. Like collision detection, check boundaries, ...
 */
class World : public turbohiker::Entity
{
private:
        std::shared_ptr<AbstractFactory::Factory> ConcreteFactory;
        std::vector<std::shared_ptr<turbohiker::Entity>> entities;
        std::shared_ptr<Score> score;
        std::string player_name;
        std::vector<float> boundaries;

public:
        /**
         * \brief The default constructor of the world.
         * \param player_name: The name of the player that is moving in the world.
         */
        World(std::string player_name);

        /**
         * \brief Initializes the entities in the world and not the world itself.
         */
        void InitWorld();

        /**
         * \brief Generates the amount of lanes that is specified in CONST.h using the abstract factory.
         */
        void generateLanes();

        /**
         * \brief Generates an amount of static enemies in the world using the abstract factory. The amount of static
         * enemies is specified in CONST.h.
         */
        void generateRandomStaticEnemies();

        /**
         * \brief Generates an amount of attacking enemies in the world using the abstract factory. The amount of attacking
         * enemies is specified in CONST.h.
         */
        void generateRandomAttackingEnemies();

        /**
         * \brief Function that is a part of the composition design pattern. Used to display every entity but keeps the
         * logic and visual of the entity seperate.
         */
        void display() override;

        /**
         * \brief Function that is part of the composition design pattern. Used to update every entity in the world without
         * leaning on the framerate.
         * \param elapsedTime: double that takes care of the independent movement from the framerate.
         */
        void update(double elapsedTime) override;

        /**
         * \brief Handles the input to make interactions with the player. This includes yelling and moving.
         * \param code: The input code.
         * \param pressed: Check if the input is actually pressed or not. Usefull for keep holding a key.
         */
        void handlePlayerInput(InputCode code, bool pressed);

        /**
         * \brief This function handles everything that is not an input. For example when yelled or collided there has to
         * happen something.
         * \param elapsedTime: Used to not depend on the framerate.
         */
        void handleStates(double elapsedTime);

        /**
         * \brief Check where a dynamic entity can move to. The entity can move to a lane that has no neighbour dynamic entity
         * from that lane.
         * \param enemy: The enemy that needs to be checked where to move to.
         * \return Where the enemy can move to. This can be left, right, left and right (preference = None) or can not
         * move at all.
         */
        MovePreference CheckWhereToMove(const std::shared_ptr<Enemy>& enemy);

        /**
         * \brief Simple AI algorithm that moves the competing enemies (randomly) in the world.
         * \param enemy
         */
        void CompetingAi(const std::shared_ptr<Enemy>& enemy);

        /**
         * \brief This function checks if a dynamic enemy is finished and counts the amount of finished entities.
         * \param to_check: The entity to check if it is already gone over the finish line or not.
         * \return boolean that indicates if the dynamic entity has gone over the finish line.
         */
        bool checkFinished(const std::shared_ptr<turbohiker::DynamicEntity>& to_check);

        /**
         * \brief Checks if entity is out of horizontal boundaries.
         * \param y: The y-coördinate of the entity that needs to be checked if out of horizontal boundaries.
         * \return boolean that indicates if the entity is out of horizontal bounds.
         */
        bool HorizontalOutOfBoundaries(float y);

        /**
         * \brief Checks if an entity collides with another dynamic entity (other than itself).
         * \param to_check: The entity that needs to be checked if it collides.
         * \return boolean that indicates if the entity collides or not.
         */
        bool IsCollision(const std::shared_ptr<DynamicEntity>& to_check);

        /**
         * \brief Get's the closest enemy in front of a dynamic entity from that same lane.
         * \param player: The dynamic entity that needs to be searched the closest enemy from.
         * \return A shared pointer to an enemy. This is the closest enemy of the parameter player from that same lane in
         * front of him. If no one in front of the player the function returns nullptr.
         */
        std::shared_ptr<Enemy> GetClosestEnemy(const std::shared_ptr<DynamicEntity>& player);


        /**
         * \brief Checks if the plalyer has gone over the finish and thus if the game needs to be stopped.
         * \return boolean that indicates if the game needs to be stopped.
         */
        bool isStop();

        /**
         * \brief Gets the score of the player in the world.
         * \return shared pointer to a score.
         */
        const std::shared_ptr<Score>& getScore() const;

        /**
         * \brief Sets the score of the player in the world.
         * \param score: The score of the player.
         */
        void setScore(const std::shared_ptr<Score>& score);

        /**
         * Gets the concrete factory of the world that is used to make every entity in the world.
         * \return A shared pointer to a concrete factory.
         */
        const std::shared_ptr<AbstractFactory::Factory>& getConcreteFactory() const;

        /**
         * Sets the concrete factory of the world that is used to make every entity in the world.
         * \param A shared pointer to a concrete factory.
         */
        void setConcreteFactory(const std::shared_ptr<AbstractFactory::Factory>& concreteFactory);

        /**
         * Gets all the entities that are in the world on that moment.
         * \return a vector of shared pointers to entities.
         */
        const std::vector<std::shared_ptr<turbohiker::Entity>>& getEntities() const;

};
}

#endif // TURBOHIKER_WORLD_H