//
// Created by Sam Pieters on 21/12/2020.
//

#include "Object.h"

sf::Texture Object::loadTextures(const std::string& fileName) {
    std::string temp = "./Resources/";
    std::string filepath = temp + fileName;
    sf::Texture texture;
    if (!texture.loadFromFile(filepath)){
        std::string exception = "Unable to load " + fileName + ", check the filename";
        throw std::runtime_error(exception);
    }
    return texture;
}

sf::Font Object::loadFont(const std::string& filename) {
    sf::Font font;
    if (!font.loadFromFile("Resources/Textures/" + filename)) {
        std::string exception = "Unable to load " + filename + ", check the filename";
        throw std::runtime_error(exception);
    }
    return font;
}

bool Object::isMouseOver(sf::Vector2i mouse, sf::Vector2f position, sf::Vector2f size) {
    return (mouse.x > position.x && mouse.x < (position.x + size.x) && mouse.y > position.y && mouse.y < (position.y + size.y));
}