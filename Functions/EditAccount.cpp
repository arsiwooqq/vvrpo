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
    std::getline(std::cin, newPassword);
    editPassword(user.login, newPassword);

    std::cout << "Password edited successfully!" << std::endl;
    pressAnyKeyToContinue();
}

void editAccountRole(std::vector<User> &users, User &user) {
    if (!checkDeletionPossibility(user.login)) {
        std::cout << "You can not change role of the last admin!" << std::endl;
        pressAnyKeyToContinue();
        return;
    }
    std::string newRole;
    selectRole(newRole);
    user.role = newRole;
    writeUsers(users);

    std::cout << "Role edited successfully!" << std::endl;
    pressAnyKeyToContinue();
}

void activateAccount(std::vector<User> &users, User &user) {
    user.access = "active";
    writeUsers(users);

    std::cout << "Account activated successfully!" << std::endl;
    pressAnyKeyToContinue();
}


void deactivateAccount(std::vector<User> &users, User &user) {
    if (!checkDeletionPossibility(user.login)) {
        std::cout << "You can not change status of the last admin!" << std::endl;
        pressAnyKeyToContinue();
        return;
    }
    user.access = "unactive";
    writeUsers(users);

    std::cout << "Account deactivated successfully!" << std::endl;
    pressAnyKeyToContinue();
}

void editAccount(Session& currentSession) {
    if (currentSession.role == "admin") {
        int choice;
        std::string login;
        std::cout << "Enter login: ";
        std::getline(std::cin, login);
        
        std::vector<User> users = getUsers();
        bool found = false;
        for (User& user : users) {
            if (login == user.login) {
                found = true;
                do {
                    editAccountMenu(choice);
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
                            pressAnyKeyToContinue();
                            break;
                    }
                } while (choice != 0);
                break;
            }
        }
        
        if (!found) {
            std::cout << "Account not found!" << std::endl;
            pressAnyKeyToContinue();

        }
    } else {
        std::cout << "You don't have access to this function!" << std::endl;
        pressAnyKeyToContinue();
    }
}