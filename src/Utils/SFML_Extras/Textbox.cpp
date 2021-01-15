//
// Created by Sam Pieters on 02/01/2021.
//

#include "Textbox.h"

// TEXTBOX CLASS
void Textbox::setBackground(sf::Color filling, sf::Color outline, sf::Vector2f size)
{
        sf::RectangleShape back;
        back.setSize(sf::Vector2f(size.x, size.y));
        back.setOutlineColor(outline);
        back.setFillColor(filling);
        back.setOutlineThickness(2);
        back.setPosition(textbox.getPosition().x - 2, textbox.getPosition().y - 2);
        Textbox::background = back;
}

void Textbox::setFont(sf::Font& fonts) { textbox.setFont(fonts); }

void Textbox::setPosition(sf::Vector2f point) { textbox.setPosition(point); }

const sf::RectangleShape& Textbox::getBackground() const { return background; }

void Textbox::setBackground(const sf::RectangleShape& background) { Textbox::background = background; }

sf::Vector2f Textbox::getPosition()
{
        sf::Vector2f position = background.getPosition();
        position.x += 5;
        position.y += 5;
        return position;
}

void Textbox::setLimit(bool ToF) { hasLimit = ToF; }

void Textbox::setLimit(bool ToF, int lim)
{
        hasLimit = ToF;
        limit = lim - 1;
}

void Textbox::setSelected(bool sel)
{
        isSelected = sel;
        // If not selected, remove the '_' at the end:
        if (!sel) {
                std::string t = text.str();
                std::string newT = "";
                for (int i = 0; i < t.length(); i++) {
                        newT += t[i];
                }
                textbox.setString(newT);
        }
}

std::string Textbox::getText() { return text.str(); }

void Textbox::typedOn(sf::Event input)
{
        if (isSelected) {
                int charTyped = input.text.unicode;
                // Only allow normal inputs:
                if (charTyped < 128) {
                        auto a = textbox.getGlobalBounds();
                        // float width = textbox.getLocalBounds().width;
                        if (a.width >= background.getSize().x - 10 && charTyped != DELETE_KEY) {
                                inputLogic(10);
                        }
                        if (hasLimit) {
                                // If there's a limit, don't go over it:
                                if (text.str().length() <= limit) {
                                        inputLogic(charTyped);
                                }
                                // But allow for char deletions:
                                else if (text.str().length() > limit && charTyped == DELETE_KEY) {
                                        deleteLastChar();
                                }
                        } else if (a.height >= background.getSize().y - (textbox.getCharacterSize()) &&
                                   charTyped != DELETE_KEY) {
                        }
                        // If no limit exists, just run the function:
                        else {
                                inputLogic(charTyped);
                        }
                }
        }
}

void Textbox::deleteLastChar()
{
        std::string t = text.str();
        std::string newT = "";
        for (int i = 0; i < t.length() - 1; i++) {
                newT += t[i];
        }
        text.str("");
        text << newT;
        textbox.setString(text.str() + "_");
}

void Textbox::inputLogic(int charTyped)
{
        // If the key pressed isn't delete, or the two selection keys, then append the text with the char:
        if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
                text << static_cast<char>(charTyped);
        }
        // If the key is delete, then delete the char:
        else if (charTyped == DELETE_KEY) {
                if (text.str().length() > 0) {
                        deleteLastChar();
                }
        }
        // Set the textbox text:
        if (this->hasLimit) {
                if (this->limit == text.str().length()) {
                        textbox.setString(text.str());
                } else {
                        textbox.setString(text.str() + "_");
                        if (hidden) {
                                std::string secure;
                                for (auto& character : text.str()) {
                                        secure += '*';
                                }
                                textbox.setString(secure + "_");
                        }
                }
        } else {
                textbox.setString(text.str() + "_");
                if (hidden) {
                        std::string secure;
                        for (auto& character : text.str()) {
                                secure += '*';
                        }
                        textbox.setString(secure + "_");
                }
        }
}

void Textbox::setHidden(bool hidden) { Textbox::hidden = hidden; }

Textbox::Textbox(int size, sf::Color color, bool sel)
{
        textbox.setCharacterSize(size);
        textbox.setColor(color);
        isSelected = sel;

        // Check if the textbox is selected upon creation and display it accordingly:
        if (isSelected) {
                textbox.setString("_");
        } else {
                textbox.setString("");
        }
}

bool Textbox::isHasLimit() const { return hasLimit; }

int Textbox::getLimit() const { return limit; }

bool Textbox::isMouseOver(sf::Vector2i mouse)
{
        int btnPosX = background.getPosition().x - background.getOrigin().x;
        int btnPosY = background.getPosition().y - background.getOrigin().y;

        int btnxPosWidth = background.getPosition().x + background.getSize().x - background.getOrigin().x;
        int btnyPosHeight = background.getPosition().y + background.getSize().y - background.getOrigin().y;

        return mouse.x < btnxPosWidth && mouse.x > btnPosX && mouse.y < btnyPosHeight && mouse.y > btnPosY;
}

void Textbox::setText(const std::string& content) { textbox.setString(content); }

void Textbox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
        target.draw(this->background);
        target.draw(this->textbox);
}

void Textbox::setOrigin(sf::Vector2f point)
{
        textbox.setOrigin(point);
        background.setOrigin(point);
}
