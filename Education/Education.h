#pragma once
#include <string>
#include <vector>
#include <map>
#include "../User/User.h"

struct Student {
	std::string fullName;
	int groupNumber;
	std::string educationForm; // Budget/Paid
	bool isActive;
	std::map<std::string, int> marks; 
	std::map<std::string, bool> credit;
	Student(int groupNumber, std::string fullName, std::string educationForm, bool isActive, std::map<std::string, int> marks, std::map<std::string, bool> credit) {
		this->groupNumber = groupNumber;
		this->fullName = fullName;
		this->isActive = isActive;
		this->marks = marks;
		this->credit = credit;
	}
};

const std::string STUDENT_DATABASE = "student_database.txt";
std::vector<Student> getStudents();
double average(std::map<std::string, int> marks, bool& isExcellent);
void outputStudents(Session& session);
void outputScholarship(Session& session, double baseScholarship);
double calculateScholarship(Student student, double baseScholarship);
