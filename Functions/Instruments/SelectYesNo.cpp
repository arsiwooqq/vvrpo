#include <iostream>
#include "Instruments.h"

bool selectYesNo() {
    std::string inputStr;
    while (true) {
        std::getline(std::cin, inputStr);
        inputStr = toLowerCase(inputStr);
        if (inputStr == "y" || inputStr == "yes") {
            return true;
        } else if (inputStr == "n" || inputStr == "no") {
            return false;
        } else {
            std::cout << "Wrong input! Enter YES or NO" << std::endl;
        }
    }
}