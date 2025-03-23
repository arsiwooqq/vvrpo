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

    Session() {};

    Session(std::string login, std::string role, std::string access) {
        this->login = login;
        this->role = role;
        this->access = access;
    }
};

std::vector <User> getUsers();
Session authUser (std::string login, std::string password);
void regUser(std::string login, std::string password, std::string role);
