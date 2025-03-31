#include <iostream>
#include <vector>
#include <algorithm>
#include "Functions.h"
#include "../Education/Education.h"
#include "Instruments/Instruments.h"

void sortByName(Session& currentSession) {
    std::vector<Student> students = getStudents();
    std::sort(students.begin(), students.end(), 
        [](const Student& a, const Student& b) {
            return a.fullName < b.fullName;
        });
    
    std::cout << "Sorted by name:" << std::endl;
    writeStudents(students);
    
    outputStudents(currentSession);
}