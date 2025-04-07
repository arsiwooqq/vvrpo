#include <vector>
#include <string>
#include "../../User/User.h"

bool checkDeletionPossibility(std::string login) {
    std::vector<User> users = getUsers();
    
    for (User& user : users) {
        if (login != user.login && user.role == "admin" && user.access == "active") {
            return true;
        }
    }
    return false;
}