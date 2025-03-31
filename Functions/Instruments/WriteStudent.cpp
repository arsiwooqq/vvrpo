#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Instruments.h"
#include "../../Education/Education.h"

void writeStudent(std::ofstream& file, Student& student) {
    file << student.groupNumber << std::endl << student.fullName << std::endl << student.educationForm << std::endl << student.isActive << std::endl;
    for (const auto& [subject, mark] : student.marks) {
        file << subject << " " << mark << " ";
    }
    file << std::endl;
    for (const auto& [subject, credited] : student.credits) {
        file << subject << " " << (credited ? 1 : 0) << " ";
    }
    file << std::endl;
}

void writeStudent(Student& student) {
    std::ofstream file(STUDENT_DATABASE, std::ios::app);
    writeStudent(file, student);
}

void writeStudents(std::vector <Student> students) {
    std::ofstream file(STUDENT_DATABASE);
    for (Student& student : students) {
        writeStudent(file, student);
    }
}