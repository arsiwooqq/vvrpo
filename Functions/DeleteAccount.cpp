#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Functions.h"
#include "../User/User.h"
#include "Instruments/Instruments.h"

void deleteAccount(Session& currentSession) {
    if (currentSession.role == "admin") {
        std::string login;
        std::cout << "Enter login of account to delete: ";
        std::getline(std::cin, login);

        if (!checkDeletionPossibility(login)) {
            std::cout << "You can not delete last admin!" << std::endl;
            pressAnyKeyToContinue();
            return;
        }

        if (login == currentSession.login) {
            currentSession = Session();
        }
        
        std::vector<User> users = getUsers();
        std::ofstream file(USER_DATABASE);
        
        bool deleted = false;
        for (User& user : users) {
            if (user.login != login) {
                writeUser(user);
            } else {
                deleted = true;
            }
        }

        std::cout << (deleted ? "Account deleted successfully!" : "Account not found!") << std::endl;
    } else {
        std::cout << "You don't have access to this function!" << std::endl;
    }
    pressAnyKeyToContinue();
}