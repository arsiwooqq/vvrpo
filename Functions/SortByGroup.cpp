#include <iostream>
#include <vector>
#include <algorithm>
#include "Functions.h"
#include "../Education/Education.h"
#include "Instruments/Instruments.h"

void sortByGroup(Session& currentSession) {
    std::vector<Student> students = getStudents();
    std::sort(students.begin(), students.end(), 
        [](const Student& a, const Student& b) {
            return a.groupNumber < b.groupNumber;
        });
    
    std::cout << "Sorted by group:" << std::endl;
    writeStudents(students);
    
    outputStudents(currentSession);
}