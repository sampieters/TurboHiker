//
// Created by Sam Pieters on 12/01/2021.
//

#include "NullptrException.h"

exceptions::NullptrException::NullptrException(const std::string& problem) : MyException(problem) {}