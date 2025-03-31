#include <iostream>
#include <map>
#include <string>
#include "../../Menu/Menu.h"
#include "Instruments.h"

std::map<std::string, bool> enterCredits() {
    std::map<std::string, bool> credits;

    std::cout << "Enter 4 credits (subject 1/0):" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::string subject;
        int credited;
        std::cout << "Subject " << i + 1 << ": ";
        std::cin.ignore();
        std::getline(std::cin, subject);
        std::cout << "Credited (1/0): ";
        std:: cin >> credited;
        credits[subject] = credited == 1;
    }

    return credits;
}