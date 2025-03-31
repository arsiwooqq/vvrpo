#pragma once
#include <string>
#include <vector>
#include <map>

struct Student {
	std::string fullName;
	int groupNumber;
	std::string educationForm; // Budget/Paid
	bool isActive;
	std::map<std::string, int> marks; 
	std::map<std::string, bool> credits;
	Student(std::string fullName, int groupNumber, std::string educationForm, bool isActive, std::map<std::string, int> marks, std::map<std::string, bool> credits) {
		this->fullName = fullName;
		this->groupNumber = groupNumber;
		this->educationForm = educationForm;
		this->isActive = isActive;
		this->marks = marks;
		this->credits = credits;
	}
};

const std::string STUDENT_DATABASE = "student_database.txt";
std::vector<Student> getStudents();
double average(std::map<std::string, int> marks, bool& isExcellent);