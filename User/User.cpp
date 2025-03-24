#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <functional>
#include "User.h"

/**
 * Получение списка пользователей в виде вектора
 */
std::vector <User> getUsers() {
    std::vector <User> users;
    std::string login, password, salt, role, access;
    try {
        std::ifstream File(USER_DATABASE);
        if (!File.is_open()) {
            throw std::string{"File not found!"};
        }
        while (File >> login >> password >> salt >> role >> access) {
            users.push_back(User(login, password, salt, role, access));
        }
    } catch (std::string e) {
        std::cout << e << std::endl;
    } catch (...) {
        std::cout << "Error!" << std::endl;
    }

    return users;
}


/**
 * Проверка на существование пользователя по логину
 * true – существует
 * false – не существует
 */
bool isExist(std::string login) {
    std::vector <User> users = getUsers();
    for (User user : users) {
        if (user.login == login) {
            return true;
        }
    }
    return false;
}


/**
 * Получение пользователя по логину
 * возвращает объект пользователя или выбрасывает ошибку
 */
User getUser(std::string login) {
    std::vector <User> users = getUsers();
    for (User user : users) {
        if (user.login == login) {
            return user;
        }
    }
    throw std::string{"User not found!"};
}

/**
 * Генерирует соль для хеширования пароля
 * Необходимо для безопасного хранения
 */
std::string generateSalt(int length) {
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::random_device random;
    std::mt19937 generator(random());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);

    std::string salt;
    for (int i = 0; i < length; ++i) {
        salt += characters[distribution(generator)];
    }
    return salt;
}

/**
 * Хэширует пароль используя соль
 */
std::string hashPassword(std::string password, std::string salt) {
    std::hash <std::string> hash;
    return std::to_string(hash(password + salt));
}

/**
 * Регистрация пользователя с хешированием пароля
 * Роль либо user, либо admin
 */
void regUser(std::string login, std::string password, std::string role) {
    if (!isExist(login)) {
        if (login.size() < 8) {
            throw std::string{"Login cannot be shorter than 8 characters!"};
        }
        if (password.size() < 8) {
            throw std::string{"Password cannot be shorter than 8 characters!"};
        }
        std::ofstream File(USER_DATABASE, std::ios::app);
        std::string salt = generateSalt(32);
        std::string hashedPassword = hashPassword(password, salt);
    
        File << login << " " << hashedPassword << " " << salt << " " << role << " " << "unactive" << std::endl;
    } else {
        throw std::string{"This login already exists!"};
    }
}

/**
 * Авторизация пользователя
 * В случае успеха возвращается роль
 * Иначе – ошибка
 */
Session authUser (std::string login, std::string password) {
    if (isExist(login)) {
        User user = getUser(login);
        std::string hashedPassword = hashPassword(password, user.salt);
        if (user.password == hashedPassword) {
            return Session(user.login, user.role, user.access);
        }
    }
    throw std::string{"Login or password is not correct!"};
}

bool isAuthorized(Session& currentSession) {
    if (currentSession.login == "" && currentSession.role == "" && currentSession.access == "")
        return false;
    return true;
}