#include <iostream>
#include "Instruments.h"

bool selectYesNo() {
    std::string inputStr;
    bool answer = false;

    while (inputStr != "y" && inputStr != "n" && inputStr != "yes" && inputStr != "no") {
        std::getline(std::cin, inputStr);
        inputStr = toLowerCase(inputStr);
        if (inputStr == "y" || inputStr == "yes") {
            answer = true;
        } else if (inputStr == "n" || inputStr == "no") {
            answer = false;
        } else {
            std::cout << "Wrong input! Enter YES or NO" << std::endl;
        }
    }

    return answer;
}