#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
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

void searchByName(Session& currentSession) {
    std::string name;
    std::cout << "Enter name to search: ";
    std::cin >> name;
    
    std::vector<Student> students = getStudents();
    bool found = false;
    
    for (const auto& student : students) {
        if (student.fullName.find(name) != std::string::npos) {
            std::cout << "Found: " << student.fullName 
                      << ", Group: " << student.groupNumber 
                      << ", Form: " << student.educationForm << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No students found with name: " << name << std::endl;
    }
}

void searchByMark(Session& currentSession) {
    double mark;
    bool isExcellent;
    std::cout << "Enter minimum mark to search: ";
    std:: cin >> mark;
    
    std::vector<Student> students = getStudents();
    bool found = false;
    
    for (const auto& student : students) {
        double avg = average(student.marks, isExcellent);
        if (avg >= mark) {
            found = true;
            std::cout << "Found: " << student.fullName 
                      << ", Group: " << student.groupNumber 
                      << ", Form: " << student.educationForm
                      << ", Avg mark: " << avg << std::endl;
        }
    }
    if (!found) {
        std::cout << "No students found with mark >= " << mark << std::endl;
    }
}

void searchByGroup(Session& currentSession) {
    int group;
    std::cout << "Enter group number to search: ";
    std:: cin >> group;
    
    std::vector<Student> students = getStudents();
    bool found = false;
    
    for (const auto& student : students) {
        if (student.groupNumber == group) {
            std::cout << "Found: " << student.fullName 
                      << ", Group: " << student.groupNumber 
                      << ", Form: " << student.educationForm << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No students found in group: " << group << std::endl;
    }
}

void sortByName(Session& currentSession) {
    std::vector<Student> students = getStudents();
    std::sort(students.begin(), students.end(), 
        [](const Student& a, const Student& b) {
            return a.fullName < b.fullName;
        });
    
    std::cout << "Sorted by name:" << std::endl;
    for (const auto& student : students) {
        std::cout << student.fullName << ", Group: " << student.groupNumber << std::endl;
    }
}

void sortByGroup(Session& currentSession) {
    std::vector<Student> students = getStudents();
    std::sort(students.begin(), students.end(), 
        [](const Student& a, const Student& b) {
            return a.groupNumber < b.groupNumber;
        });
    
    std::cout << "Sorted by group:" << std::endl;
    for (const auto& student : students) {
        std::cout << student.fullName << ", Group: " << student.groupNumber << std::endl;
    }
}

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
    for (const auto& student : students) {
        bool excellent;
        double avg = average(student.marks, excellent);
        std::cout << student.fullName << ", Average: " << avg << std::endl;
    }
}

void viewAllAccounts(Session& currentSession) {
    std::vector<User> users = getUsers();
    std::cout << "All accounts:" << std::endl;
    for (const auto& user : users) {
        std::cout << "Login: " << user.login 
                  << ", Role: " << user.role 
                  << ", Access: " << user.access << std::endl;
    }
}

void addNewAccount(Session& currentSession) {
    std::string login, password, role;
    std::cout << "Enter login: " << std::endl;
    std::cin >> login;
    std::cout << "Enter password: " << std::endl;
    std::cin >> password;  
    std::cout << "Enter role (user/admin): " << std::endl;
    std::cin >> role;
    try {
        regUser(login, password, role, true);
        std::cout << "Account created successfully!" << std::endl;
    } catch (const std::string& e) {
        std::cout << "Error: " << e << std::endl;
    }
}

void editStudent(Session& currentSession) {
    std::string name;
    std::cout << "Enter student name to edit: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    
    std::vector<Student> students = getStudents();
    for (auto& student : students) {
        if (student.fullName == name) {
            std::cout << "Enter new group number: ";
            std::cin >> student.groupNumber;
            std::cout << "Enter new education form (Budget/Paid): ";
            std::cin >> student.educationForm;
            std::cout << "Student updated successfully!" << std::endl;
        }
    }
    std::ofstream file(STUDENT_DATABASE);
    
    for (const auto& student : students) {
        file << student.groupNumber << std::endl << student.fullName << std::endl << student.educationForm << std::endl << student.isActive << std::endl;
        for (const auto& [subject, mark] : student.marks) {
            file << subject << " " << mark << " ";
        }
        file << std::endl;
        for (const auto& [subject, credited] : student.credit) {
            file << subject << " " << (credited ? 1 : 0) << " ";
        }
        file << std::endl;
    }
}

void deleteStudent(Session&) {
    std::string name;
    std::cout << "Enter student name to delete: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::vector<Student> students = getStudents();
    std::ofstream file(STUDENT_DATABASE);

    bool deleted = false;
    for (const auto& student : students) {
        if (student.fullName != name) {
            file << student.groupNumber << std::endl
                 << student.fullName << std::endl
                 << student.educationForm << std::endl
                 << student.isActive << std::endl;

            for (const auto& [subject, mark] : student.marks) {
                file << subject << " " << mark << " ";
            }
            file << std::endl;

            for (const auto& [subject, credited] : student.credit) {
                file << subject << " " << (credited ? 1 : 0) << " ";
            }
            file << std::endl;
        } else {
            deleted = true;
        }
    }

    std::cout << (deleted ? "Student deleted successfully!" : "Student not found!") << std::endl;
}


void addStudent(Session& currentSession) {
    std::string fullName, educationForm;
    int groupNumber;
    bool isActive;
    
    std::cout << "Enter full name: ";
    std::cin.ignore();
    std::getline(std::cin, fullName);
    std::cout << "Enter group number: ";
    std::cin >> groupNumber;
    std::cout << "Enter education form (Budget/Paid): ";
    std::cin >> educationForm;
    std::cout << "Is active? (1/0): ";
    int activeChoice;
    std:: cin >> activeChoice;
    isActive = activeChoice == 1;
    
    // Ввод оценок (4 предмета)
    std::map<std::string, int> marks;
    std::cout << "Enter 4 marks (subject mark):" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::string subject;
        int mark;
        std::cout << "Subject " << i + 1 << ": ";
        std::cin >> subject;
        std::cout << "Mark: ";
        std:: cin >> mark;
        marks[subject] = mark;
    }
    
    // Ввод зачетов (4 предмета)
    std::map<std::string, bool> credits;
    std::cout << "Enter 4 credits (subject 1/0):" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::string subject;
        int credited;
        std::cout << "Subject " << i + 1 << ": ";
        std::cin >> subject;
        std::cout << "Credited (1/0): ";
        std:: cin >> credited;
        credits[subject] = credited == 1;
    }
    
    // Открываем файл для добавления
    std::ofstream file(STUDENT_DATABASE, std::ios::app);
    
    // Записываем нового студента
    file << groupNumber << std::endl << fullName << std::endl << educationForm << std::endl << isActive << std::endl;
    for (const auto& [subject, mark] : marks) {
        file << subject << " " << mark << " ";
    }
    file << std::endl;
    for (const auto& [subject, credited] : credits) {
        file << subject << " " << (credited ? 1 : 0) << " ";
    }
    file << std::endl;
    
    file.close();
    std::cout << "Student added successfully!" << std::endl;
}

void editAccount(Session& currentSession) {
    std::string login;
    std::cout << "Enter login of account to edit: ";
    std::cin >> login;
    
    std::vector<User> users = getUsers();
    bool found = false;
    
    for (auto& user : users) {
        if (user.login == login) {
            found = true;
            std::string newPassword;
            std::cout << "Enter new password: ";
            std::cin >> newPassword;
            editPassword(login, newPassword);
            std::cout << "Account updated successfully!" << std::endl;
            break;
        }
    }
    
    if (!found) {
        std::cout << "Account not found!" << std::endl;
    }
}

void deleteAccount(Session&) {
    std::string login;
    std::cout << "Enter login of account to delete: ";
    std::cin >> login;

    std::vector<User> users = getUsers();
    std::ofstream file(USER_DATABASE);

    bool deleted = false;
    for (const auto& user : users) {
        if (user.login != login) {
            file << user.login << " " << user.password << " " << user.salt << " "
                 << user.role << " " << user.access << "\n";
        } else {
            deleted = true;
        }
    }

    std::cout << (deleted ? "Account deleted successfully!" : "Account not found!") << std::endl;
}

void activateAccount(Session& currentSession) {
    std::string login;
    std::cout << "Enter login: ";
    std::cin >> login;
    
    std::vector<User> users = getUsers();
    for (User& user : users) {
        if (user.login == login) {
            user.access = "active";
            std::cout << "Account activated successfully!" << std::endl;
            break;
        }
    }
    std::ofstream file(USER_DATABASE);
    for (const auto& u : users) {
        file << u.login << " " << u.password << " " << u.salt << " "
                << u.role << " " << u.access << "\n";
    }
}