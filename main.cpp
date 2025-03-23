#include <iostream>
#include <string>
#include <vector>
#include "User.h"

int main() {
    std::vector<User> users;
    Session user;
    int choice;
    
    do {
        std::string login, password, role;
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Login" << std::endl;
        std::cout << "2. Register" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter username: " ;
                std::cin >> login;
                std::cout << std::endl;
                std::cout << "Enter password: ";
                std::cin >> password;
                std::cout << std::endl;

                try {
                    user = authUser(login, password);
                } catch (std::string e) {
                    std::cout << e;
                }
                break;
            case 2:
                std::cout << "Select role: " << std::endl;
                std::cout << "1. User" << std::endl;
                std::cout << "2. Admin" << std::endl;
                std::cout << "Enter your choice: ";
                std::cin >> choice;
                switch (choice) {
                    case 1: 
                        role = "user";
                        break;
                    case 2:
                        role = "admin";
                        break;
                    default:
                        std::cout << "Enter correct role!" << std::endl;
                }

                std::cout << "Enter username: ";
                std::cin >> login;
                std::cout << std::endl;
                std::cout << "Enter password: ";
                std::cin >> password;
                std::cout << std::endl;

                try {
                    regUser(login, password, role);
                } catch (std::string e) {
                    std::cout << e << std::endl;
                }
                break;
        }
    } while (choice != 3);
    return 0;
}
