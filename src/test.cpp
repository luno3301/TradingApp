#include <iostream>
#include <string>
#include <fstream>
#include <vector>
std::string stocks_path = "../programfiles/stocksdata.txt";
bool ValidateStockInput(std::string stock) {
    std::vector <std::string> data;
    std::string word;
    char symbol;
    std::cout << stock << std::endl;
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
int main() {
    std::fstream file;
    std::string user_input;
    file.open(stocks_path, std::fstream::app);
    if (!file.is_open())
    {
        std::cout << "Fatal Error" << std::endl;
    }
    else {
        std::cout << "Enter your stock info {StockName StockPrice}" << std::endl;
        std::cout << "When you are done , enter 0" << std::endl;
        std::getline(std::cin, user_input); 
        while (user_input != "0")
        {
            if (ValidateStockInput(user_input) == false)
            {
                std::cout << "Enter corrent stock info" << std::endl;
                std::getline(std::cin, user_input); 
            }
            file << user_input << std::endl;
            std::getline(std::cin, user_input); 
        }
        file.close();
    }
    return 0;
}