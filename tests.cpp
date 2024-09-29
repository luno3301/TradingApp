#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string input_login = "luno3301";

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
  

int main() {
    getAccoutInfo();
    return 0;
}