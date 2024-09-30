#ifndef VALIDATEDATA_H
#define VALIDATEDATA_H

#include <string>

class ValidateData
{
public:
    bool ValidatePassword(std::string password);
    bool ValidateLogin(std::string login);
    bool ValidateEmail(std::string email);
};

#endif
