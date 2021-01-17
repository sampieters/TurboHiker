/**
 * \brief Score class that keeps the score of the player (observable) en the amount of people finished.
 * \details This class is a derived class of the observer class. It is an observer of the player used to keep the score.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#ifndef TURBOHIKER_SCOREBOARD_H
#define TURBOHIKER_SCOREBOARD_H

#include "../../../Observer/Observable.h"
#include "../Entity.h"
#include <fstream>
#include <memory>
#include <vector>

namespace turbohiker {

/** \class Score Score.h "src/Logic/Entities/Static/Score.h"
 * \brief Class that is the score of a player on the camera from that world.
 * \details This class is a derived class from the observer class. Updates the score when the player interact in the world.
 */
class Score : public Observer
{
private:
        unsigned int finished;
        unsigned int score;

public:
        /**
         * Default constructor of the Score.
         */
        Score();

        /**
         * \brief Function that belongs to the obsever pattern. The score updates when notifief from the player.
         * \param event: An enumerable that indicates which event has happened in the world.
         */
        void OnNotify(Event event) override;

        /**
         * \brief Gets the score at a moment in time in the world.
         * \return unsigned int to the score. the score can thus be never under zero.
         */
        unsigned int getScore() const;

        /**
         * \brief Sets the score.
         * \param score: The updated score.
         */
        void setScore(unsigned int score);

        /**
         * \brief Function that adds to the counter of finishers when a dynamic entity goes over the finish line.
         */
        void addFinisher();

        /**
         * \brief Get the amount of finished dynamic entities there are in the world.
         * \return The amount of finished dynamic entities.
         */
        unsigned int getFinished() const;

        /**
         * \brief Function that writes the new score to a text file with the corresponding player. This function orders
         * the scores such that the highest score is on top of the file.
         * \param player_name: The user's name that is bound to the score.
         */
        void writeToFile(const std::string& player_name) const;

        /**
         * \brief Reads the score from the text file. Mostly used to display the score to the user.
         * \return a string that contains (the ordered) content of the scoreboard text file.
         */
        static std::string ReadFile();
};
} // namespace turbohiker

#endif // TURBOHIKER_SCOREBOARD_H