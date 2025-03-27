#include <iostream>
#include <string>
#include <vector>
#include "User/User.h"
#include "Menu/Menu.h"

Session currentSession;

int main() {
    std::vector<User> users;
    do {
        mainMenu(currentSession);
    } while (true);
    return 0;
}
