#ifndef LOGGING_H
#define LOGGING_H

#include <string>
#include <fstream>
#include <ctime>
#include <regex>

class Logging
{
public:
    void LogData(std::string str);
    bool containsWord(const std::string& text, const std::string& word);
};

#endif
