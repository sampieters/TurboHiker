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
#include <vector>

namespace turbohiker {
    class Score: public Observer {
    private:
        unsigned int finished;
        unsigned int score;
    public:
        Score();

        void OnNotify(Event event) override;

        unsigned int getScore() const;

        void setScore(unsigned int score);

        void addFinisher();

        unsigned int getFinished() const;

        void writeToFile(const std::string& player_name) const;

        static std::string ReadFile();
    };
}

#endif //TURBOHIKER_SCOREBOARD_H