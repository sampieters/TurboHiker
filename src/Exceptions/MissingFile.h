//
// Created by Sam Pieters on 12/01/2021.
//

#ifndef TURBOHIKER_MISSINGFILE_H
#define TURBOHIKER_MISSINGFILE_H

#include "MyException.h"
#include <memory>

namespace exceptions {
    class MissingFile : public MyException {
    public:
        /**
         * Constructor
         * @param filename The name of the missing file
         */
        explicit MissingFile(const std::string &filename);
    };
}

#endif //TURBOHIKER_MISSINGFILE_H
