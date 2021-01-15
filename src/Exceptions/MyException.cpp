//
// Created by Sam Pieters on 12/01/2021.
//

#include "MyException.h"

const char* exceptions::MyException::what() const noexcept { return problem.c_str(); }

exceptions::MyException::MyException(std::string problem) : problem(std::move(problem)) {}