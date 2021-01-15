//
// Created by Sam Pieters on 12/01/2021.
//

#include "MissingFile.h"

exceptions::MissingFile::MissingFile(const std::string& filename)
    : MyException("File " + filename + "is missing or wrong filename")
{
}