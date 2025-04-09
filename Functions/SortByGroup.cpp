#include <iostream>
#include <vector>
#include <algorithm>
#include "Functions.h"
#include "../Education/Education.h"
#include "Instruments/Instruments.h"

void sortByGroup(Session& currentSession) {
    if (currentSession.role == "admin" || currentSession.role == "user") {
        std::vector<Student> students = getStudents();
        std::sort(students.begin(), students.end(), 
            [](const Student& a, const Student& b) {
                return a.groupNumber < b.groupNumber;
            });
        
        std::cout << "Sorted by group:" << std::endl;
        writeStudents(students);
        
        outputStudents(currentSession);
    } else {
        std::cout << "You don't have access to this function!" << std::endl;
        pressAnyKeyToContinue();
    }
}