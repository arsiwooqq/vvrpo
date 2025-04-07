#include <iostream>
#include "Instruments.h"

/**
 * Функция для ввода числа пользователем
 * Защищена от некорректного ввода
 */
void enterNumber(int& number) {
    do {
        std::cin >> number;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input!" << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    } while (true);
}

void enterNumber(double& number) {
    do {
        std::cin >> number;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input!" << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    } while (true);
}