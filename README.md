# Luno Trading App

The **Luno Trading App** is a console-based C++ application that allows users to manage their stock portfolio. Users can register, log in, view account information, deposit funds, buy and sell stocks, and view transaction history. This project demonstrates basic file handling, input validation, and the usage of STL containers such as vectors, maps, and strings.

```
Trading App
├── bin/
│ └── tradingapp.exe
├── includes/
│   ├── Logging.h
|   |   ├── LogData()
│   |   └── containsWord()
│   |
│   ├── Menu.h
|   |   └── RunStartMenu()
│   |
│   ├── TradingApp.h
|   |   ├── RunMainMenu()
|   |   ├── getAccoutInfo()
|   |   ├── depositMoney()
|   |   ├── BuyStock()
|   |   ├── sellStock()
|   |   ├── addStocks()
│   |   └── checkTransactions()
│   |
│   ├── ValidateData.h
|   |   ├── ValidatePassword()
|   |   ├── ValidateLogin()
|   |   ├── ValidateEmail()
|   |   └── ValidateStockInput()
│   └── UserAuth.h
|       ├── LogIn()
|       └── SignUp()
│   
├── programfiles/
│   └── stocksdata.txt
│   
├── src/
│   ├── Logging.cpp
│   ├── Menu.cpp
│   ├── TradingApp.cpp
│   ├── ValidateData.cpp
│   └── UserAuth.cpp
│   
└── userdata/
    ├── uesrname.log
    └── username.txt
```
