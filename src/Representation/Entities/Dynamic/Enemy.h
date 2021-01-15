//
// Created by Sam Pieters on 04/12/2020.
//

#ifndef TURBOHIKERSFML_ENEMY_H
#define TURBOHIKERSFML_ENEMY_H

#include "../../../Logic/Entities/Dynamic/Enemy.h"
#include "../Entity.h"

#include <memory>

namespace turbohikerSFML {
class Enemy : public Entity
{
        std::shared_ptr<sf::SoundBuffer> buffer;
        std::shared_ptr<sf::Sound> sound;

public:
        Enemy(const std::string& texture);

        const std::shared_ptr<sf::SoundBuffer>& getBuffer() const;

        void setBuffer(const std::shared_ptr<sf::SoundBuffer>& buffer);

        const std::shared_ptr<sf::Sound>& getSound() const;

        void setSound(const std::shared_ptr<sf::Sound>& sound);
};

class Competing : public Enemy, public turbohiker::Competing
{
public:
        Competing();

        void display() override;
};

class Static : public Enemy, public turbohiker::Static
{
public:
        Static();

        void display() override;
};

class Attacking : public Enemy, public turbohiker::Attacking
{
public:
        Attacking();

        void display() override;
};
} // namespace turbohikerSFML

#endif // TURBOHIKERSFML_ENEMY_H