#include "../includes/UserAuth.h"
std::string input_login;
int UserAuth::LogIn()
{

    std::string input_password, user_password, user_email;
    std::cout << "Enter your login" << std::endl;
    std::cin >> input_login;
    std::cout << "Enter your password" << std::endl;
    std::cin >> input_password;
    std::fstream file_output;
    std::string user_path = "../userdata/" + input_login + ".txt";
    std::string log_path = "../userdata/" + input_login + ".log";
    file_output.open(user_path);

    if (!file_output.is_open())
    {
        std::cout << "Wrong Login" << std::endl;
        return 0;
    }
    else
    {
        file_output >> user_email;
        file_output >> user_password;
        file_output.close();
        if (user_password != input_password)
        {
            std::cout << "Wrong Password" << std::endl;
            Logging log;
            log.LogData("WrongPass " + input_login);
            TradingApp app;
            return 0;
        }
        else
        {
            std::cout << "Welcome, " + user_email << std::endl;
            Logging log;
            log.LogData("LogIn " + input_login);
            TradingApp app;
            app.RunMenu();
            return 0;
        }
    }
}
int UserAuth::SignUp()
{
    std::cout << "Welcome!";
    std::string input_password, input_email;
    ValidateData validate;
    while (!validate.ValidateLogin(input_login))
    {
        std::cout << "Enter your login (Must contain at least one digit and have lenght > 4)" << std::endl;
        std::cin >> input_login;
    }
    while (!validate.ValidatePassword(input_password))
    {
        std::cout << "Enter your password (Must contain at least one digit lowercase and uppercase symbol, symbol from {!@#$%^&*()-+} and have lenght > 8 )" << std::endl;
        std::cin >> input_password;
    }
    while (!validate.ValidateEmail(input_email))
    {
        std::cout << "Enter email" << std::endl;
        std::cin >> input_email;
    }
    std::string path = "../userdata/" + input_login + ".txt";
    std::fstream file_input;
    file_input.open(path, std::fstream::app);
    if (!file_input.is_open())
    {
        std::cout << "File opening Error" << std::endl;
    }
    else
    {
        std::cout << "Registration Successful" << std::endl;
        file_input << input_email << std::endl;
        file_input << input_password << std::endl;
        file_input << "0" << std::endl;
        file_input << " " << std::endl;
    }
    file_input.close();
     int a = 1;
        std::cout <<  "Input 0 to close window";
        while (a != 0)
        {
            std::cin >> a;
        }
        return 0;
    return 0;
}