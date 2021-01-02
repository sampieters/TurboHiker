//
// Created by Sam Pieters on 03/12/2020.
//

#include "AbstractFactory.h"
#include "../../Logic/Entities/Static/World.h"

std::shared_ptr<turbohiker::Entity> AbstractFactorySFML::Factory::CreateWorld(std::string player_name) const {
    return std::make_shared<turbohiker::World>(player_name);
}

std::shared_ptr<turbohiker::Entity> AbstractFactorySFML::Factory::CreatePlayer() const {
    auto temp_player = turbohikerSFML::Player();
    temp_player.setWindowToDrawTo(window);
    return std::make_shared<turbohikerSFML::Player>(temp_player);
}

std::shared_ptr<turbohiker::Entity> AbstractFactorySFML::Factory::CreateCompetingEnemy() const {
    auto temp_enemy = turbohikerSFML::Competing();
    temp_enemy.setWindowToDrawTo(window);
    return std::make_shared<turbohikerSFML::Competing>(temp_enemy);
}

std::shared_ptr<turbohiker::Entity> AbstractFactorySFML::Factory::CreateStaticEnemy() const {
    auto temp_enemy = turbohikerSFML::Static();
    temp_enemy.setWindowToDrawTo(window);
    return std::make_shared<turbohikerSFML::Static>(temp_enemy);
}

std::shared_ptr<turbohiker::Entity> AbstractFactorySFML::Factory::CreateAttackingEnemy() const {
    auto temp_enemy = turbohikerSFML::Attacking();
    temp_enemy.setWindowToDrawTo(window);
    return std::make_shared<turbohikerSFML::Attacking>(temp_enemy);
}

std::shared_ptr<turbohiker::Entity> AbstractFactorySFML::Factory::CreateLane() const {
    auto temp_lane = turbohikerSFML::Lane();
    temp_lane.setWindowToDrawTo(window);
    std::shared_ptr<turbohiker::Entity> lane = std::make_shared<turbohikerSFML::Lane>(temp_lane);
    return lane;
}

std::shared_ptr<turbohiker::Entity> AbstractFactorySFML::Factory::CreateCamera(std::shared_ptr<turbohiker::Entity> entity, std::shared_ptr<turbohiker::Score> score) const {
    auto player = std::dynamic_pointer_cast<turbohiker::Player>(entity);
    return std::make_shared<turbohikerSFML::Camera>(score, player, window);
}

std::shared_ptr<turbohiker::Entity> AbstractFactorySFML::Factory::CreateFinish() const {
    auto temp_finish = turbohikerSFML::Finish();
    temp_finish.setWindowToDrawTo(window);
    return std::make_shared<turbohikerSFML::Finish>(temp_finish);
}

std::shared_ptr<turbohiker::Score> AbstractFactorySFML::Factory::CreateScore() const {
    return std::make_shared<turbohiker::Score>();
}
