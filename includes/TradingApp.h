#ifndef TRADINGAPP_H
#define TRADINGAPP_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "Logging.h"

class TradingApp
{
public:
    void RunMenu();
    void getAccoutInfo();
    void depositMoney();
    void BuyStock();
    void sellStock();
    void checkTransactions();
    void addStocks();
};

#endif
