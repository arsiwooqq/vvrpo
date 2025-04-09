#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Functions.h"
#include "../Education/Education.h"
#include "../Menu/Menu.h"
#include "Instruments/Instruments.h"

void addStudent(Session& currentSession) {
    if (currentSession.role == "admin") {
        std::string fullName, educationForm;
        int groupNumber;
        bool isActive;
        
        std::cout << "Enter full name: ";
        std::getline(std::cin, fullName);
        std::cout << "Enter group number: ";
        enterNumber(groupNumber);
        std::cout << "Enter education form (Budget/Paid): ";
        enterEducationForm(educationForm);
        std::cout << "Is active? (yes/no): ";
        isActive = selectYesNo();
        
        std::map<std::string, int> marks = enterMarks();
        std::map<std::string, bool> credits = enterCredits();
        
        Student student = Student(fullName, groupNumber, educationForm, isActive, marks, credits);

        writeStudent(student);

        std::cout << "Student added successfully!" << std::endl;
    } else {
        std::cout << "You don't have access to this function!" << std::endl;
    }
    pressAnyKeyToContinue();
}