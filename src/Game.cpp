/**
 * \brief Classes to handle game and game state.
 * \author Sam Pieters
 * \date 24 December 2020
 */

#include "Game.h"
#include <src/Utils/SFML_Extras/Textbox.h>

#define FRAMERATE 120                       // Framerate: The number of max loops in one second
#define TIME_PER_CYCLE (1000.0 / FRAMERATE) // Time for one loop

void T_State::run()
{
        double elapsedSeconds = 0;
        StopWatch::Getinstance().Start();
        while (this->context_->getWindow()->isOpen()) {
                if (StopWatch::Getinstance().GetElapsedTime() < TIME_PER_CYCLE) {
                        continue;
                }
                processEvents();
                update(elapsedSeconds);
                render();
                // Restart the timer
                elapsedSeconds = StopWatch::Getinstance().GetElapsedTime() * 0.001;
                StopWatch::Getinstance().Reset();
        }
}

void T_State::update(double elapsedTime) {}

void T_State::render()
{
        this->context_->getWindow()->clear();
        for (const auto& drawable : this->getGuiObjects()) {
                this->context_->getWindow()->draw(*drawable);
        }
        this->context_->getWindow()->display();
}

void T_State::processEvents() {}

const std::shared_ptr<sf::Font>& T_State::getGuiFont() const { return gui_font; }

void T_State::setGuiFont(const std::shared_ptr<sf::Font>& guiFont) { gui_font = guiFont; }

const std::shared_ptr<sf::Music>& T_State::getGuiSound() const { return gui_sound; }

void T_State::setGuiSound(const std::shared_ptr<sf::Music>& guiSound) { gui_sound = guiSound; }

const std::vector<std::shared_ptr<sf::Drawable>>& T_State::getGuiObjects() const { return gui_objects; }

void T_State::setGuiObjects(const std::vector<std::shared_ptr<sf::Drawable>>& guiObjects) { gui_objects = guiObjects; }

void T_State::set_context(std::shared_ptr<T_Game> context) { this->context_ = std::move(context); }

void T_State::init() {}

T_Game::T_Game(const std::shared_ptr<T_State>& state) : state_(state)
{
        try {
                window = std::make_shared<sf::RenderWindow>(sf::VideoMode(CONST::WINDOW::WIDTH, CONST::WINDOW::HEIGHT),
                                                            "TurboHiker");
                Transformation::Getinstance().SetWindowSize(CONST::WINDOW::WIDTH, CONST::WINDOW::HEIGHT);
                this->TransitionTo(state);
                this->Request_Next();
        } catch (exceptions::MyException& MyExcecption) {
                std::cerr << "An internal exception occured: " << MyExcecption.what() << std::endl;
        } catch (...) {
                std::cerr << "An unknown exception occured" << std::endl;
        }
}

T_Game::~T_Game() = default;

const std::string& T_Game::getPlayerName() const { return player_name; }

void T_Game::setPlayerName(const std::string& playerName) { player_name = playerName; }

bool T_Game::isRunning() const { return running; }

void T_Game::setRunning(bool running) { T_Game::running = running; }

void T_Game::setPreviousState(const std::shared_ptr<T_State>& previousState) { previous_state_ = previousState; }

const std::shared_ptr<T_State>& T_Game::getPreviousState() const { return previous_state_; }

void T_Game_Menu::init()
{
        if (this->context_ == nullptr) {
                throw exceptions::NullptrException(
                    "Game state or Window is not initialized correctly, leading to a nullptr");
        }

        std::shared_ptr<Background> background = std::make_shared<Background>("background.png");

        std::shared_ptr<sf::Music> music = std::make_shared<sf::Music>();
        music->openFromFile("./Resources/theme.wav");
        music->setLoop(true);
        music->setVolume(50.0f);
        music->play();

        std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
        font->loadFromFile("Resources/BalooBhai-Gujarati.ttf");
        this->setGuiFont(font);

        sf::Vector2f button_size = {static_cast<float>(this->context_->getWindow()->getSize().x / 4),
                                    static_cast<float>(this->context_->getWindow()->getSize().y / 8)};
        Button button_1("play", button_size, 20, sf::Color::White, sf::Color::Transparent);
        std::shared_ptr<Button> play = std::make_shared<Button>(button_1);
        play->setTexture("Play_Button.png");
        play->setOrigin({(play->getSize().x / 2), (play->getSize().y / 2)});
        play->setPosition({static_cast<float>(this->context_->getWindow()->getSize().x / 2),
                           static_cast<float>(this->context_->getWindow()->getSize().y / 2)});

        std::shared_ptr<Textbox> wow = std::make_shared<Textbox>(40, sf::Color::White, false);
        wow->setPosition({play->getPosition().x, play->getPosition().y - play->getSize().y - 5});
        wow->setFont(*this->getGuiFont());
        wow->setBackground(sf::Color::Transparent, sf::Color::White, {700, 60});
        wow->setOrigin({(wow->getBackground().getSize().x / 2), (wow->getBackground().getSize().y / 2)});
        wow->setText("");
        wow->setLimit(true, 20);

        this->setGuiSound(music);
        this->setGuiObjects({background, play, wow});
}

void T_Game_Menu::processEvents()
{
        sf::Event event{};
        while (this->context_->getWindow()->pollEvent(event)) {
                switch (event.type) {
                case sf::Event::Closed:
                        this->context_->getWindow()->close();
                        break;
                case sf::Event::Resized:
                        this->context_->getWindow()->setView(
                            sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
                        break;
                case sf::Event::LostFocus:
                        break;
                case sf::Event::GainedFocus:
                        break;

                case sf::Event::TextEntered:
                        for (const auto& object : this->getGuiObjects()) {
                                if (std::dynamic_pointer_cast<Textbox>(object) != nullptr) {
                                        auto textbox = std::dynamic_pointer_cast<Textbox>(object);
                                        textbox->typedOn(event);
                                }
                        }
                case sf::Event::MouseButtonPressed:
                        if (event.mouseButton.button == sf::Mouse::Left) {
                                sf::Vector2i position = sf::Mouse::getPosition(*this->context_->getWindow());
                                for (const auto& object : this->getGuiObjects()) {
                                        if (std::dynamic_pointer_cast<Button>(object) != nullptr) {
                                                auto button = std::dynamic_pointer_cast<Button>(object);
                                                if (button->isMouseOver(position)) {
                                                        button->layoutclick(true, 2);
                                                        this->getGuiSound()->stop();
                                                        std::string test = button->getText();
                                                        if (button->getText() == "play") {
                                                                for (const auto& object : this->getGuiObjects()) {
                                                                        if (std::dynamic_pointer_cast<Textbox>(
                                                                                object) != nullptr) {
                                                                                auto textbox =
                                                                                    std::dynamic_pointer_cast<Textbox>(
                                                                                        object);
                                                                                if (!textbox->getText().empty()) {
                                                                                        this->context_->setPlayerName(
                                                                                            textbox->getText());
                                                                                        this->context_->TransitionTo(
                                                                                            std::make_shared<
                                                                                                T_Game_Play>());
                                                                                        this->context_
                                                                                            ->setPreviousState(
                                                                                                std::make_shared<
                                                                                                    T_Game_Menu>());
                                                                                        this->context_->Request_Next();
                                                                                        return;
                                                                                } else {
                                                                                        // TODO:: DISPLAY THERE HAS TO
                                                                                        // BE A NAME
                                                                                }
                                                                                break;
                                                                        }
                                                                }
                                                        }
                                                }
                                        }
                                        if (std::dynamic_pointer_cast<Textbox>(object) != nullptr) {
                                                auto textbox = std::dynamic_pointer_cast<Textbox>(object);
                                                textbox->setSelected(textbox->isMouseOver(position));
                                        }
                                }
                        }
                        break;
                }
        }
}

void T_Game_Play::init()
{
        if (this->context_ == nullptr) {
                throw exceptions::NullptrException(
                    "Game state or Window is not initialized correctly, leading to a nullptr");
        }

        std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
        font->loadFromFile("Resources/BalooBhai-Gujarati.ttf");
        this->setGuiFont(font);

        if (!this->context_->isRunning()) {
                auto wow = std::make_shared<AbstractFactorySFML::Factory>();
                wow->window = this->context_->getWindow();
                this->context_->setWorld(
                    std::dynamic_pointer_cast<turbohiker::World>(wow->CreateWorld(this->context_->getPlayerName())));
                this->context_->getWorld()->setConcreteFactory(wow);
                this->context_->getWorld()->InitWorld();

                std::shared_ptr<sf::Text> countdown = std::make_shared<sf::Text>();
                countdown->setFont(*this->getGuiFont());
                countdown->setCharacterSize(100);
                countdown->setString("3");
                countdown->setOrigin(countdown->getGlobalBounds().width / 2, countdown->getGlobalBounds().height / 2);
                countdown->setPosition({static_cast<float>(this->context_->getWindow()->getSize().x / 2), 800});
                this->setGuiObjects({countdown});
        }
        std::shared_ptr<sf::Music> music = std::make_shared<sf::Music>();
        music->openFromFile("./Resources/run.wav");
        music->setLoop(true);
        music->setVolume(50.0f);
        music->play();
        this->setGuiSound(music);
}

void T_Game_Play::run()
{
        double elapsedSeconds = 0;
        StopWatch::Getinstance().Start();
        while (this->context_->getWindow()->isOpen()) {
                if (StopWatch::Getinstance().GetElapsedTime() < TIME_PER_CYCLE) {
                        continue;
                }
                this->context_->getWorld()->handleStates(elapsedSeconds);
                processEvents();
                update(elapsedSeconds);
                render();

                if (this->context_->getWorld()->isStop()) {
                        this->context_->setWindow(std::make_shared<sf::RenderWindow>(
                            sf::VideoMode(CONST::WINDOW::WIDTH, CONST::WINDOW::HEIGHT), "TurboHiker"));
                        this->context_->getWindow()->setSize({CONST::WINDOW::WIDTH, CONST::WINDOW::HEIGHT});
                        this->getGuiSound()->stop();
                        this->context_->TransitionTo(std::make_shared<T_Game_Scoreboard>());
                        this->context_->Request_Next();
                        return;
                }
                // Restart the timer
                elapsedSeconds = StopWatch::Getinstance().GetElapsedTime() * 0.001;
                ;
                StopWatch::Getinstance().Reset();
        }
}

void T_Game_Play::processEvents()
{
        sf::Event event{};
        while (this->context_->getWindow()->pollEvent(event)) {
                switch (event.type) {
                case sf::Event::Closed:
                        this->context_->getWindow()->close();
                        break;
                case sf::Event::Resized:
                        break;
                case sf::Event::LostFocus:
                        this->getGuiSound()->stop();
                        // this->context_->TransitionTo(std::make_shared<T_Game_Settings>());
                        // this->context_->Request_Next();
                        break;
                case sf::Event::GainedFocus:
                        break;
                case sf::Event::KeyPressed:
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                                this->context_->getWorld()->handlePlayerInput(Z, true);
                        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                                this->context_->getWorld()->handlePlayerInput(Q, true);
                        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                                this->context_->getWorld()->handlePlayerInput(S, true);
                        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                                this->context_->getWorld()->handlePlayerInput(D, true);
                        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                                this->context_->getWorld()->handlePlayerInput(SPACE, true);
                        }
                        break;
                case sf::Event::KeyReleased:
                        this->context_->getWorld()->handlePlayerInput(Z, false);
                        break;
                }
        }
}

void T_Game_Play::update(double elapsedTime)
{
        static float Seconds = 0;
        static bool timer = true;
        static bool runOnce = false;
        if (timer) {
                if (!runOnce) {
                        this->context_->getWorld()->update(elapsedTime);
                        runOnce = true;
                }
                auto countdown = std::dynamic_pointer_cast<sf::Text>(this->getGuiObjects()[0]);
                std::string whut = countdown->getString();
                int i = std::stoi(whut);
                Seconds += (StopWatch::Getinstance().GetElapsedTime() * 0.001);
                if (i == 0) {
                        timer = false;
                        this->setGuiObjects({});
                        this->context_->setRunning(true);
                }
                if (Seconds > (1.0) && i != 0) {
                        i -= 1;
                        countdown->setString(std::to_string(i));
                        Seconds = 0;
                }
        } else {
                this->context_->getWorld()->update(elapsedTime);
        }
}

void T_Game_Play::render()
{
        this->context_->getWindow()->clear();
        this->context_->getWorld()->display();
        for (const auto& drawable : this->getGuiObjects()) {
                this->context_->getWindow()->draw(*drawable);
        }
        this->context_->getWindow()->display();
}

void T_Game_Scoreboard::init()
{
        if (this->context_ == nullptr) {
                throw exceptions::NullptrException(
                    "Game state or Window is not initialized correctly, leading to a nullptr");
        }

        std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
        font->loadFromFile("Resources/BalooBhai-Gujarati.ttf");
        this->setGuiFont(font);

        // Background
        std::shared_ptr<Background> background = std::make_shared<Background>("Score_background.jpg");

        std::shared_ptr<sf::Text> score = std::make_shared<sf::Text>();
        score->setString(turbohiker::Score::ReadFile());
        score->setFont(*this->getGuiFont());
        score->setCharacterSize(60);
        score->setFillColor(sf::Color::Red);
        score->setOrigin((score->getGlobalBounds().width / 2), (score->getGlobalBounds().height / 2));
        score->setPosition((this->context_->getWindow()->getSize().x / 2),
                           (this->context_->getWindow()->getSize().y / 2));

        this->setGuiObjects({background, score});
}

void T_Game_Scoreboard::processEvents()
{
        sf::Event event{};
        while (this->context_->getWindow()->pollEvent(event)) {
                switch (event.type) {
                case sf::Event::Closed:
                        this->context_->getWindow()->close();
                        break;
                case sf::Event::Resized:
                        this->context_->getWindow()->setView(
                            sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
                        break;
                case sf::Event::LostFocus:
                        break;
                case sf::Event::GainedFocus:
                        break;
                case sf::Event::MouseButtonPressed:
                        break;
                }
        }
}
