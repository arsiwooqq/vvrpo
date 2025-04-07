#include <iostream>
#include <fstream>
#include "Menu.h"
#include "../User/User.h"
#include "../Education/Education.h"
#include "../Functions/Functions.h"
#include "../Functions/Instruments/Instruments.h"

const std::string BASE_SCHOLARSHIP = "base_scholarship.txt";

void enterNumber(double& number) {
    do {
        std::cin >> number;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a valid number." << std::endl;
        } else {
            break;
        }
    } while (true);
}

void enterScholarship(double& scholarship) {
    std::cout << "Enter scholarship:";
    std::cin >> scholarship;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number!" << std::endl;
    }
}

/**
 * Меню для авторизации 
 */
void loginMenu(int& choice) {
    clearConsole();
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Register" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    enterNumber(choice);
}

/**
 * Функция ввода логина и пароля
 */
void enterLoginAndPassword(std::string& login, std::string& password) {
    std::cout << "Enter login: " ;
    std::cin >> login;
    std::cout << "Enter password: ";
    std::cin >> password;
}

/**
 * Функция приветствия (при успешной авторизации)
 */
void welcome(Session currentSession) {
    std::cout << "Welcome, " << currentSession.login << "!" << std::endl;
    std::cout << "You're logged in as " << currentSession.role << std::endl;
}

/**
 * Функция начального экрана (если программа запущена впервые)
 */
void greeting(Session& currentSession) {
    if (!fileExists(USER_DATABASE)) {
        std::cout << "It seems you're running this application for the first time.\nLet's register an account for you!" << std::endl;

        do {
            std::string login, password;
            enterLoginAndPassword(login, password);
            
            try {
                regFirstUser(login, password);
                currentSession = authUser(login, password);
                welcome(currentSession);
                pressAnyKeyToContinue();
            } catch (std::string e) {
                std::cout << e << std::endl;
                pressAnyKeyToContinue();
            }

        } while (!fileExists(USER_DATABASE));
    }
}

/**
 * Основное меню авторизации
 */
void authMenu(Session& currentSession) {
    greeting(currentSession);
    int choice;
    do {
        std::string login, password, role;
        loginMenu(choice);
        switch (choice) {
            case 1:
                enterLoginAndPassword(login, password);

                try {
                    currentSession = authUser(login, password);
                    welcome(currentSession);
                    pressAnyKeyToContinue();
                } catch (std::string e) {
                    std::cout << e << std::endl;
                    pressAnyKeyToContinue();
                }

                break;
            case 2:
                selectRole(role);
                enterLoginAndPassword(login, password);

                try {
                    regUser(login, password, role, false);
                    currentSession = authUser(login, password);
                    welcome(currentSession);
                    pressAnyKeyToContinue();
                } catch (std::string e) {
                    std::cout << e << std::endl;
                    pressAnyKeyToContinue();
                }

                break;

            case 3:
                exit(0);
            
            default: 
                std::cout << "Enter correct number!" << std::endl;
        }
    } while (!isAuthorized(currentSession));
}

void searchMenu(int& choice) {
    std::cout << "Search menu:" << std::endl;
    std::cout << "1. Search by name" << std::endl;
    std::cout << "2. Search by group" << std::endl;
    std::cout << "3. Search by mark" << std::endl;
    std::cout << "0. Back" << std::endl;
    enterNumber(choice);
}

void sortMenu(int& choice) {
    std::cout << "Sort menu:" << std::endl;
    std::cout << "1. Sort by name" << std::endl;
    std::cout << "2. Sort by group" << std::endl;
    std::cout << "3. Sort by mark" << std::endl;
    std::cout << "0. Back" << std::endl;
    enterNumber(choice);
}

/**
 * Меню для обычного пользователя 
 */
void userMenu(Session& currentSession) {
    if (currentSession.access == "unactive") {
        std::cout << "Your account is not activated yet!" << std::endl;
        std::cout << "Logging out..." << std::endl;
        pressAnyKeyToContinue();
        currentSession = Session();
        return;
    }
    do {
        clearConsole();
        int choice; 
        std::cout << "User menu:" << std::endl;
        std::cout << "1. View Data" << std::endl;
        std::cout << "2. Calculate Scholarship" << std::endl;
        std::cout << "3. Search Data" << std::endl;
        std::cout << "4. Sort Data" << std::endl;
        std::cout << "0. Log out" << std::endl;
        enterNumber(choice);
        switch (choice) {
            case 1:
                outputStudents(currentSession);
                break;
    
            case 2:
                double baseScholarship;
                enterScholarship(baseScholarship);
                outputScholarship(currentSession, baseScholarship);
                break;
    
            case 3:
                searchMenu(choice);
                switch (choice) {
                    case 1:
                        searchByName(currentSession);
                        break;
                    case 2:
                        searchByGroup(currentSession);
                        break;
                    case 3:
                        searchByMark(currentSession);
                        break;
                    case 0:
                        break;
                    default:
                        std::cout << "Enter correct number!" << std::endl;
                        break;
                }
                break;
            case 4:
                sortMenu(choice);
                switch (choice) {
                    case 1:
                        sortByName(currentSession);
                        break;
                    case 2:
                        sortByGroup(currentSession);
                        break;
                    case 3:
                        sortByMark(currentSession);
                        break;
                    case 0:
                        break;
                    default:
                        std::cout << "Enter correct number!" << std::endl;
                        break;
                }
                break;
            case 0: 
                currentSession = Session();
                return;
            default:
                std::cout << "Enter correct number!" << std::endl;
        }
    } while (true);
}
/**
 * Меню для администратора
 */
void adminMenu(Session& currentSession) {
    if (currentSession.access == "unactive") {
        std::cout << "Your account is not activated yet!" << std::endl;
        std::cout << "Logging out..." << std::endl;
        pressAnyKeyToContinue();
        currentSession = Session();
        return;
    }
    do {
        int choice;
        clearConsole();
        std::cout << "Admin menu:" << std::endl;
        std::cout << "1. Account management" << std::endl;
        std::cout << "2. Work with data" << std::endl;
        std::cout << "0. Log out" << std::endl;
        enterNumber(choice);
        switch (choice) {
            case 1:
                clearConsole();
                std::cout << "Account management menu:" << std::endl;
                std::cout << "1. View all accounts" << std::endl;
                std::cout << "2. Add new account" << std::endl;
                std::cout << "3. Edit account" << std::endl;
                std::cout << "4. Delete account" << std::endl;
                std::cout << "0. Back" << std::endl;
                enterNumber(choice);
                switch (choice) {
                    case 1:
                        outputAccounts(currentSession);
                        break;
                    case 2:
                        addAccount(currentSession);
                        break;
                    case 3:
                        editAccount(currentSession);
                        break;
                    case 4:
                        deleteAccount(currentSession);
                        break;
                    case 0:
                        break;
                    default:
                        std::cout << "Enter correct number!" << std::endl;
                }
                break;
            case 2:
                clearConsole();
                std::cout << "Edit data menu:" << std::endl;
                std::cout << "1. View data" << std::endl;
                std::cout << "2. Add data" << std::endl;
                std::cout << "3. Edit data" << std::endl;
                std::cout << "4. Delete data" << std::endl;
                std::cout << "5. Calculate scholarship" << std::endl;
                std::cout << "6. Search data" << std::endl;
                std::cout << "7. Sort data" << std::endl;
                std::cout << "0. Back" << std::endl;
                enterNumber(choice);
                switch(choice) {
                    case 1:
                        outputStudents(currentSession);
                        break;
                    case 2:
                        addStudent(currentSession);
                        break;
                    case 3:
                        editStudent(currentSession);
                        break;
                    case 4:
                        deleteStudent(currentSession);
                        break;
                    case 5:
                        double baseScholarship;
                        enterScholarship(baseScholarship);
                        outputScholarship(currentSession, baseScholarship);
                        break;
                    case 6:
                        searchMenu(choice);
                        switch (choice) {
                            case 1:
                                searchByName(currentSession);
                                break;
                            case 2:
                                searchByGroup(currentSession);
                                break;
                            case 3:
                                searchByMark(currentSession);
                                break;
                            case 0:
                                break;
                            default:
                                std::cout << "Enter correct number!" << std::endl;
                        }
                        break;
                    case 7:
                        sortMenu(choice);
                        switch (choice) {
                            case 1:
                                sortByName(currentSession);
                                break;
                            case 2:
                                sortByGroup(currentSession);
                                break;
                            case 3:
                                sortByMark(currentSession);
                                break;
                            case 0:
                                break;
                            default:
                                std::cout << "Enter correct number!" << std::endl;
                        }
                        break;
                    case 0:
                        break;
                    default:
                        std::cout << "Enter correct number!" << std::endl;
                }
                break;
            case 0: 
                currentSession = Session();
                return;
            default:
                std::cout << "Enter correct number!" << std::endl;
        }
    } while (true);
}

/**
 * Основное меню программы
 */
void mainMenu(Session& currentSession) {
    if (!isAuthorized(currentSession)) {
        authMenu(currentSession);
    }

    if (currentSession.role == "user") {
        userMenu(currentSession);
    }

    if (currentSession.role == "admin") {
        adminMenu(currentSession);
    }
}
