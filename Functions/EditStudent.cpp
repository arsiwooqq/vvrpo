#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Functions.h"
#include "../Education/Education.h"
#include "Instruments/Instruments.h"
#include "../Menu/Menu.h"

void editStudentMenu(int& choice) {
    clearConsole();
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

void editStudentFullName(std::vector <Student> &students, Student &student) {
    std::string newFullName;
    std::cout << "Enter full name: ";
    std::getline(std::cin, newFullName);
    student.fullName = newFullName;
    writeStudents(students);
}

void editStudentGroupNumber(std::vector <Student> &students, Student &student) {
    int newGroupNumber;
    std::cout << "Enter group: ";
    enterNumber(newGroupNumber);
    student.groupNumber = newGroupNumber;
    writeStudents(students);
}

void editStudentEducationForm(std::vector <Student> &students, Student &student) {
    std::string newEducationForm;
    std::cout << "Enter education form (Budget/Paid): ";
    enterEducationForm(newEducationForm);
    student.educationForm = newEducationForm;
    writeStudents(students);
}

void editStudentActiveness(std::vector <Student> &students, Student &student) {
    bool isActive;
    std::cout << "Enter activeness (yes/no): ";
    student.isActive = selectYesNo();
    writeStudents(students);
}

void editStudentMarks(std::vector <Student> &students, Student &student) {
    student.marks = enterMarks();
    writeStudents(students);
}

void editStudentCredits(std::vector <Student> &students, Student &student) {
    student.credits = enterCredits();
    writeStudents(students);
}

void editStudent(Session& currentSession) {
    int choice;
    std::string name;
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    
    std::vector<Student> students = getStudents();
    bool found = false;
    
    for (Student& student : students) {
        if (toLowerCase(name) == toLowerCase(student.fullName)) {
            found = true;
            do {
                editStudentMenu(choice);
                switch(choice) {
                    case 1:
                        editStudentFullName(students, student);
                        break;
                    case 2:
                        editStudentGroupNumber(students, student);
                        break;
                    case 3:
                        editStudentEducationForm(students, student);
                        break;
                    case 4:
                        editStudentActiveness(students, student);
                        break;
                    case 5:
                        editStudentMarks(students, student);
                        break;
                    case 6:
                        editStudentCredits(students, student);
                        break;
                    case 0:
                        return;
                    default:
                        std::cout << "Enter correct number!" << std::endl;
                        pressAnyKeyToContinue();
                        break;
                }
            } while (choice != 0);
            std::cout << "Student updated successfully!" << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "Student not found!" << std::endl;
    }

    pressAnyKeyToContinue();
}