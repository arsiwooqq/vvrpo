#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Functions.h"
#include "../Education/Education.h"
#include "Instruments/Instruments.h"
#include "../Menu/Menu.h"

void editStudentMenu(int& choice) {
    std::cout << "Edit student menu:" << std::endl;
    std::cout << "1. Edit full name" << std::endl;
    std::cout << "2. Edit group number" << std::endl;
    std::cout << "3. Edit education form" << std::endl;
    std::cout << "4. Edit student's activeness" << std::endl;
    std::cout << "5. Edit student's marks" << std::endl;
    std::cout << "6. Edit student's credits" << std::endl;
    std::cout << "0. Back" << std::endl;
    enterNumber(choice);
}

void editStudentFullName() {

}

void editStudentGroupNumber() {

}

void editStudentEducationForm() {

}

void editStudentActiveness() {

}

void editStudentMarks() {

}

void editStudentCredits() {
    
}

void editStudent(Session& currentSession) {
    int choice;
    editStudentMenu(choice);
    std::string name;
    std::cout << "Enter name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    
    std::vector<Student> students = getStudents();
    bool found = false;

    for (Student& student : students) {
        if (name == student.fullName) {
            found = true;
            switch(choice) {
                case 1:
                    editStudentFullName();
                    break;
                case 2:
                    editStudentGroupNumber();
                    break;
                case 3:
                    editStudentEducationForm();
                    break;
                case 4:
                    editStudentActiveness();
                    break;
                case 5:
                    editStudentMarks();
                    break;
                case 6:
                    editStudentCredits();
                    break;
                case 0:
                    return;
                default:
                    std::cout << "Enter correct number!" << std::endl;
                    break;
            }
        }
    }

    writeStudents(students);
}