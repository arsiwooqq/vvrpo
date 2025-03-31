#include "Functions.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "../User/User.h"
#include "../Education/Education.h"

void outputScholarship(Session& currentSession, double baseScholarship) {
    if (currentSession.role == "admin" || currentSession.role == "user") {
        std::vector <Student> students = getStudents();
        std::cout << std::left
        << std::setw(40) << "Full Name"
        << std::setw(20) << "Group"
        << std::setw(20) << "Scholarship"
         << std::endl;
        std::cout << std::string(80, '-') << std::endl;

        for (const Student& student : students) {
            double scholarship = calculateScholarship(student, baseScholarship);
            std::cout << std::left
                      << std::setw(40) << student.fullName
                      << std::setw(20) << student.groupNumber
                      << std::setw(20) << (scholarship > 0 ? std::to_string(scholarship) : "No scholarship")
                      << std::endl;
        }
    } else {
        std::cout << "You don't have access to this function!" << std::endl;
    }
}