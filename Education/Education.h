#pragma once
#include <string>
#include <vector>
#include <map>

struct Student {
	std::string login;
	int groupNumber;
	std::string fullName;
	std::string educationForm; // Budget/Paid
	bool isActive;
	std::map<std::string, int> marks; 
	std::map<std::string, bool> credit;
	Student(std::string login, int groupNumber, std::string fullName, std::string educationForm, bool isActive, std::map<std::string, int> marks, std::map<std::string, bool> credit) {
		this->login = login;
		this->groupNumber = groupNumber;
		this->fullName = fullName;
		this->isActive = isActive;
		this->marks = marks;
		this->credit = credit;
	}
};

const std::string STUDENT_DATABASE = "student_database.txt";
