//
// Created by piotr on 20/06/30.
//

#ifndef UNTITLED_DAO_H
#define UNTITLED_DAO_H

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using BLOB = void*;
class KodokanDAO;

class UserDAO {
public:
    sql::Connection* connection;
    const int id;
    std::string username;
    std::string email;
    std::string creation_date;
    std::string name;
    std::string surname;
    std::string hashed_pswd;
    BLOB photo = nullptr;

public:
    UserDAO(sql::Connection* connection,
            int id,
            std::string username,
            std::string email,
            std::string creation_date,
            std::string name,
            std::string surname,
            std::string hashed_pswd);

    void add_subscription(int subscription_type);
    bool is_subscription_active();
    void add_photo();
    friend std::ostream& operator<<(std::ostream& os, const UserDAO& user);
};

class KodokanDAO
{
private:
    static const char* server_name;
    static const char* username;
    static const char* username_visual_studio;
    static const char* password;
    static const char* database_name;
    sql::Driver* driver;
    sql::Connection* connection;

public:
    KodokanDAO();
    UserDAO* authorize_user(std::string login, std::string password);
    bool add_user(std::string login, std::string email, std::string name, std::string surname, std::string password, BLOB photo = nullptr);
    void list_users();
    ~KodokanDAO();
};

#endif //UNTITLED_DAO_H
