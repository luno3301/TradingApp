#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <ctime>
#include <regex>

/* Global Variables */
std::string input_login;
std::string stocks_path = "programfiles/stocksdata.txt";

class Logging
{
    public:
        void LogData(std::string str) {
        std::fstream log;
        int pos;

        std::string output;
        std::string user_path = "userdata/" + input_login + ".txt";
        std::string log_path = "userdata/" + input_login + ".log";

        log.open(log_path, std::fstream::app);
        std::time_t result = std::time(nullptr);
        output = std::ctime(&result) + str;
        if((pos = output.find('\n')) != std::string::npos)
            output.erase(pos);
        log << str + "\t" + output << std::endl;
        log.close();
        }
        bool containsWord(const std::string& text, const std::string& word) {
            std::regex pattern("\\b" + word + "\\b"); 
            return std::regex_search(text, pattern);
        }
};

class TradingApp
{
public:
    void RunMenu()
    {
        std::cout << "_________________________\n";
        std::cout << "|                       |\n";
        std::cout << "|                       |\n";
        std::cout << "|   Luno Trade App      |\n";
        std::cout << "|                       |\n";
        std::cout << "|_______________________|\n";
        std::cout << "|  1. Account Info      |\n";
        std::cout << "|  2. Top Up Banalce    |\n";
        std::cout << "|  3. Buy Stocks        |\n";
        std::cout << "|  4. Sell Stocks       |\n";
        std::cout << "|  5. Transitions List  |\n";
        std::cout << "|_______________________|\n";
        std::cout << "Select a menu item(1-5): ";
        std::cout << std::endl;
        int choise;
    caseWrongKey:
        std::cin >> choise;
        switch (choise)
        {
        case 1:
            getAccoutInfo();
            break;
        case 2:
            depositMoney();
            break;
        case 3:
            BuyStock();
            break;
        case 4:
            sellStock();
            break;
        case 5:
            checkTransactions();
            break;
        default:
            std::cout << "Wrong Button! Try again" << std::endl;
            goto caseWrongKey;
            break;
        }
    }
    void getAccoutInfo()
    {
        std::string user_path = "userdata/" + input_login + ".txt";
        std::string log_path = "userdata/" + input_login + ".log";
        std::fstream get_file;
        std::string user_email, user_balance, user_stocks, user_password;
        std::string str;
        std::vector <std::string> data;
        get_file.open(user_path);
        if (!get_file.is_open())
        {
            std::cout << "Unexpected Error!" << std::endl;
        }
        else
        {
            while (!get_file.eof())
            {
                str = "";
                std::getline(get_file, str);
                if (str != "")
                {
                    data.push_back(str);
                }
            }
            user_email = data[0];
            user_balance = data[2];
            user_stocks = data[3];
            std::cout << "Your Balance: " << user_balance << std::endl;
            std::cout << "Your Stocks: " << user_stocks << std::endl;
            get_file.close();
        }
    }
    void depositMoney()
    {
        std::string user_path = "userdata/" + input_login + ".txt";
        std::string log_path = "userdata/" + input_login + ".log";

        int deposit_metod;
        std::string card_number, phone_number, deposit_amount;
        std::string data;
        std::cout << "Enter the deposit amount " << std::endl;
        std::cin >> deposit_amount;
        std::cout << "Select a deposit method " << std::endl;
        std::cout << "1. Credit Card" << std::endl << "2. Phone Number" << std::endl;
        std::cin >> deposit_metod;

        std::fstream file_input;

        file_input.open(user_path, std::fstream::app);
        if (!file_input.is_open())
        {
            std::cout << "File opening Error" << std::endl;
        }
        else
        {
            // variables for swich
            std::fstream file_input;
            std::fstream file;
            file_input.open(user_path);
            std::string str;
            std::vector<std::string> data;
            bool flag = true;
            switch (deposit_metod)
            {
            case 1:
                    std::cout << "Enter card number" << std::endl;
                    while (card_number.size() != 16)
                    {
                        std::cin >> card_number;
                        if (card_number.size() != 16)
                        {
                            std::cout << "Enter Valid Card Number!" << std::endl;
                        }
                    }
                    // file_input << card_number << std::endl;
                    while (!file_input.eof())
                    {
                        str = "";
                        std::getline(file_input, str);
                        if (str != "")
                        {
                            data.push_back(str);
                        }
                    }
                    file_input.close();
                    for (size_t i = 0; i < data.size(); i++) 
                    {
                        if (data[i] == card_number)
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        data.push_back(card_number);
                    }
                    data[2] = std::to_string(std::stoi(data[2]) + std::stoi(deposit_amount));
                    file.open(user_path);
                    for (size_t i = 0; i < data.size(); i++)
                    {
                        file << data[i] << std::endl;
                    }
                    
                    file.close();
                    std::cout << "Payment successful!" << std::endl;
                    Logging log;
                    log.LogData("DepositMoney " + deposit_amount);
                    RunMenu();
                break;
            case 2:
                std::cout << "Enter phone number" << std::endl;
                while (phone_number.size() != 12 && phone_number[0] != '+')
                {
                    std::cin >> phone_number;
                    if (phone_number.size() != 12 && phone_number[0] != '+')
                    {
                        std::cout << "Enter Valid Phone Number!" << std::endl;
                    }
                }
                while (!file_input.eof())
                    {
                        str = "";
                        std::getline(file_input, str);
                        if (str != "")
                        {
                            data.push_back(str);
                        }
                    }
                    file_input.close();
                    for (size_t i = 0; i < data.size(); i++) 
                    {
                        if (data[i] == phone_number)
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        data.push_back(phone_number);
                    }
                    data[2] = std::to_string(std::stoi(data[2]) + std::stoi(deposit_amount));
                    file.open(user_path);
                    for (size_t i = 0; i < data.size(); i++)
                    {
                        file << data[i] << std::endl;
                    }
                    
                    file.close();
                    std::cout << "Payment successful!" << std::endl;
                    log.LogData("DepositMoney " + deposit_amount);
                    RunMenu();  
                    break;
            default:
                break;
            }
        }
    }
    void BuyStock()
    {
        std::fstream stockdata;
        std::fstream userdata;
        std::fstream file;
        std::string user_path = "userdata/" + input_login + ".txt";
        std::string log_path = "userdata/" + input_login + ".log";

        userdata.open(user_path);
        stockdata.open(stocks_path);
        std::vector <std::string> user_data;
        std::map <int, std::string> stock_data;
        std::string str;
        std::string user_stock_choice;
        std::string curr_stock_price;
        std::string curr_stock_name;
        std::string stock_value;
        int stock_count;
        int stock_choice;
        int curr_balance;
        int count = 1;

        if (!stockdata.is_open())
        {
            std::cout << "Unexpected Error!" << std::endl;
        }
        else {
            while (!stockdata.eof())
            {
                str = "";
                std::getline(stockdata, str);
                stock_data[count] = str;
                if (str != "")
                {
                    std::cout << count << ' ' << str << std::endl;
                }
                count++;
            }
            stockdata.close();

            std::cout << std::endl << "Pick Stock From List" << std::endl;
            std::cin >> stock_choice;
            user_stock_choice = stock_data[stock_choice];
            std::cout << stock_data[stock_choice] << std::endl;
            std::cout << "Enter count of stocks" << std::endl;
            std::cin >> stock_count;
            if (!userdata.is_open())
            {
                std::cout << "Unexpected Error!" << std::endl;
            }
            else {
                while (!userdata.eof())
                        {
                            str = "";
                            std::getline(userdata, str);
                            if (str != "")
                            {
                                user_data.push_back(str);
                            }
                        }
            }
            userdata.close();
            curr_balance = std::stoi(user_data[2]);
            for (size_t i = 0; i < user_stock_choice.size(); i++)
            {
                char symbol = user_stock_choice[i];
                if (symbol >= '0' && symbol <= '9')
                {
                    curr_stock_price += symbol;
                }
                else if (symbol >= 'A' && symbol <= 'Z' && symbol != ' ')
                {
                    curr_stock_name += symbol;
                }
            }
            if(std::stoi(curr_stock_price)*stock_count > curr_balance)
            {
                while (std::stoi(curr_stock_price)*stock_count > curr_balance)
                {
                    std::cout << "Insufficient balance to complete the transaction" << std::endl;
                    std::cin >> stock_count;
                }
            }
            else {
                curr_balance -= stock_count * std::stoi(curr_stock_price);
                stock_value = curr_stock_name + ' '+ std::to_string(stock_count);
            }   
            user_data[2] = std::to_string(curr_balance);
            if (user_data[3] == "" ) {
                user_data[3] += stock_value;
            }
            else {
                user_data[3] +=  " " + stock_value;
            }
            file.open("userdata/" + input_login + ".txt");
            for (size_t i = 0; i < user_data.size(); i++)
            {
                file << user_data[i] << std::endl;
            }
            std::cout << "Stocks purchased successfully" << std::endl;
            file.close();
            Logging log;
            log.LogData("BuyStocks " + user_stock_choice);
            RunMenu();
        }
        
    }
    void sellStock()
    {
        std::fstream userdata_read;
        std::fstream stocksdata;
        std::fstream userdata_write;
        std::string str, temp;
        std::string user_stocks_data;
        std::string data_string;

        std::string stock_choice;
        std::string stock_choice_amount;
        std::string stock_choice_price;

        std::map <std::string, std::string> stocks_info;
        std::vector <std::string> data;
        std::vector <std::string> temp_data;

        std::string user_path = "userdata/" + input_login + ".txt";
        std::string log_path = "userdata/" + input_login + ".log";
        userdata_read.open(user_path);
        stocksdata.open(stocks_path);

        if (!userdata_read.is_open())
        {
            std::cout << "Unexpected Error";
        }
        else {
            while (!userdata_read.eof())
            {
                str = "";
                std::getline(userdata_read, str);      
                data.push_back(str);
            }
        }
        userdata_read.close();
        
        user_stocks_data = data[3];
        char symbol;
        std::string word;
        for (size_t i = 0; i < user_stocks_data.size(); i++)
        {
            symbol = user_stocks_data[i];
            if (symbol != ' ')
            {
                word += symbol;
            }
            else if (word != "")
            {
                temp_data.push_back(word);
                word.clear();
            }
        }
        temp_data.push_back(word);

        for (size_t i = 0; i < temp_data.size(); i++)
        {
            if (temp_data[i][0] >= '0' && temp_data[i][0] <= '9')
            {
                stocks_info[temp_data[i - 1]] = temp_data[i];
            }
        }
        temp_data.clear();
        std::cout << "Your Stocks List : " + user_stocks_data << std::endl;
        user_stocks_data.clear();
        std::cout << "What stock you whant to sell?" << std::endl;
        std::cin >> stock_choice;
        

        for (const auto& [key, value] : stocks_info)
            if (key != stock_choice) {
                user_stocks_data += key + " " + value + " ";
            }
            else {
                stock_choice_amount = value;
            }
        data[3] = user_stocks_data;

        if (!stocksdata.is_open())
        {
            std::cout << "Unexpected Error" << std::endl;
        }
        else {
            while (!stocksdata.eof())
            {
                str = "";
                std::getline(stocksdata, str);
                for (size_t i = 0; i < str.size(); i++)
                {
                    if (str[i] != ' ')
                    {
                        temp += str[i];
                    }
                    else {
                        temp_data.push_back(temp);
                        temp = "";
                    }
                }
                temp_data.push_back(temp);
                temp = "";
            }
        }
        for (size_t i = 0; i < temp_data.size(); i++)
        {
            if (temp_data[i] == stock_choice)
            {
                stock_choice_price = temp_data[i + 1];
                break;
            }
        }        
        data[2] = std::to_string(std::stoi(data[2]) + std::stoi(stock_choice_price) * std::stoi(stock_choice_amount));

        userdata_write.open(user_path, std::ios::out); 


        for (size_t i = 0; i < data.size(); i++){
                userdata_write << data[i] << std::endl;
        } 
        userdata_write.close(); 
        Logging log;
        log.LogData("SellStock " + stock_choice);
        RunMenu();
    }
    void checkTransactions()
    {
        std::string str;
        std::string user_path = "userdata/" + input_login + ".log";
        std::fstream data;
        Logging check;
        data.open(user_path);
        if (!data.is_open())
        {
            std::cout << "Unexpected Error!" << std::endl;
        }
        else{
            while (!data.eof())
            {
                str = "";
                std::getline(data, str);
                if (check.containsWord(str, "DepositMoney") || check.containsWord(str, "SellStock") || check.containsWord(str, "BuyStocks"))
                {
                    std::cout << str << std::endl;
                }
            }
        }
        RunMenu();
    }
};

class ValidateData
{
public:
    bool ValidatePassword(std::string password)
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
    bool ValidateLogin(std::string login)
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
    bool ValidateEmail(std::string email)
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
};

class UserAuth
{
public:
    int LogIn()
    {
        std::string input_password, user_password, user_email;
        std::cout << "Enter your login" << std::endl;
        std::cin >> input_login;
        std::cout << "Enter your password" << std::endl;
        std::cin >> input_password;
        std::fstream file_output;
        std::string user_path = "userdata/" + input_login + ".txt";
        std::string log_path = "userdata/" + input_login + ".log";
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
    int SignUp()
    {
        std::cout << "Welcome!";
        std::string input_login, input_password, input_email;
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
        std::string path = "userdata/" + input_login + ".txt";
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
        return 0;
    }
};
class Menu
{
public:
    int RunMenu()
    {
        std::cout << "__________________" << std::endl;
        std::cout << "| Luno Trade App!|" << std::endl;
        std::cout << "|    1.Log in    |" << std::endl;
        std::cout << "|    2.Sign up   |" << std::endl;
        std::cout << "|----------------|" << std::endl;

        char choice;
        std::cin >> choice;
        if (choice == '1')
        {
            UserAuth Auth;
            Auth.LogIn();
        }
        else if (choice == '2')
        {
            UserAuth Register;
            Register.SignUp();
        }

        return 0;
    }
};

int main()
{
    Menu run;
    run.RunMenu();
    return 0;
}