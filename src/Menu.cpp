#include "../includes/Menu.h"

int Menu::RunStartMenu()
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
