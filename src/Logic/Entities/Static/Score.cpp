/**
 * \brief Score class that keeps the score of the player (observable) en the amount of people finished.
 * \details This class is a derived class of the observer class. It is an observer of the player used to keep the score.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#include "Score.h"

turbohiker::Score::Score() {
    score = 0;
}

void turbohiker::Score::OnNotify(Event event) {
    unsigned int to_remove = 0;
    switch (event) {
        case COLISSION:
            to_remove = 1;
            break;
        case YELLED:
            to_remove = 50;
            break;
        case MURDERED:
            to_remove = 100;
            break;
        case MOVE:
            score += 1;
            break;
        case FINISHED:
            score += (100/ (finished+1));
            break;
    }
    // This check is needed because score is unsigned integer and would be very large when going under 0.
    if(to_remove > score) {
        score = 0;
    } else {
        score -= to_remove;
    }
}

unsigned int turbohiker::Score::getScore() const {
    return score;
}

void turbohiker::Score::setScore(unsigned int score) {
    Score::score = score;
}

void turbohiker::Score::addFinisher() {
    finished += 1;
}

unsigned int turbohiker::Score::getFinished() const {
    return finished;
}

void turbohiker::Score::writeToFile(const std::string& player_name) const {
    std::ofstream outputFile("Resources/new_Scoreboard");
    std::ifstream inputFile("Resources/Scoreboard.txt");

    bool write = false;
    std::string line;
    // If file  empty
    if(inputFile.peek() == std::ifstream::traits_type::eof()) {
        outputFile << player_name << ": " << score << "\n";
    } else {
        while (getline(inputFile, line)) {
            std::string whut = line.substr(line.find(':') + 2);
            int number = std::stoi(whut);
            if (number < score && !write) {
                outputFile << player_name << ": " << score << "\n";
                write = true;
            }
            outputFile << line << "\n";
        }
        // If at the end of the file the new score is not written, write it.
        if(!write) {
            outputFile << player_name << ": " << score << "\n";
        }
    }

    inputFile.close();
    outputFile.close();

    std::remove("Resources/Scoreboard.txt");
    std::rename("Resources/new_Scoreboard","Resources/Scoreboard.txt");
}

std::string turbohiker::Score::ReadFile() {
    std::ifstream score_file("Resources/Scoreboard.txt");
    std::string line;
    std::string scoreboard;
    int i = 1;
    while (getline(score_file, line) && i < 11) {
        scoreboard += std::to_string(i) + ") " + line + "\n";
        i += 1;
    }
    return scoreboard;
}
