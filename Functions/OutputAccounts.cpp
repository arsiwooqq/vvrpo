#include <iostream>
#include <vector>
#include <iomanip>
#include "Functions.h"
#include "../User/User.h"
#include "Instruments/Instruments.h"

void outputAccounts(Session& currentSession) {
    if (currentSession.role == "admin") {
        std::vector<User> users = getUsers();
        std::cout << std::left
            << std::setw(20) << "Login"
            << std::setw(20) << "Role"
            << std::setw(20) << "Access"
            << std::endl;
        std::cout << std::string(60, '-') << std::endl;

        for (const auto& user : users) {
            std::cout << std::left
                      << std::setw(20) << user.login
                      << std::setw(20) << user.role
                      << std::setw(20) << user.access
                      << std::endl;
        }
    } else {
        std::cout << "You don't have access to this function!" << std::endl;
    }
    pressAnyKeyToContinue();
}