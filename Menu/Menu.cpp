#include <iostream>
#include "Menu.h"
#include "../User/User.h"

/**
 * Функция для ввода выбора пользователем
 * Защищена от некорректного ввода
 */
void enterChoice(int& choice) {
    std::cin >> choice;
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
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Register" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    enterChoice(choice);
}

/**
 * Функция ввода логина и пароля
 */
void enterLoginAndPassword(std::string& login, std::string& password) {
    std::cout << "Enter login: " ;
    std::cin >> login;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << std::endl;
}

/**
 * Функция выбора роли при регистрации
 */
void selectRole(std::string& role) {
    do {
        int choice;
        std::cout << "Select role: " << std::endl;
        std::cout << "1. User" << std::endl;
        std::cout << "2. Admin" << std::endl;
        std::cout << "Enter your choice: ";
        enterChoice(choice);
        switch (choice) {
            case 1: 
                role = "user";
                break;
            case 2:
                role = "admin";
                break;
            default:
                std::cout << "Enter correct role!" << std::endl;
        }
    } while (role != "user" && role != "admin");
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
            } catch (std::string e) {
                std::cout << e << std::endl;
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
                } catch (std::string e) {
                    std::cout << e << std::endl;
                }

                break;
            /**
             * TODO: очень нужно сделать выход из аккаунта, запретить вход и регистрацию если сессия активна
             */
            case 2:
                selectRole(role);
                enterLoginAndPassword(login, password);

                try {
                    regUser(login, password, role);
                    currentSession = authUser(login, password);
                    welcome(currentSession);
                } catch (std::string e) {
                    std::cout << e << std::endl;
                }

                break;

            case 3:
                exit(0);
            
            default: 
                std::cout << "Enter correct number!" << std::endl;
        }
    } while (!isAuthorized(currentSession));
}

/**
 * Меню для обычного пользователя 
 */
void userMenu() {
    std::cout << "This is user menu." << std::endl;
}

/**
 * Меню для администратора
 */
void adminMenu() {
    std::cout << "This is admin menu." << std::endl;
}

/**
 * Основное меню программы
 */
void mainMenu(Session& currentSession) {
    if (!isAuthorized(currentSession)) {
        authMenu(currentSession);
    }

    if (currentSession.role == "user") {
        userMenu();
    }

    if (currentSession.role == "admin") {
        adminMenu();
    }
}
