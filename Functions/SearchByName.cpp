#include <iostream>
#include <vector>
#include "Functions.h"
#include "../Education/Education.h"
#include "Instruments/Instruments.h"

void searchByName(Session& currentSession) {
    if (currentSession.role == "admin" || currentSession.role == "user") {
        std::string name;
        std::cout << "Enter name to search: ";
        std::getline(std::cin, name);
        
        std::vector<Student> students = getStudents();
        bool found = false;
        
        for (const auto& student : students) {
            if (toLowerCase(student.fullName).find(toLowerCase(name)) != std::string::npos) {
                std::cout << "Found: " << student.fullName 
                          << ", Group: " << student.groupNumber 
                          << ", Form: " << student.educationForm << std::endl;
                found = true;
            }
        }
        if (!found) {
            std::cout << "No students found with name: " << name << std::endl;
        }
    } else {
        std::cout << "You don't have access to this function!" << std::endl;
    }
    pressAnyKeyToContinue();
}