#pragma once
#include <vector>
#include <string>

/**
 * Структура пользователя
 * Описывает возможные данные о пользователе
 */
struct User {
    std::string login; 
    std::string password;
    std::string salt;
    std::string role;
    std::string access;

    User(std::string login, std::string password, std::string salt, std::string role, std::string access) {
        this->login = login;
        this->password = password;
        this->salt = salt;
        this->role = role;
        this->access = access;
    }
};

/**
 * Структура сессии
 * Используется для хранения данных
 * о текущей сессии
 */
struct Session {
    std::string login;
    std::string role;
    std::string access;

    Session() {
        this->login = "";
        this->role = "";
        this->access = "";
    };

    Session(std::string login, std::string role, std::string access) {
        this->login = login;
        this->role = role;
        this->access = access;
    }
};

const std::string USER_DATABASE = "user_database.txt";
std::vector <User> getUsers();
Session authUser (std::string login, std::string password);
std::string generateSalt(int length);
std::string hashPassword(std::string password, std::string salt);
void regUser(std::string login, std::string password, std::string role, bool isActive);
void regFirstUser(std::string login, std::string password);
void editPassword(std::string login, std::string newPassword);
bool fileExists(std::string file);
bool isAuthorized(Session& currentSession);