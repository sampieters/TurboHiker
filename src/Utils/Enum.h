/**
 * \brief All enumerators used in this project.
 * \author Sam Pieters
 * \date 24 December 2020
 */

#ifndef GAME_ENUM_H
#define GAME_ENUM_H

enum EntityType {Player, Static, Attacking, Competing, Lane, Camera, Finish};

/* Given to playerinput in world to distinguish sfml input from logic. */
enum InputCode {Z, Q, S, D, SPACE};

/* Parameter that is the move preference of the enemy when yelled at. */
enum MovePreference {Left, Right, None, Cannot};

/* Parameter that is the response of an enemy when yelled at. */
enum Response {Obey, Defy, Pain, Die};

/* State of the player. Default is NORMAL. */
enum State{POWERUP, NORMAL, COOLDOWN, YELL};

/* State of an enemy. */
enum Event{COLISSION, YELLED, MOVE, FINISHED, MURDERED};

#endif //GAME_ENUM_H

