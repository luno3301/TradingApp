#ifndef USERAUTH_H
#define USERAUTH_H

#include <iostream>
#include <fstream>
#include <string>
#include "Logging.h"
#include "TradingApp.h"
#include "ValidateData.h"

extern std::string input_login;

class UserAuth
{
public:
    int LogIn();
    int SignUp();
};

#endif
