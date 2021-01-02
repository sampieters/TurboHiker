//
// Created by Sam Pieters on 01/12/2020.
//

#include "Entity.h"



const sf::Texture &turbohikerSFML::Entity::getTexture() const {
    return texture;
}

void turbohikerSFML::Entity::setTexture(const sf::Texture &texture) {
    Entity::texture = texture;
}

const sf::Sprite &turbohikerSFML::Entity::getSprite() const {
    return sprite;
}

void turbohikerSFML::Entity::setSprite(const sf::Sprite &sprite) {
    Entity::sprite = sprite;
}

void turbohikerSFML::Entity::setWindowToDrawTo(const std::shared_ptr<sf::RenderWindow> &windowToDrawTo) {
    WindowToDrawTo = windowToDrawTo;
}

const std::shared_ptr<sf::RenderWindow> &turbohikerSFML::Entity::getWindowToDrawTo() const {
    return WindowToDrawTo;
}

turbohikerSFML::Entity::Entity(const std::string& texture) {
    sf::Texture text;
    if (!text.loadFromFile("Resources/" + texture)) {
        std::cerr << "Could not load" << std::endl;
    }
    this->setTexture(text);
    sf::Sprite sprit;
    sprit.setTexture(text);
    this->setSprite(sprit);
}
