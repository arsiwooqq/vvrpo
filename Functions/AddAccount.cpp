#include <iostream>
#include <string>
#include <vector>
#include "Functions.h"
#include "../User/User.h"

void addAccount(Session& currentSession) {
    std::string login, password, role;
    std::cout << "Enter login: " << std::endl;
    std::cin >> login;  
    std::cout << "Enter password: " << std::endl;
    std::cin >> password;
    std::cout << "Enter role (user/admin): " << std::endl;
    std::cin >> role;

    try {
        regUser(login, password, role, true);
        std::cout << "Account created successfully!" << std::endl;
    } catch (const std::string& e) {
        std::cout << e << std::endl;
    }
}