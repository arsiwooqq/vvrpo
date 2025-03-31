#pragma once
#include "../../Education/Education.h"
#include "../../User/User.h"

void writeStudent(Student& student);
void writeStudents(std::vector <Student> students);
void writeUser(User& user);
void writeUsers(std::vector <User> users);
std::map<std::string, int> enterMarks();
std::map<std::string, bool> enterCredits();
bool checkDeletionPossibility(std::string login);