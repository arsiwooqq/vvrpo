#include <iostream>
#include <string>
#include <vector>
#include "Functions.h"
#include "../User/User.h"
#include "Instruments/Instruments.h"

void addAccount(Session& currentSession) {
    std::string login, password, role;
    std::cout << "Enter login: " << std::endl;
    std::cin >> login;  
    std::cout << "Enter password: " << std::endl;
    std::cin >> password;
    selectRole(role);

    try {
        regUser(login, password, role, true);
        std::cout << "Account created successfully!" << std::endl;
    } catch (const std::string& e) {
        std::cout << e << std::endl;
    }

    pressAnyKeyToContinue();
}