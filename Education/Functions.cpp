#include <iostream>
#include <vector>
#include <iomanip>
#include "../User/User.h"
#include "Education.h"

void outputStudents(Session& currentSession) {
    if (currentSession.role == "admin" || currentSession.role == "user") {
        std::vector <Student> students = getStudents();
        std::cout << std::left
        << std::setw(20) << "Full Name"
        << std::setw(8) << "Group"
        << std::setw(17) << "Education Form"
        << std::setw(10) << "Active"
        << std::setw(15) << "Average Mark"
        << std::setw(10) << "Excellent"
         << std::endl;
        std::cout << std::string(80, '-') << std::endl;
        
        for (const Student& student : students) {
            bool isExcellent = false;
            std::cout << std::left
                      << std::setw(20) << student.fullName
                      << std::setw(8) << student.groupNumber
                      << std::setw(17) << student.educationForm
                      << std::setw(10) << (student.isActive ? "Yes" : "No")
                      << std::setw(15) << std::setprecision(2) << average(student.marks, isExcellent)
                      << std::setw(10) << (isExcellent ? "Yes" : "No")
                      << std::endl;
        }

    } else {
        std::cout << "You don't have access to this function!" << std::endl;
    }
}

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