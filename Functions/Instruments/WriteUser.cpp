#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../../User/User.h"
#include "Instruments.h"

void writeUser(std::ofstream& file, User& user) {
    file << user.login << " " << user.password << " " << user.salt << " "
         << user.role << " " << user.access << std::endl;
}

void writeUser(User& user) {
    std::ofstream file(USER_DATABASE, std::ios::app);
    writeUser(file, user);
}

void writeUsers(std::vector <User> users) {
    std::ofstream file(USER_DATABASE);
    for (User& user : users) {
        writeUser(file, user);
    }
}