#include <iostream>
#include <string>
#include "../../Menu/Menu.h"
#include "Instruments.h"

std::string toLowerCase(std::string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] -= 'A' - 'a';
        }
    }
    return str;
}

void enterEducationForm(std::string &educationForm) {
    while (educationForm != "budget" && educationForm != "paid") {
        std::getline(std::cin, educationForm);
        educationForm = toLowerCase(educationForm);
        if (educationForm != "budget" && educationForm != "paid") {
            std::cout << "Wrong input! Form can be only Budget or Paid" << std::endl;
        }
    }
}