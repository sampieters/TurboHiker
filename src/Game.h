/**
 * \brief Classes to handle game and game state.
 * \author Sam Pieters
 * \date 24 December 2020
 */

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "src/Exceptions/MyException.h"
#include "src/Exceptions/NullptrException.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <memory>
#include <utility>

#include "Logic/Entities/Static/Score.h"
#include "Logic/Entities/Static/World.h"
#include "Representation/Factories/AbstractFactory.h"
#include "Singletons/StopWatch.h"
#include "Singletons/Transformation.h"
#include "Utils/Enum.h"
#include "src/Utils/SFML_Extras/Button.h"
#include "src/Utils/SFML_Extras/Object.h"
#include "src/Utils/SFML_Extras/Textbox.h"

class T_Game;

/** \class T_State Game.h "src/Game.h"
 * \brief State the game is in (example: Main menu, Stop, Play, ...).
 * \details Every state has gui objects, sound, font because when not a member of
 *          the class and only initialized in a function, it gets destroyed when
 *          going out of scope. Becase of that is can't draw or play the object
 *          (music, drawable) anymore and thus would not be visible.
 */
class T_State
{
protected:
        std::shared_ptr<T_Game> context_;

private:
        std::shared_ptr<sf::Font> gui_font;
        std::shared_ptr<sf::Music> gui_sound;
        std::vector<std::shared_ptr<sf::Drawable>> gui_objects;

public:
        /**
         * \brief Default destructor for the game.
         */
        virtual ~T_State() = default;

        /**
         * \brief Initializes everything needed for the current state of the game.
         */
        virtual void init();

        /**
         * \brief Runs the current state
         * \details Run fucntion is virtual, virtual run-fucntion consists of function processEvents, update, render
         * unless said otherwise in an override.
         */
        virtual void run();

        /**
         * \brief Processes the events (keyboard, window, ...) given by the user.
         */
        virtual void processEvents();

        /**
         * \brief Updates everything in the given state.
         * \details This function updates everything that does not need an event
         *          (because that is already done in processEvents).
         * \param elapsedTime: This is a double which is the elapsed time of one frame.
         */
        virtual void update(double elapsedTime);

        /**
         * \brief Resets the window, draws everything (updated) on the window and displays it.
         */
        virtual void render();

        /**
         * Getters and Setters
         */
        const std::shared_ptr<sf::Font>& getGuiFont() const;

        void setGuiFont(const std::shared_ptr<sf::Font>& guiFont);

        const std::shared_ptr<sf::Music>& getGuiSound() const;

        void setGuiSound(const std::shared_ptr<sf::Music>& guiSound);

        const std::vector<std::shared_ptr<sf::Drawable>>& getGuiObjects() const;

        void setGuiObjects(const std::vector<std::shared_ptr<sf::Drawable>>& guiObjects);

        void set_context(std::shared_ptr<T_Game> context);
};

/** \class T_Game Game.h "src/Game.h"
 * \brief This class is the game itself.
 */
class T_Game : public std::enable_shared_from_this<T_Game>
{
private:
        /** \brief world_ is nullptr until the state is T_Play_State. */
        std::shared_ptr<turbohiker::World> world_;
        /** \brief window is the window to draw to. */
        std::shared_ptr<sf::RenderWindow> window;
        /** \brief previous_state_ is only usefull for going back when in Settings_state or Scoreboard_State. */
        std::shared_ptr<T_State> previous_state_;
        /** \brief state_ is the state currently in. */
        std::shared_ptr<T_State> state_;
        /** \brief player_name only usefull for the scoreboard. */
        std::string player_name;
        /** \brief running is a variable that checks if game is still running.. */
        bool running;
        std::vector<std::string> keys;

public:
        /**
         * \brief Default constructor for the game.
         * \param state: state the game starts in when opened.
         */
        explicit T_Game(const std::shared_ptr<T_State>& state);

        /**
         * \brief Default destructor for the game.
         */
        ~T_Game();

        /**
         * The Context allows changing the State object at runtime.
         */
        void TransitionTo(const std::shared_ptr<T_State>& state)
        {
                auto wptr = std::shared_ptr<T_Game>(this, [](T_Game*) {});
                this->state_ = state;
                this->state_->set_context(this->shared_from_this());

                if (this->state_ == nullptr || this->window == nullptr) {
                        throw exceptions::NullptrException(
                            "Game state is not initialized correctly, leading to a nullptr");
                }
        }

        /**
         * The Context delegates part of its behavior to the current State object.
         */
        void Request_Next()
        {
                this->state_->init();
                this->state_->run();
        }

        /**
         * Getters and Setters
         */
        const std::shared_ptr<turbohiker::World>& getWorld() const { return world_; }

        void setWorld(std::shared_ptr<turbohiker::World> world) { this->world_ = std::move(world); }

        const std::shared_ptr<sf::RenderWindow>& getWindow() const { return window; }

        void setWindow(const std::shared_ptr<sf::RenderWindow>& window) { T_Game::window = window; }

        const std::shared_ptr<T_State>& getPreviousState() const;

        void setPreviousState(const std::shared_ptr<T_State>& previousState);

        const std::string& getPlayerName() const;

        void setPlayerName(const std::string& playerName);

        bool isRunning() const;

        void setRunning(bool running);
};

/** \class T_Game_Menu Game.h "src/Game.h"
 * \brief The game menu state.
 */
class T_Game_Menu : public T_State, public std::enable_shared_from_this<T_Game_Menu>
{
public:
        void init() override;

        void processEvents() override;
};

/** \class T_Game_Play Game.h "src/Game.h"
 * \brief The play state, this is the game itself.
 */
class T_Game_Play : public T_State, public std::enable_shared_from_this<T_Game_Play>
{
public:
        void init() override;

        void run() override;

        void processEvents() override;

        void update(double elapsedTime) override;

        void render() override;
};

/** \class T_Game_Play Game.h "src/Game.h"
 * \brief The aplay state, this is the game itself.
 */
class T_Game_Scoreboard : public T_State, public std::enable_shared_from_this<T_Game_Scoreboard>
{
public:
        void init() override;

        void processEvents() override;
};

#endif // GAME_GAME_H
