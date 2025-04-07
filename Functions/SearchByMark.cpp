#include <iostream>
#include <vector>
#include "Functions.h"
#include "../Education/Education.h"
#include "../Menu/Menu.h"
#include "Instruments/Instruments.h"

void searchByMark(Session& currentSession) {
    double mark;
    bool isExcellent;
    std::cout << "Enter minimum mark to search: ";
    enterNumber(mark);
    
    std::vector<Student> students = getStudents();
    bool found = false;
    
    for (Student& student : students) {
        double avg = average(student.marks, isExcellent);
        if (avg >= mark) {
            found = true;
            std::cout << "Found: " << student.fullName 
                      << ", Group: " << student.groupNumber 
                      << ", Form: " << student.educationForm
                      << ", Avg mark: " << avg << std::endl;
        }
    }
    if (!found) {
        std::cout << "No students found with mark >= " << mark << std::endl;
    }

    pressAnyKeyToContinue();
}