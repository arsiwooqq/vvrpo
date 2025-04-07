#include <iostream>
#include "Instruments.h"

/**
 * Очистка консоли
 */
void clearConsole() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls"); 
    #else
        system("clear");
    #endif
}

void pressAnyKeyToContinue() {
    std::cout << "Press any key to continue...";
    std::cout.flush();

    #ifdef _WIN32
        system("pause >nul");
    #else
        system("read -n 1 -s");
    #endif

    std::cout << std::endl;
}