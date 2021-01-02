//
// Created by Sam Pieters on 14/12/2020.
//

#include "Camera.h"

#include <utility>


turbohikerSFML::Camera::Camera(std::shared_ptr<turbohiker::Score> score, std::shared_ptr<turbohiker::Player> player, const std::shared_ptr<sf::RenderWindow>& window): turbohikerSFML::Entity("camera.png"), turbohiker::Camera(std::move(score), std::move(player)) {
    setWindowToDrawTo(window);
}

void turbohikerSFML::Camera::display() {
    sf::Sprite new_sprite = getSprite();

    new_sprite.setOrigin(static_cast<float>(new_sprite.getTextureRect().width) / 2,static_cast<float>(new_sprite.getTextureRect().height / 2));
    // transform the width and height of the object to width and height
    auto S_Width = new_sprite.getTextureRect().width;
    auto S_Height = new_sprite.getTextureRect().height;

    std::pair<float, float> D_Size = {this->getSize().first, this->getSize().second};
    std::pair<float, float> D_Pos = {this->getPosition().first, this->getPosition().second};

    Transformation::Getinstance().convert(D_Pos, D_Size);

    new_sprite.setScale(D_Size.first / S_Width, D_Size.second / S_Height);
    new_sprite.setPosition(D_Pos.first, D_Pos.second);
    new_sprite.setTexture(getTexture());

    /////////////////////////////////////////////////////
    //TODO:: DIT VOOR CAMERA
    ////////////////////////////////////////////////////
    sf::View view = this->getWindowToDrawTo()->getView();
    view.setSize(D_Size.first, D_Size.second);
    view.setCenter(D_Pos.first,D_Pos.second);
    this->getWindowToDrawTo()->setView(view);
    /////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////


    sf::Font font;
    font.loadFromFile("Resources/BalooBhai-Gujarati.ttf");

    sf::Text score_1;
    score_1.setString(std::to_string(this->getScore()->getScore()));
    score_1.setPosition(new_sprite.getPosition().x - (new_sprite.getGlobalBounds().width/2) + 30, new_sprite.getGlobalBounds().top + 5);
    score_1.setFont(font);
    score_1.setCharacterSize(40);
    score_1.setFillColor(sf::Color::Red);


    getWindowToDrawTo()->draw(new_sprite);
    getWindowToDrawTo()->draw(score_1);
}
