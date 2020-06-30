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
                std::string hashed_pswd)
                : connection{ connection },
                  id{ id },
                  username{ username },
                  email{ email },
                  creation_date{ creation_date },
                  name{ name },
                  surname{ surname },
                  hashed_pswd{ hashed_pswd },
                  photo{ photo }
    {    }

    void add_subscription(int subscription_type);
    bool is_subscription_active();
    void add_photo();
    friend std::ostream& operator<<(std::ostream& os, const UserDAO& user);
};

class KodokanDAO {
private:
    const char* server_name = "kodokanserver.mysql.database.azure.com";
    const char* username = "azureuser";
    const char* username_visual_studio = "azureuser@kodokanserver";
    const char* password = "Kodokan123";
    const char* database_name = "kodokan_database";
    sql::Driver* driver;
    sql::Connection* connection = nullptr;
    KodokanDAO();
    static KodokanDAO* instance;
public:
    static KodokanDAO* getInstance();
    UserDAO* authorize_user(std::string login, std::string password);
    bool add_user(std::string login, std::string email, std::string name, std::string surname, std::string password, BLOB photo = nullptr);
    void list_users();
    ~KodokanDAO();
};

#endif //UNTITLED_DAO_H
