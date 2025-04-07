#include <iostream>
#include <map>
#include <string>
#include "../../Menu/Menu.h"
#include "Instruments.h"

std::map<std::string, bool> enterCredits() {
    std::map<std::string, bool> credits;

    std::cout << "Enter 4 credits:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::string subject;
        std::cout << "Subject " << i + 1 << ": ";
        std::getline(std::cin, subject);
        std::cout << "Is credited (yes/no):";
        credits[subject] = selectYesNo();
    }
    std::cout << "\nEntered credits:" << std::endl;
    for (const auto& credit : credits) {
        std::cout << "Subject: " << credit.first 
                  << ", Credited: " << (credit.second ? "Yes" : "No") 
                  << std::endl;
    }
    return credits;
}