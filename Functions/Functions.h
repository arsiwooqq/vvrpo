#pragma once
#include "../User/User.h"
#include "../Education/Education.h"

void outputAccounts(Session& session);
void outputStudents(Session& session);
void outputScholarship(Session& session, double baseScholarship);
void searchByName(Session& session);
void searchByMark(Session& session);
void searchByGroup(Session& session);
void sortByName(Session& session);
void sortByMark(Session& session);
void sortByGroup(Session& session);
void addAccount(Session& session);
void addStudent(Session& session);
void editAccount(Session& session);
void editStudent(Session& session);
void deleteAccount(Session& session);
void deleteStudent(Session& session);
double calculateScholarship(Student student, double baseScholarship);