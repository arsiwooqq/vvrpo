#include <iostream>
#include <vector>
#include <algorithm>
#include "Functions.h"
#include "../Education/Education.h"
#include "Instruments/Instruments.h"

void sortByMark(Session& currentSession) {
    std::vector<Student> students = getStudents();
    std::sort(students.begin(), students.end(), 
        [](const Student& a, const Student& b) {
            bool aExcellent, bExcellent;
            double aAvg = average(a.marks, aExcellent);
            double bAvg = average(b.marks, bExcellent);
            return aAvg > bAvg;
        });
    
    std::cout << "Sorted by average mark:" << std::endl;
    writeStudents(students);
    
    outputStudents(currentSession);
}