#include <iostream>
#include "../../User/User.h"
#include "../../Menu/Menu.h"
#include "Instruments.h"

/**
 * Функция выбора роли при регистрации
 */
void selectRole(std::string& role) {
    do {
        int choice;
        std::cout << "Select role: " << std::endl;
        std::cout << "1. User" << std::endl;
        std::cout << "2. Admin" << std::endl;
        std::cout << "Enter your choice: ";
        enterNumber(choice);
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
    } while (role != "user" && role != "admin");
}