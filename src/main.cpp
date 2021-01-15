#include "Game.h"
#include <memory>

int main() {
    T_Game game(std::make_shared<T_Game_Menu>());
    return 0;
}

//TODO:: 1) Comment Utils
//TODO:: 2) In transformation is still something hardcoded -> fix that
//TODO:: 3) Comment fuurther onthe representation entity

/** \mainpage Report The Flash TurboHiker
 *
 * \section Introduction
 *
 * This is the exam project of Sam Pieters. It is a Turbohiker based on the series The Flash. Every sound and picture used
 * in this project is originally from the The Flash series.
 *
 * \section Game
 * The Game consists of multiple states: the main page, the game loop and an scoreboard page. These states are implemented with
 * the state pattern design. This is an extra design i implemented based on the following source https://refactoring.guru/design-patterns/state/cpp/example.
 * The following subsections will describe the use and functionality of the states in more detail.
 *
 * \subsection Main
 * This is the first state that the game will be in when the game is started. It is a simple window with a background,
 * textbox and a button. When in this state, the music theme of The Flash will be played in the background.
 *
 * The player has to enter his name in the textbox. This can be done by first clicking on the textbox and then typing
 * his name/nickname. A cursor will indicate on what position the player is typing. Some complex letters like é, §, ...
 * can not be typed, this happens because the font used for the game doesn't support this glyph. When the play button is
 * pressed and nothing is typed, a text will pop up saying that there must be given a name. The game will not run until
 * at least on char is typed. The maximum amount of characters that can be typed is 20. This is set because the player
 * can't type out of the boundaries of the textbox.
 *
 * When something is typed in the textbox and the player presses the play button than the game state will change from
 * menu to play. When the screen is resized the button's click field will not be updated correctly in this version
 * because it wasn't as important as other functionalities. When the screen is initialised on other values than it will
 * work.
 *
 * The music that is played in the background is repeated so that when a player waits on the menu screen it will not get
 * boring.
 *
 * \subsection Loop
 * 1) start: <br>
 * When a player is out of the menu state (by clicking the play button in the menu state), the game will start running.
 * The game will start when the countdown reaches zero. This is done because the player can observe the environment
 * before he starts playing otherwise it will be a to quick start and let the player make mistakes.
 *
 * 2) player: <br>
 * The player is the only type of entity that can be controlled. A player can yell, change lanes, speed up and slow down.
 * The play can be moved or change speed with the z, q, s, d keys and will yell when pressed on the the space bar.
 *
 * When a player yells a amount of 50 points will be subtracted from the players score. If the enemy being yelled at should
 * die than there will be another 100 point subtracted from the score. If a player collides with an enemy, the score will
 * be deducted with 1 point. The player can earn point by moving a specified lenght in the world and by finishing. The
 * game keeps track of the competing enemies that crossed the finish. The amount of point given at the end for the player
 * will depend on which place the player ends.
 *
 * A player can't move to a lane on the same y-coördinates if there is an enemy in the way. The player can only yell
 * in front of him to an enemy. If there is no enemy in front of the player, the score of the player is still deducted
 * by a amount but there will be no enemy moved because there is no enemy.
 *
 * 3) enemies: <br>
 * The positions of the static and attacking will be random generated. The random generation will generate enemies and
 * checks if no two enemies are on the same position in the world or are a decided amount of y-coördinates away from
 * each other. This is done because if the player murders an enemy by yelling to much, there can't be a surprise enemy
 * be hidden under the one that recently died. The distance check is to make sure that there is at least a little space
 * between two enemies to play in and that the enemies will not be inside each other or be packed together. The
 * competing players are set by default. The amount of competing enemies and the lane they start on can be set to other
 * values as long as two competing hikers are not on the same start lane. When running the attacking players can hover
 * over the static enemies because otherwise they would be stuck and stack behind a static player.
 *
 * When yelled at an enemy the enemy has a chance to move and will lose health points. Based on what the enemy decides
 * (to move or not) the enemy will display a text balloon with the corresponding yell and there will be played a sound
 * that is directly from The Flash series. Each type of enemy responds differently (in text and sound) when yelled at
 * and the colour of the text balloon is also depending on the type of enemy. If the health of the enemy drops to zero
 * the enemy will die.
 *
 * 4) camera: <br>
 * The camera will keep track of the players position and updates it's own position. An extra functionality is that the
 * camera will stop when his front or end are going out of the bounds of the world this creates an effect when the player
 * goes over the finish because the camera stops. The camera holds a text value to display the score at any time when
 * running. The camera shows a part of the world so that the rest of the world is still mysterious and exciting.
 *
 * 5) lanes: <br>
 * The lanes are the x-coördinates where the dynamic entities (entities that can move) can be. The amount of lanes can
 * change when changed in the CONST header (Utils/CONST.h).
 *
 * 6) window: <br>
 * The window of the game can be resized and the game will still work correctly. The game can be closed at any time but
 * the score gathered when not finished will not be saved.
 *
 * \subsection Scoreboard
 * In the end the updated scoreboard (with the score the player just earned) will be displayed. The score that the player
 * earned will be loaded in the Scoreboard.txt file (src/Resources/Scoreboard.txt) if he/she has high enough points to be
 * in the top 10. If the player has earned a score that is high enough to be in the top 10 than his name and score will
 * be displayed. Every player can be multiple times on the scoreboard. For example is the first player has 2000 points
 * and the same player earns 1900 point than he will be in first and second place.
 *
 * If less than 10 people have played the game, the scoreboard will only display the amount of people who have played the
 * game. The window is resizable and can be closed in this state.
 *
 * \section Features
 *
 * \subsection game-patterns
 * This subsection will describe short what patterns are used in the game. Further explenation can be found in the class
 * of that design. Extra desing patterns are seen as extra features.
 *
 * 1) state pattern design: <br>
 * Design used to indicate the state of a game. That is, the menu, play or scoreboard state. Every state has a window,
 * different gui objects and has the functionality to go to another state.
 *
 * 2) Abstract factory: <br>
 * Design used to make every entity in the game. This pattern has 2 parts, an abstract factory and a concrete factory
 * the abstract factory is used in the logic of the game (srs/Logic/Factories) and the concrete factory is used in the
 * representation of the game (src/Representation/Factories).
 *
 * 3) Observer:
 * Design used to updte the score when the player has an interaction with the world. In the game the player is an observable
 * and the score is an observer.
 *
 *
 */