//
// Created by Sam Pieters on 12/01/2021.
//

#ifndef TURBOHIKER_MYEXCEPTION_H
#define TURBOHIKER_MYEXCEPTION_H

#include <exception>
#include <memory>
#include <string>

namespace exceptions {
    class MyException : public std::exception {
    private:
        std::string problem;

    public:
        /**
         * Make a new exception
         * \param problem: The problem why the exception is thrown
         */
        explicit MyException(std::string problem);

        /**
         * Get the reason that caused the exception
         * \return a string describing the cause of the exception
         */
        [[nodiscard]] const char *what() const noexcept override;
    };
}

#endif //TURBOHIKER_MYEXCEPTION_H
