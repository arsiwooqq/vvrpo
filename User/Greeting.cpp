#include <iostream>
#include <fstream>
#include "User.h"

bool fileExists(std::string file) {
    std::ifstream File(file);
    return File.good();
}

void regFirstUser(std::string login, std::string password) {
    if (login.size() < 8) {
        throw std::string{"Login cannot be shorter than 8 characters!"};
    }
    if (password.size() < 8) {
        throw std::string{"Password cannot be shorter than 8 characters!"};
    }
    std::ofstream File(USER_DATABASE, std::ios::app);
    std::string salt = generateSalt(32);
    std::string hashedPassword = hashPassword(password, salt);

    File << login << " " << hashedPassword << " " << salt << " " << "admin" << " " << "active" << std::endl;
}