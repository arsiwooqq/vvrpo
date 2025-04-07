#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <functional>
#include "Education.h"
#include "../User/User.h"
#include "../Functions/Instruments/Instruments.h"

std::map<std::string, int> readMarks(std::ifstream& file) {
    std::map<std::string, int> marks;
    for (int i = 0; i < 4; i++) {
        std::string key;
        int value;
        if (!(file >> key >> value)) {
            std::cerr << "Error reading marks!" << std::endl;
            break;
        }
        marks[key] = value;
    }
    return marks;
}

std::map<std::string, bool> readCredits(std::ifstream& file) {
    std::map<std::string, bool> credits;
    for (int i = 0; i < 4; i++) {
        std::string key;
        int value;
        if (!(file >> key >> value)) {
            std::cerr << "Error reading credits!" << std::endl;
            break;
        }
        credits[key] = value;
    }
    return credits;
}



std::vector<Student> getStudents() {
	std::ifstream file(STUDENT_DATABASE);

	std::vector<Student> students;
	std::string fullName, educationForm;
	int groupNumber;
	int isActive;
	std::map<std::string, int> marks;
	std::map<std::string, bool> credits;

	try {
		if (!file.is_open()) {
			throw std::string{"File not found!"};
		}

		while (file >> groupNumber) {
			file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(file, fullName);
			file >> educationForm >> isActive;
			marks = readMarks(file);
			credits = readCredits(file);
			students.push_back(Student(fullName, groupNumber, educationForm, isActive, marks, credits));
		}
	} catch (const std::string& e) {
		std::cout << "Error: " << e << std::endl;
	} catch (...) {
		std::cout << "Unknown error!" << std::endl;
	}

	return students;
}

bool isCredit(std::map<std::string, bool> credits) {
	for (auto pair : credits) {
		if (pair.second == false) {
			return false;
		}
	}
	return true;
}

double average(std::map<std::string, int> marks, bool& isExcellent) {
	isExcellent = true;
	double sum = 0, average;
	for (auto& pair : marks) {
		sum += pair.second;
		if (pair.second < 9) {
			isExcellent = false;
		}
	}
	average = sum / 4;
	return average;
}

double calculateScholarship(Student student, double baseScholarship) {
	bool isExcellent;
	bool isCredited = isCredit(student.credits);
	double ball = average(student.marks, isExcellent);

	if (toLowerCase(student.educationForm) == "paid" || ball <= 5 || !isCredited) {
		return 0;
	}

	if (isExcellent && student.isActive) {
		return baseScholarship * 1.5;
	}
	else  if (isExcellent) {
		return baseScholarship * 1.25;
	}
	else {
		return baseScholarship;
	}
}