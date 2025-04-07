#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Functions.h"
#include "Instruments/Instruments.h"
#include "../User/User.h"
#include "../Menu/Menu.h"

void editAccountMenu(int& choice) {
    clearConsole();
    std::cout << "Edit account menu:" << std::endl;
    std::cout << "1. Edit password" << std::endl;
    std::cout << "2. Edit role" << std::endl;
    std::cout << "3. Activate account" << std::endl;
    std::cout << "4. Deactivate account" << std::endl;
    std::cout << "0. Back" << std::endl;
    enterNumber(choice);
}

void editAccountPassword(User &user) {
    std::string newPassword;
    std::cout << "Enter new password: ";
    std::cin >> newPassword;
    editPassword(user.login, newPassword);
}

void editAccountRole(std::vector<User> &users, User &user) {
    std::string newRole;
    selectRole(newRole);
    user.role = newRole;
    writeUsers(users);
}

void activateAccount(std::vector<User> &users, User &user) {
    user.access = "active";
    writeUsers(users);
}


void deactivateAccount(std::vector<User> &users, User &user) {
    user.access = "unactive";
    writeUsers(users);
}

void editAccount(Session& currentSession) {
    int choice;
    editAccountMenu(choice);
    if (choice == 0) {
        return;
    }
    std::string login;
    std::cout << "Enter login: ";
    std::cin >> login;
    
    std::vector<User> users = getUsers();
    bool found = false;
    for (User& user : users) {
        if (login == user.login) {
            found = true;
            switch(choice) {
                case 1:
                    editAccountPassword(user);
                    break;
                case 2:
                    editAccountRole(users, user);
                    break;
                case 3:
                    activateAccount(users, user);
                    break;
                case 4:
                    deactivateAccount(users, user);
                    break;
                case 0:
                    return;
                    break;
                default:
                    std::cout << "Enter correct number!" << std::endl;
                    break;
            }
            std::cout << "Account updated successfully!" << std::endl;
            break;
        }
    }
    
    if (!found) {
        std::cout << "Account not found!" << std::endl;
    }

    pressAnyKeyToContinue();
}