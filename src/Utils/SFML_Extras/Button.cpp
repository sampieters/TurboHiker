//
// Created by Sam Pieters on 21/12/2020.
//

#include "Button.h"

// BUTTON CLASS
// 1) BUTTON LAYOUT
// 1.1) Constructors
Button::Button(const std::string& content, sf::Vector2f B_Size, int T_Size, sf::Color B_Color, sf::Color T_Color) {
    // Set everything ready for the Button
    button.setSize(B_Size);
    button.setFillColor(B_Color);
    // Set everything ready for the Text in the Button
    text.setString(content);
    text.setCharacterSize(T_Size);
    text.setFillColor(T_Color);
    // Set text in the middle of Button
   // text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2);
    //text.setPosition(button.getPosition().x, button.getPosition().y);
    text.setPosition(button.getPosition().x + (button.getSize().x/2) - (text.getGlobalBounds().width/2), button.getPosition().y + (button.getSize().y/2) - (text.getGlobalBounds().height/2));
}

Button::Button(sf::Vector2f B_Position, sf::Vector2f B_Size, sf::Color B_Color) {
    button.setPosition(B_Position);
    button.setSize(B_Size);
    button.setFillColor(B_Color);
    // There is no text
    text.setString("");
}

// 1.2) ButtonColor
void Button::setButtonColor(sf::Color color) {
    button.setFillColor(color);
}

sf::Color Button::getButtonColor() {
    return button.getFillColor();
}

void Button::setTexture(const std::string& texture) {
    sf::Texture textur = Object::loadTextures(texture);
    this->texture = textur;
    button.setTexture(&this->texture);
}

const sf::Texture* Button::getTexture() {
    return button.getTexture();
}


// 1.3) Position
void Button::setPosition(sf::Vector2f point) {
    button.setPosition(point);
    // Set text back to middle of button
    text.setPosition(point);

}

sf::Vector2f Button::getPosition() {
    return button.getPosition();
}

// 1.4) OutlineColor
void Button::setOutlineColor(sf::Color color) {
    button.setOutlineColor(color);
}

sf::Color Button::getOutlineColor() {
    return button.getOutlineColor();
}

void Button::setOutlineSize(float size) {
    button.setOutlineThickness(size);
}

float Button::getOutlineSize() {
    return button.getOutlineThickness();
}

void Button::layoutclick(bool clicked, float clickdepth, sf::Color color) {
    if (clicked) {
        sf::Sound sound;
        sound.setBuffer(click);
        sound.play();
        button.setOutlineColor(color);
        button.setOutlineThickness(clickdepth);
    } else {
        //TODO: if before already outlinecolor, then setback to that color
        button.setOutlineColor(button.getFillColor());
    }

}

// 2) TEXT LAYOUT
void Button::setFont(sf::Font &fonts) {
    text.setFont(fonts);
}

void Button::setFontSize(unsigned int size) {
    text.setCharacterSize(size);
}

sf::Vector2f Button::getSize() {
    return button.getSize();
}

void Button::setSize(sf::Vector2f size) {
    button.setSize(size);
}

// 3) TRANSFORMATIONS
void Button::CenterHorizontal(sf::RenderWindow &window) {
    this->setPosition({((float)window.getSize().x/2) - (getSize().x/2), getPosition().y});
}

void Button::CenterVertical(sf::RenderWindow &window) {
    this->setPosition({getPosition().x, ((float)window.getSize().y/2) - (getSize().y/2)});
}


void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->button);
    target.draw(this->text);
}

void Button::setOrigin(sf::Vector2f point) {
    button.setOrigin(point);
}

sf::Vector2f Button::getOrigin() {
    return this->button.getOrigin();
}

void Button::setClickSound(sf::SoundBuffer buffer) {
    click = buffer;
}


bool Button::isMouseOver(sf::Vector2i mouse) {
    return (
            mouse.x > (getPosition().x - getOrigin().x) &&
            mouse.x < (getPosition().x + getSize().x - getOrigin().x) &&

            mouse.y > (getPosition().y - getOrigin().y) &&
            mouse.y < (getPosition().y + getSize().y - getOrigin().y)
    );
}

std::string Button::getText() const {
    std::string wow = text.getString();
    return wow;
}

void Button::setText(const std::string& text) {
    Button::text.setString(text);
}

void Background::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(spirte);
}

Background::Background(std::string texture) {
    sf::Texture text = Object::loadTextures(texture);
    this->texture = std::make_shared<sf::Texture>(text);
    spirte.setTexture(*this->texture);
}

void Scoreboard::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}