//
// Created by piotr on 20/07/01.
//

#ifndef RASPBERRY_SQL_USERDAO_H
#define RASPBERRY_SQL_USERDAO_H

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

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
    std::string photo_path;
    std::string rfid;

public:
    UserDAO(sql::Connection* connection,
            int id,
            std::string username,
            std::string email,
            std::string creation_date,
            std::string name,
            std::string surname,
            std::string hashed_pswd,
            std::string rfid)
            : connection{ connection },
              id{ id },
              username{ username },
              email{ email },
              creation_date{ creation_date },
              name{ name },
              surname{ surname },
              hashed_pswd{ hashed_pswd },
              rfid{rfid}
    {}

    UserDAO(std::string email, std::string name):id {0},email{email}, name{name}{}

    // add new subscription (when user buys one)
    void add_subscription(int subscription_type);

    // storing only photos in databse, photos should be kept in the device's memory
    void add_update_photo_path(std::string photo_path);

    // adds or updates rfid
    void add_update_rfid(std::string rfid);

    // update user data
    void update_user(std::string username,
                     std::string email,
                     std::string name,
                     std::string surname);
    void update_user_username(std::string username);
    void update_user_email(std::string email);
    void update_user_hashed_pswd(std::string new_password);
    void update_user_name(std::string name);
    void update_user_surname(std::string surname);
    void update_user_rfid(std::string rfid);

    // deletes the user from database
    void delete_user();
};


#endif //RASPBERRY_SQL_USERDAO_H
