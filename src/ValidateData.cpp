#include "../includes/ValidateData.h"

bool ValidateData::ValidatePassword(std::string password)
{
    const std::string special_symbol = "!@#$%^&*()-+";
    bool ContainsSpecSymb = false;
    bool ContainsLower = false;
    bool ContainsUpper = false;
    bool ContainsDigit = false;
    if (password.size() < 8)
    {
        return false;
    }
    for (size_t i = 0; i < password.size(); i++)
    {
        char symbol = password[i];
        if (symbol >= 'a' && symbol <= 'z')
        {
            ContainsLower = true;
        }
        else if (symbol >= 'A' && symbol <= 'Z')
        {
            ContainsUpper = true;
        }
        else if (symbol >= '0' && symbol <= '9')
        {
            ContainsDigit = true;
        }
        else
        {
            ContainsSpecSymb = true;
        }
    }
    return ContainsDigit && ContainsLower && ContainsSpecSymb && ContainsUpper;
}
bool ValidateData::ValidateLogin(std::string login)
{
    bool ContainsDigit = false;
    if (login.size() < 4)
    {
        return false;
    }

    for (size_t i = 0; i < login.size(); i++)
    {
        char symbol = login[i];
        if (symbol >= '0' and symbol <= '9')
        {
            return true;
        }
    }
    return false;
}
bool ValidateData::ValidateEmail(std::string email)
{
    bool ContainsDot = false;
    bool ContainsDog = false;
    if (email.size() < 4)
    {
        return false;
    }
    for (size_t i = 0; i < email.size(); i++)
    {
        char symbol = email[i];
        if (symbol == '@')
        {
            ContainsDog = true;
        }
        else if (symbol == '.')
        {
            ContainsDot = true;
        }
    }
    return ContainsDog && ContainsDot;
}
bool ValidateData::ValidateStockInput(std::string stock) {
    std::vector <std::string> data;
    std::string word;
    char symbol;
    for (size_t i = 0; i < stock.size(); i++)
    {
        symbol = stock[i];
        if (symbol != ' ')
        {
            word += symbol;
        }
        else if (word != "")
        {
            data.push_back(word);
            word.clear();
        }
    }
    data.push_back(word);
    if (data.size() != 2)
    {
        return false;
    }
    
    bool flag = true;
    for (size_t i = 0; i < data[1].size(); i++)
    {
        symbol = data[1][i];
        if (symbol >= '0' && symbol <= '9')
        {
            flag = true;
        }
        else {
            return false;
            break;
        }
    }
    return true;
}
