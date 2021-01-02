/**
 * \brief World class that implements all the functions the game can request.
 * \details This class has al the info used to create a world to play in.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#include "World.h"

turbohiker::World::World(std::string player_name) {
    this->boundaries = {static_cast<float>(CONST::WORLD::UPPER_BOUNDARY), static_cast<float>(CONST::WORLD::RIGHT_BOUNDARY),
                       static_cast<float>(CONST::WORLD::LOWER_BOUNDARY), static_cast<float>(CONST::WORLD::LEFT_BOUNDARY)};
    this->player_name = std::move(player_name);
}

void turbohiker::World::InitWorld() {
    // MAAK DE LANES
    generateLanes();

    // MAAK EEN FINISH
    entities.push_back(ConcreteFactory->CreateFinish());

    // MAAK SCOREBOARD
    this->score = ConcreteFactory->CreateScore();

    // MAAK EEN PLAYER
    auto player = ConcreteFactory->CreatePlayer();
    auto temp_player = std::static_pointer_cast<turbohiker::Player>(player);
    temp_player->setLane(std::dynamic_pointer_cast<turbohiker::Lane>(entities[1]));
    temp_player->AttachObserver(this->score);
    entities.push_back(temp_player);

    // MAAK DE CAMERA
    entities.push_back(ConcreteFactory->CreateCamera(player, score));

    // MAAK COMPETING PLAYERS
    for (int i = 0; i < CONST::ENEMIES::COMPETING::NUMBER; ++i) {
        auto comp = std::dynamic_pointer_cast<DynamicEntity>(ConcreteFactory->CreateCompetingEnemy());
        comp->setPosition({std::dynamic_pointer_cast<turbohiker::Lane>(entities[CONST::ENEMIES::COMPETING::LANE[i]])->getPosition().first, -2.5});
        comp->setLane(std::dynamic_pointer_cast<Lane>(entities[CONST::ENEMIES::COMPETING::LANE[i]]));
        entities.push_back(comp);
    }
    // MAAK STATIC AAN
    generateRandomStaticEnemies();

    // MAAK ATACKING AAN
    generateRandomAttackingEnemies();
}

void turbohiker::World::generateLanes() {
    std::shared_ptr<turbohiker::Lane> newe = nullptr;
    for (int i = 0; i < CONST::WORLD::NR_OF_LANES; ++i) {
        std::shared_ptr<Entity> lane = ConcreteFactory->CreateLane();
        lane->setPosition({boundaries[3] + (lane->getSize().first/2)  + i*lane->getSize().first,0});
        auto temp = std::dynamic_pointer_cast<turbohiker::Lane>(lane);
        temp->setPrevious(newe);
        if(newe != nullptr) {
            newe->setNext(temp);
        }
        newe = temp;
        entities.push_back(temp);
    }
}

void turbohiker::World::generateRandomStaticEnemies() {
    std::vector<std::pair<float, float>> already_used;
    int number = RandomNumberGenerator::generate_int(3, 10);
    for (int i = 0; i < number; ++i) {
        auto comp = std::dynamic_pointer_cast<DynamicEntity>(ConcreteFactory->CreateStaticEnemy());
        float pos_y = RandomNumberGenerator::Getinstance().generate_float((this->boundaries[2] + 1) / CONST::WORLD::MIN_DISTANCE_BETWEEN_ENEMIES, (this->boundaries[0] + 1)/ CONST::WORLD::MIN_DISTANCE_BETWEEN_ENEMIES);
        pos_y *= CONST::WORLD::MIN_DISTANCE_BETWEEN_ENEMIES;
        unsigned int lane = RandomNumberGenerator::Getinstance().generate_int(0, 4);
        auto lane_1 = std::dynamic_pointer_cast<Lane>(entities[lane]);
        float pos_x = lane_1->getPosition().first;

        std::pair<float, float> temp = {pos_x, pos_y};
        if(std::find(already_used.begin(), already_used.end(),temp) == already_used.end()) {
            already_used.emplace_back(pos_x, pos_y);
            comp->setPosition({pos_x, pos_y});
            comp->setLane(lane_1);
            entities.push_back(comp);
        }
    }
}

void turbohiker::World::generateRandomAttackingEnemies() {
    std::vector<std::pair<float, float>> already_used;
    int number = RandomNumberGenerator::generate_int(3, 10);
    for (int i = 0; i < number; ++i) {
        auto comp = std::dynamic_pointer_cast<DynamicEntity>(ConcreteFactory->CreateAttackingEnemy());
        float pos_y = RandomNumberGenerator::Getinstance().generate_float((this->boundaries[2] + 1) / CONST::WORLD::MIN_DISTANCE_BETWEEN_ENEMIES, (this->boundaries[0] + 1) / CONST::WORLD::MIN_DISTANCE_BETWEEN_ENEMIES);
        pos_y *= CONST::WORLD::MIN_DISTANCE_BETWEEN_ENEMIES;
        unsigned int lane = RandomNumberGenerator::Getinstance().generate_int(0, 4);
        auto lane_1 = std::dynamic_pointer_cast<Lane>(entities[lane]);
        float pos_x = lane_1->getPosition().first;

        std::pair<float, float> temp = {pos_x, pos_y};
        if(std::find(already_used.begin(), already_used.end(),temp) == already_used.end()) {
            already_used.emplace_back(pos_x, pos_y);
            comp->setPosition({pos_x, pos_y});
            comp->setLane(lane_1);
            entities.push_back(comp);
        }
    }
}

void turbohiker::World::display() {
    for (const auto& entity: entities) {
        entity->display();
    }
}

bool turbohiker::World::HorizontalOutOfBoundaries(float y) {
    return y < boundaries[2] || y > boundaries[0];
}

const std::vector<std::shared_ptr<turbohiker::Entity>> &turbohiker::World::getEntities() const {
    return entities;
}

void turbohiker::World::update(double elapsedTime) {
    for (const auto& entity_1: entities) {
        if(HorizontalOutOfBoundaries(entity_1->getPosition().second + (entity_1->getSize().second/2))) {
            continue;
        }
        if (std::dynamic_pointer_cast<turbohiker::DynamicEntity>(entity_1) != nullptr) {
            auto dynamic_1 = std::dynamic_pointer_cast<turbohiker::DynamicEntity>(entity_1);
            if (!this->IsCollision(dynamic_1)) {
                entity_1->update(elapsedTime);
            } else {
                if(std::dynamic_pointer_cast<turbohiker::Player>(entity_1) != nullptr) {
                    auto close_enemy = GetClosestEnemy(dynamic_1);
                    if(close_enemy != nullptr) {
                        close_enemy->setYell(true);
                        close_enemy->setResponse(Pain);
                    }
                }
            }
        } else {
            entity_1->update(elapsedTime);
        }
    }
}

void turbohiker::World::handlePlayerInput(InputCode code, bool pressed) {
    if(pressed) {
        for (const auto &entity: entities) {
            if (std::dynamic_pointer_cast<turbohiker::Player>(entity) != nullptr) {
                auto player = std::static_pointer_cast<turbohiker::Player>(entity);
                if (code == Z) {
                    player->SpeedUp();
                }
                else if(code == Q) {
                    player->MoveLeft();
                    if(IsCollision(player)) {
                        player->MoveRight();
                    }
                }
                else if(code == S) {
                    player->SlowDown();
                }
                else if(code == D) {
                    player->MoveRight();
                    if(IsCollision(player)) {
                        player->MoveLeft();
                    }
                }
                else if(code == SPACE) {
                    if(!player->isYell()) {
                        player->NotifyObservers(Event::YELLED);
                        auto enemy = GetClosestEnemy(player);
                        if (enemy != nullptr) {
                            enemy->setScaredMeter(enemy->getScaredMeter() - 50);
                            if(enemy->getScaredMeter() <= 0) {
                                enemy->setYell(true);
                                enemy->setResponse(Die);
                                player->NotifyObservers(Event::MURDERED);

                                //TODO:: ENtity nog niet hier verwijderen want dan roept die zijn death niet
                                auto iter = std::find(entities.begin(), entities.end(), enemy);
                                entities.erase(iter);
                            } else {
                                CheckWhereToMove(enemy);
                            }
                        }
                        player->setYell(true);
                    }
                }
            }
        }
    }
}

std::shared_ptr<turbohiker::Enemy> turbohiker::World::GetClosestEnemy(const std::shared_ptr<DynamicEntity>& player) {
    std::pair<float, float> player_pos = player->getPosition();
    std::shared_ptr<turbohiker::Enemy> returnenemy = nullptr;
    float enemy_pos_y = std::numeric_limits<float>::infinity();
    for (const auto &entity: entities) {
        auto enemy = std::dynamic_pointer_cast<turbohiker::Enemy>(entity);
        if (enemy != nullptr) {
            if (player->getPosition().first  == enemy->getPosition().first) {
                if (enemy->getPosition().second > player_pos.second && enemy->getPosition().second < enemy_pos_y) {
                    enemy_pos_y = enemy->getPosition().second;
                    returnenemy = enemy;
                }
            }
        }
    }
    return returnenemy;
}

bool turbohiker::World::IsCollision(const std::shared_ptr<DynamicEntity>& to_check) {
    for (const auto& entity_2: entities) {
        // Don't check collision on itself and don't check collision of a static and attacking
        if(to_check == entity_2 || std::dynamic_pointer_cast<turbohiker::Static>(entity_2) != nullptr && std::dynamic_pointer_cast<turbohiker::Attacking> (to_check) != nullptr) {
            continue;
        }
        auto dynamic_2 = std::dynamic_pointer_cast<turbohiker::DynamicEntity>(entity_2);
        if (dynamic_2 != nullptr) {
            if(dynamic_2->getLane() == to_check->getLane()) {
                if ((to_check->GetFront().second <= dynamic_2->GetFront().second && to_check->GetFront().second >= dynamic_2->GetBack().second) ||
                (to_check->GetBack().second <= dynamic_2->GetFront().second && to_check->GetBack().second >= dynamic_2->GetBack().second)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void turbohiker::World::handleStates(double elapsedTime) {
    for (const auto &entity: entities) {
        if (std::dynamic_pointer_cast<turbohiker::DynamicEntity>(entity) != nullptr) {
            auto dynamic = std::static_pointer_cast<turbohiker::DynamicEntity>(entity);
            if(dynamic->isYell()) {
                dynamic->setTimeSindsYelling(dynamic->getTimeSindsYelling() + elapsedTime);
                if(dynamic->getTimeSindsYelling() > 2.0) {
                    dynamic->setYell(false);
                    dynamic->setTimeSindsYelling(0);
                }
            }
            if(isStop()) {
                break;
            }
            if(checkFinished(dynamic)) {
                score->addFinisher();
            }
        }
        if(std::dynamic_pointer_cast<turbohiker::Competing>(entity) != nullptr) {
            auto competing = std::dynamic_pointer_cast<turbohiker::Competing>(entity);
            CompetingAi(competing);
        }
    }
}

bool turbohiker::World::checkFinished(const std::shared_ptr<turbohiker::DynamicEntity>& to_check) {
    for(const auto& finish: entities) {
        if(std::dynamic_pointer_cast<turbohiker::Finish>(finish) != nullptr) {
            if(to_check->getPosition().second >= finish->getPosition().second) {
                return true;
            }
        }
    }
    return false;
}

void turbohiker::World::CheckWhereToMove(const std::shared_ptr<Enemy>& enemy) {
    MovePreference pref = Cannot;
    if(GetClosestEnemy(enemy) != nullptr) {
        // Get the preference of the enemy to move to
        // Check if enemy can move left by checking if there is a lane on the left.
        if(enemy->getLane()->getPrevious() != nullptr) {
            // Check if on the left there is an enemy.
            enemy->MoveLeft();
            if(!IsCollision(enemy)) {
                pref = Left;
            }
            enemy->MoveRight();
        }
        // Check if enemy can move right by checking id there is a lane on the right.
        if(enemy->getLane()->getNext() != nullptr) {
            // Check if on the right there is an enemy.
            enemy->MoveRight();
            if(IsCollision(enemy)) {
                // Collision on the right. Now check if you could move left, if not preference is Cannot.
                if(pref != Left) {
                    pref = Cannot;
                }
            } else {
                // No Collision so can move. Both if pref was already left, Right if pref was cannot.
                if(pref == Left) {
                    pref = None;
                } else {
                    pref = Right;
                }
            }
            enemy->MoveLeft();
        }
        enemy->DoSomethingWhenYell(pref);
    }
    // If there is no closest enemy than that (not existing) enemy doesn't need to move
}

void turbohiker::World::CompetingAi(const std::shared_ptr<Enemy>& enemy) {
    if(std::dynamic_pointer_cast<Competing>(enemy) != nullptr) {
        if(GetClosestEnemy(enemy) != nullptr) {
            if(GetClosestEnemy(enemy)->GetBack().second - enemy->GetFront().second < 0.05) {
                CheckWhereToMove(enemy);
                enemy->setYell(false);
            }
        }
    }
}

const std::shared_ptr<turbohiker::Score> &turbohiker::World::getScore() const {
    return score;
}

void turbohiker::World::setScore(const std::shared_ptr<Score> &score) {
    World::score = score;
}

bool turbohiker::World::isStop() {
    for(const auto& entity: entities) {
        if(std::dynamic_pointer_cast<Player>(entity) != nullptr) {
            auto player = std::dynamic_pointer_cast<Player>(entity);
            if(checkFinished(player)) {
                player->NotifyObservers(Event::FINISHED);
                score->writeToFile(player_name);
                return true;
            } else {
                return false;
            }
        }
    }
}

const std::shared_ptr<AbstractFactory::Factory> &turbohiker::World::getConcreteFactory() const {
    return ConcreteFactory;
}

void turbohiker::World::setConcreteFactory(const std::shared_ptr<AbstractFactory::Factory> &concreteFactory) {
    ConcreteFactory = concreteFactory;
}
