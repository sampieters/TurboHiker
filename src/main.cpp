#include "Game.h"
#include <memory>

/*! \mainpage Report The Flash TurboHiker
 *
 * \section Introduction
 *
 * This is the exam project of Sam Pieters. It is a Turbohiker based on the series The Flash. Every sound and picture used
 * in this project is originally from the The Flash series.
 *
 * \section The Game:
 * The Game consists of multiple states: the main page, the game loop and an end page. These states are implemented with
 * the state pattern design. This is an extra design i implemented based on the following source https://refactoring.guru/design-patterns/state/cpp/example.
 * The following subsections will describe the use and functionality of the states in more detail.
 *
 * \section Main_Page:
 * This is the first state that the game will be in when the game is started.
 *
 * \section Game_Loop:
 * \section End_Page:
 *
 *
 */


int main() {
    T_Game game(std::make_shared<T_Game_Menu>());
    return 0;
}

//TODO:: 1) Comment Utils
//TODO:: 2) In transformation is still something hardcoded -> fix that
//TODO:: 3) Comment fuurther onthe representation entity
