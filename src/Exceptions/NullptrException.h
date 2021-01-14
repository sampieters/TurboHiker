//
// Created by Sam Pieters on 12/01/2021.
//

#ifndef TURBOHIKER_NULLPTREXCEPTION_H
#define TURBOHIKER_NULLPTREXCEPTION_H

#include "MyException.h"
#include <memory>

namespace exceptions {
    class NullptrException : public MyException {
    public:
        explicit NullptrException(const std::string &problem);
    };
}

#endif //TURBOHIKER_NULLPTREXCEPTION_H
