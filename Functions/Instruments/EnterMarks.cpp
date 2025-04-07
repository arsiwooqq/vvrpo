#include <iostream>
#include <map>
#include <string>
#include "../../Menu/Menu.h"
#include "Instruments.h"

std::map<std::string, int> enterMarks() {
    std::map<std::string, int> marks;

    std::cout << "Enter 4 marks (subject mark):" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::string subject;
        int mark;
        std::cout << "Subject " << i + 1 << ": ";
        std::getline(std::cin, subject);
        std::cout << "Mark: ";
        enterNumber(mark);
        marks[subject] = mark;
    }

    return marks;
}