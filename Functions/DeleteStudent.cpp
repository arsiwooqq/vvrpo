#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Functions.h"
#include "../Education/Education.h"
#include "Instruments/Instruments.h"

void deleteStudent(Session&) {
    std::string name;
    std::cout << "Enter student name to delete: ";
    std::getline(std::cin, name);

    std::vector<Student> students = getStudents();
    std::ofstream file(STUDENT_DATABASE);

    bool deleted = false;
    for (Student& student : students) {
        if (toLowerCase(student.fullName) != toLowerCase(name)) {
            writeStudent(student);
        } else {
            deleted = true;
        }
    }

    std::cout << (deleted ? "Student deleted successfully!" : "Student not found!") << std::endl;
    pressAnyKeyToContinue();
}