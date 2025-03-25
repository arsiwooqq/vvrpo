#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <functional>
#include "Education.h"
#include "../User/User.h"

std::map<std::string, int> readMarks() { // функция для чтения из файла map
	std::ifstream file(STUDENT_DATABASE);
	std::map<std::string, int> marks;
	for (int i = 0; i < 4; i++) {
		std::string key;
		int value;
		file >> key >> value;
		marks[key] = value;
	}
	return marks;
}

std::map<std::string, bool> readCredits() {
	std::ifstream file(STUDENT_DATABASE);
	std::map<std::string, bool> credit;
	for (int i = 0; i < 5; i++) {
		std::string key;
		int value;
		file >> key >> value;
		credit[key] = value;
	}
	return credit;
}


std::vector<Student> getStudents() { // получение студентов из файла, формирование вектора
	std::ifstream file(STUDENT_DATABASE);

	std::vector<Student> students;
	std::string login, fullName, educationForm;
	int groupNumber;
	bool isActive;
	std::map<std::string, int> marks;
	std::map<std::string, bool> credit;

	try {
		if (!file.is_open()) {
			throw std::string{"File not found!"};
		}
		while (file >> login >> groupNumber >> fullName >> educationForm >> isActive) {
			marks = readMarks();
			credit = readCredits();
			students.push_back(Student(login,groupNumber, fullName, educationForm, isActive, marks, credit));
		}
	}
	catch (std::string e) {
		std::cout << e << std::endl;
	}
	catch (...) {
		std::cout << "Error!" << std::endl;
	}
	return students;
}

bool isCredit(std::map<std::string, bool> credit) { // функция для определения есть ли незачет
	for (auto pair : credit) {
		if (pair.second == false) {
			return false;
		}
	}
	return true;
}

double average(std::map<std::string, int> marks, bool& isExcellent) { // функция для расчета среднего балла и получения bool=false если человек не отличник
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

double calculateScholarship(Student student, double baseScholarship) { // вычисление стипендии
	bool isExcellent;
	bool isCredited = isCredit(student.credit);
	double ball = average(student.marks, isExcellent);

	if (student.educationForm == "Paid" || ball <= 5 || !isCredited) {
		std::cout << "Student hasn't scholarsip." << std::endl;
		return 0.0;
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