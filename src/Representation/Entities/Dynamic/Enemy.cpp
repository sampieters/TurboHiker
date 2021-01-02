//
// Created by Sam Pieters on 04/12/2020.
//

#include "Enemy.h"

turbohikerSFML::Enemy::Enemy(const std::string& texture): turbohikerSFML::Entity(texture) {
    std::shared_ptr<sf::Sound> yell = std::make_shared<sf::Sound>();
    std::shared_ptr<sf::SoundBuffer> buff = std::make_shared<sf::SoundBuffer>();
    setSound(yell);
    setBuffer(buff);
}

const std::shared_ptr<sf::SoundBuffer> &turbohikerSFML::Enemy::getBuffer() const {
    return buffer;
}

void turbohikerSFML::Enemy::setBuffer(const std::shared_ptr<sf::SoundBuffer> &buffer) {
    Enemy::buffer = buffer;
}

const std::shared_ptr<sf::Sound> &turbohikerSFML::Enemy::getSound() const {
    return sound;
}

void turbohikerSFML::Enemy::setSound(const std::shared_ptr<sf::Sound> &sound) {
    Enemy::sound = sound;
}

turbohikerSFML::Competing::Competing(): turbohikerSFML::Enemy("savitar/savitar.png") {}

void turbohikerSFML::Competing::display() {
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

    if(this->isYell()) {
        sf::Sprite balloon;
        sf::Texture text_1;
        text_1.loadFromFile("Resources/savitar/savitar_textballoon.png");
        balloon.setTexture(text_1);
        balloon.setOrigin(0, balloon.getTextureRect().height);
        balloon.setPosition(D_Pos.first, D_Pos.second);
        // Set Textballoon right above the player
        balloon.setScale(0.4, 0.4);

        sf::Font font;
        font.loadFromFile("Resources/BalooBhai-Gujarati.ttf");
        sf::Text text;
        text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2);
        text.setFont(font);

        std::string file = "Resources/savitar/";
        if(this->getResponse() == Obey) {
            text.setString("Yes, sir!");
            file += "Obey";
        }
        else if(this->getResponse() == Defy) {
            text.setString("Fock u!");
            file += "Defy";
        }
        else if(this->getResponse() == Pain) {
            text.setString("Auwwiiee");
            file += "Pain";
        }
        else if(this->getResponse() == Die) {
            text.setString("Dead");
            file += "Die";
        }
        if(getSound()->getStatus() != sf::SoundSource::Status::Playing) {
            getBuffer()->loadFromFile(file + ".wav");
            getSound()->setBuffer(*getBuffer());
            getSound()->play();
        }

        text.setFillColor(sf::Color(71, 159, 248));
        text.setCharacterSize(20);
        text.setPosition(balloon.getPosition().x, balloon.getPosition().y);

        sf::FloatRect rectBounds = balloon.getGlobalBounds();
        sf::FloatRect textBounds = text.getGlobalBounds();

        text.setPosition(rectBounds.left + (rectBounds.width / 2) - (textBounds.width / 2),
                         rectBounds.top + (rectBounds.height / 2) - textBounds.height
        );

        getWindowToDrawTo()->draw(balloon);
        getWindowToDrawTo()->draw(text);
    }
    getWindowToDrawTo()->draw(new_sprite);
}

turbohikerSFML::Static::Static(): turbohikerSFML::Enemy("zoom/zoom.png") {
}

void turbohikerSFML::Static::display() {
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
    getWindowToDrawTo()->draw(new_sprite);

    if(this->isYell()) {
        sf::Sprite balloon;
        sf::Texture text_1;
        text_1.loadFromFile("Resources/zoom/zoom_textballoon.png");
        balloon.setTexture(text_1);
        balloon.setOrigin(0, balloon.getTextureRect().height);
        balloon.setPosition(D_Pos.first, D_Pos.second);
        // Set Textballoon right above the player
        balloon.setScale(0.4, 0.4);

        sf::Font font;
        font.loadFromFile("Resources/BalooBhai-Gujarati.ttf");
        sf::Text text;
        text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2);
        text.setFont(font);

        std::string file = "Resources/zoom/";
        if(this->getResponse() == Obey) {
            text.setString("Yes, sir!");
            file += "Obey";
        }
        else if(this->getResponse() == Defy) {
            text.setString("Fock u!");
            file += "Defy";
        }
        else if(this->getResponse() == Pain) {
            text.setString("Auwwiiee");
            file += "Pain";
        }
        else if(this->getResponse() == Die) {
            text.setString("Dead");
            file += "Die";
        }
        if(getSound()->getStatus() != sf::SoundSource::Status::Playing) {
            getBuffer()->loadFromFile(file + ".wav");
            getSound()->setBuffer(*getBuffer());
            getSound()->play();
        }

        text.setFillColor(sf::Color(71, 159, 248));
        text.setCharacterSize(20);
        text.setPosition(balloon.getPosition().x, balloon.getPosition().y);

        sf::FloatRect rectBounds = balloon.getGlobalBounds();
        sf::FloatRect textBounds = text.getGlobalBounds();

        text.setPosition(rectBounds.left + (rectBounds.width / 2) - (textBounds.width / 2),
                         rectBounds.top + (rectBounds.height / 2) - textBounds.height
        );

        getWindowToDrawTo()->draw(balloon);
        getWindowToDrawTo()->draw(text);
    }
    getWindowToDrawTo()->draw(new_sprite);
}

turbohikerSFML::Attacking::Attacking(): turbohikerSFML::Enemy("reverse/reverse.png") {}

void turbohikerSFML::Attacking::display() {
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
    getWindowToDrawTo()->draw(new_sprite);

    if(this->isYell()) {
        sf::Sprite balloon;
        sf::Texture text_1;
        text_1.loadFromFile("Resources/reverse/reverse_textballoon.png");
        balloon.setTexture(text_1);
        balloon.setOrigin(0, balloon.getTextureRect().height);
        balloon.setPosition(D_Pos.first, D_Pos.second);
        // Set Textballoon right above the player
        balloon.setScale(0.4, 0.4);

        sf::Font font;
        font.loadFromFile("Resources/BalooBhai-Gujarati.ttf");
        sf::Text text;
        text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2);
        text.setFont(font);

        std::string file = "Resources/reverse/";
        if(this->getResponse() == Obey) {
            text.setString("Yes, sir!");
            file += "Obey";
        }
        else if(this->getResponse() == Defy) {
            text.setString("Fock u!");
            file += "Defy";
        }
        else if(this->getResponse() == Pain) {
            text.setString("Auwwiiee");
            file += "Pain";
        }
        else if(this->getResponse() == Die) {
            text.setString("Dead");
            file += "Die";
        }
        if(getSound()->getStatus() != sf::SoundSource::Status::Playing) {
            getBuffer()->loadFromFile(file + ".wav");
            getSound()->setBuffer(*getBuffer());
            getSound()->play();
        }

        text.setFillColor(sf::Color::Black);
        text.setCharacterSize(20);
        text.setPosition(balloon.getPosition().x, balloon.getPosition().y);

        sf::FloatRect rectBounds = balloon.getGlobalBounds();
        sf::FloatRect textBounds = text.getGlobalBounds();

        text.setPosition(rectBounds.left + (rectBounds.width / 2) - (textBounds.width / 2),
                         rectBounds.top + (rectBounds.height / 2) - textBounds.height
        );

        getWindowToDrawTo()->draw(balloon);
        getWindowToDrawTo()->draw(text);
    }
    getWindowToDrawTo()->draw(new_sprite);
}