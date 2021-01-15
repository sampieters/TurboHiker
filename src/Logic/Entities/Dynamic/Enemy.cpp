/**
 * \brief Enemy classes are entities that block the player from moving.
 * \details Multiple derived enemy classes: 1) Static 2) Competing 3) Attacking that each do other movements and prompts
 *          in the world.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#include "Enemy.h"

turbohiker::Enemy::Enemy()
{
        // TODO:: NOG VERANDEREN NAAR ENEMY SPEED EN CONSTS VOOR MAKEN
        this->setSize(CONST::PLAYER::SIZE);
        this->setYell(false);
}

turbohiker::Enemy::Enemy(float chance) : MoveChance(chance)
{
        // TODO:: NOG VERANDEREN NAAR ENEMY SPEED EN CONSTS VOOR MAKEN
        this->setSize(CONST::PLAYER::SIZE);
        this->setYell(false);
}

float turbohiker::Enemy::getMoveChance() const { return MoveChance; }

void turbohiker::Enemy::setMoveChance(float moveChance) { MoveChance = moveChance; }

unsigned int turbohiker::Enemy::getScaredMeter() const { return scared_meter; }

void turbohiker::Enemy::setScaredMeter(unsigned int scaredMeter) { scared_meter = scaredMeter; }

Response turbohiker::Enemy::getResponse() const { return response; }

void turbohiker::Enemy::setResponse(Response response) { Enemy::response = response; }

turbohiker::Static::Static() : Enemy(CONST::ENEMIES::STATIC::MOVE_CHANCE)
{
        this->setSpeed(0);
        this->setScaredMeter(CONST::ENEMIES::STATIC::STRENGTH);
        this->setType(EntityType::Static);
}

void turbohiker::Static::DoSomethingWhenYell(MovePreference preference)
{
        int chance = RandomNumberGenerator::Getinstance().generate_int(0, 100);
        if (chance > this->getMoveChance() && preference != Cannot) {
                // MOVE
                if (preference == None) {
                        if (chance > (this->getMoveChance() / 2)) {
                                // Move in 50% of the cases to the right and other to the left
                                this->MoveRight();
                        } else {
                                this->MoveLeft();
                        }
                } else if (preference == Left) {
                        this->MoveLeft();
                } else if (preference == Right) {
                        this->MoveRight();
                }
                this->setResponse(Obey);
        } else {
                this->setResponse(Defy);
        }
        this->setYell(true);
}

turbohiker::Competing::Competing() : Enemy(CONST::ENEMIES::COMPETING::MOVE_CHANCE)
{
        this->setSpeed(CONST::ENEMIES::COMPETING::MIN_SPEED);
        this->setScaredMeter(CONST::ENEMIES::STATIC::STRENGTH);
        this->setType(EntityType::Competing);
}

void turbohiker::Competing::DoSomethingWhenYell(MovePreference preference)
{
        int chance = RandomNumberGenerator::Getinstance().generate_int(0, 100);
        if (chance > this->getMoveChance() && preference != Cannot) {
                // MOVE
                if (preference == None) {
                        if (chance > (this->getMoveChance() / 2)) {
                                // Move in 50% of the cases to the right and other to the left
                                this->MoveRight();
                        } else {
                                this->MoveLeft();
                        }
                } else if (preference == Left) {
                        this->MoveLeft();
                } else if (preference == Right) {
                        this->MoveRight();
                }
                this->setResponse(Obey);
        } else {
                this->setResponse(Defy);
        }
        this->setYell(true);
}

turbohiker::Attacking::Attacking() : Enemy(CONST::ENEMIES::ATTACKING::MOVE_CHANCE)
{
        this->setSpeed(-CONST::ENEMIES::ATTACKING::MIN_SPEED);
        this->setScaredMeter(CONST::ENEMIES::ATTACKING::STRENGTH);
        this->setType(EntityType::Attacking);
}

void turbohiker::Attacking::DoSomethingWhenYell(MovePreference preference)
{
        int chance = RandomNumberGenerator::Getinstance().generate_int(0, 100);
        if (chance > this->getMoveChance()) {
                // SLOWDOWN
                this->SlowDown();
                this->setResponse(Obey);
        } else {
                this->setResponse(Defy);
        }
        this->setYell(true);
}
