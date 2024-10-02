#ifndef VALIDATEDATA_H
#define VALIDATEDATA_H

#include <string>
#include <vector>
class ValidateData
{
public:
    bool ValidatePassword(std::string password);
    bool ValidateLogin(std::string login);
    bool ValidateEmail(std::string email);
    bool ValidateStockInput(std::string stock);
};

#endif
