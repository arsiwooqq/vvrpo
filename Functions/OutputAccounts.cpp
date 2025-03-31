#include <iostream>
#include <vector>
#include <iomanip>
#include "Functions.h"
#include "../User/User.h"

void outputAccounts(Session& currentSession) {
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
}