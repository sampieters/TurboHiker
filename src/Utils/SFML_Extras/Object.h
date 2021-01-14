//
// Created by Sam Pieters on 21/12/2020.
//

#ifndef TURBOHIKER_OBJECT_H
#define TURBOHIKER_OBJECT_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Main.hpp>
#include <SFML/Audio.hpp>
#include <memory>

class Object {
private:
    std::shared_ptr<sf::Shape> box;
public:
    static sf::Texture loadTextures(const std::string& fileName);
    sf::Font loadFont(const std::string& filename);
    static bool isMouseOver(sf::Vector2i mouse, sf::Vector2f position, sf::Vector2f size);
};


#endif //TURBOHIKER_OBJECT_H
