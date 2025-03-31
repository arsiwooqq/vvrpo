#include <iostream>
#include <vector>
#include "Functions.h"
#include "../Education/Education.h"
#include "../Menu/Menu.h"

void searchByGroup(Session& currentSession) {
    int group;
    std::cout << "Enter group number to search: ";
    enterNumber(group);
    
    std::vector<Student> students = getStudents();
    bool found = false;
    
    for (const auto& student : students) {
        if (student.groupNumber == group) {
            std::cout << "Found: " << student.fullName 
                      << ", Group: " << student.groupNumber 
                      << ", Form: " << student.educationForm << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No students found in group: " << group << std::endl;
    }
}