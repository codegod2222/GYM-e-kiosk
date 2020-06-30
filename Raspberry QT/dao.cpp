//
// Created by piotr on 20/06/30.
//

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "dao.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <QDebug>

// compiling on raspberry with line:
// sudo g++ -Wall -I/usr/include/cppconn -o test cppconn.cpp -L/usr/lib -lmysqlcppconn

/*KodokanDAO::server_name = "kodokanserver.mysql.database.azure.com";
KodokanDAO::username = "azureuser";
KodokanDAO::username_visual_studio = "azureuser@kodokanserver";
KodokanDAO::password = "Kodokan123";
KodokanDAO::database_name = "kodokan_database";*/

void UserDAO::add_subscription(int subscription_type)
{
    try {
        auto* prepared_statement = connection->prepareStatement(
                "INSERT INTO subscriptions(users_id, subscription_types_id) values (?, ?)"
        );
        prepared_statement->setInt(1, id);
        prepared_statement->setInt(2, subscription_type);
        prepared_statement->executeUpdate();
        delete prepared_statement;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

bool UserDAO::is_subscription_active()
{

}

KodokanDAO* KodokanDAO::instance = nullptr;

KodokanDAO* KodokanDAO::getInstance() {
    if (instance == nullptr) {
        instance = new KodokanDAO();
        return instance;
    }
    else
        return instance;
}

KodokanDAO::KodokanDAO()
    {
        try {
            driver = get_driver_instance();
            connection = driver->connect(
                    this->server_name,
                    this->username_visual_studio,  // change to username when running on raspberry
                    this->password
            );
            connection->setSchema(database_name);  // select database
        }
        catch (sql::SQLException& e) {
            std::cout << "# ERR: SQLException in " << __FILE__;
            std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
            std::cout << "# ERR: " << e.what();
            std::cout << " (MySQL error code: " << e.getErrorCode();
            std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
        }
    }

UserDAO* KodokanDAO::authorize_user(std::string login, std::string password)
{
    std::string hashed_pswd = password; // complicated hashing function
    try {
        auto* prepared_statement = connection->prepareStatement(
                "SELECT * FROM users WHERE login LIKE ?"
        );
        prepared_statement->setString(1, login);
        auto result = prepared_statement->executeQuery();
        if (result->next()) {
            if (result->getString("hashed_pswd") == hashed_pswd) {
                auto napis = result->getString(2);
                return new UserDAO(
                        connection,
                        result->getInt("id"),
                        result->getString("login"),
                        result->getString("email"),
                        result->getString("creation_date"),
                        result->getString("name"),
                        result->getString("surname"),
                        result->getString("hashed_pswd")
                );
            }
        }
        prepared_statement->close();
        delete prepared_statement;
        return nullptr;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
        return nullptr;
    }
}

bool KodokanDAO::add_user(std::string login, std::string email, std::string name, std::string surname, std::string password, BLOB photo)
{
    // check if login already exists in database, if yes return error
    // check if mail already exists in database, if yes return error
    // hashes password
    std::string hashed_password = password; // complicated hashing function
    try {
        qDebug() << "Debug: ";
        qDebug() << "Debug: " << this;
        qDebug() << "Debug: " << this->connection;
        auto* prepared_statement = connection->prepareStatement(
                "INSERT INTO users(login, email, hashed_pswd, name, surname) values (?, ?, ?, ?, ?)"
        );
        prepared_statement->setString(1, login);
        prepared_statement->setString(2, email);
        prepared_statement->setString(3, hashed_password);
        prepared_statement->setString(4, name);
        prepared_statement->setString(5, surname);
        prepared_statement->executeUpdate();
        prepared_statement->close();
        delete prepared_statement;
    }
    catch(const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(...) {
        std::cout << "zjebaˆo si©" << std::endl;
    }
}

void KodokanDAO::list_users()
{
    try {
        auto* statement = connection->createStatement();
        auto* results = statement->executeQuery("SELECT * FROM users");
        while (results->next()) {
            std::cout << results->getString(1) << " " << results->getString(2) << " " << results->getString(3) << std::endl;
        }
        delete statement;
        delete results;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

KodokanDAO::~KodokanDAO()
{
    delete connection;
}


/*int main()
{
    KodokanDAO first;
    first.add_user("pampam", "pampam2@gmail.com", "pam", "pam", "abcdef");
    first.list_users(); // prints users
    UserDAO* user = first.authorize_user("pampam", "abcdef");

    if (user) {
        user->add_subscription(3);
        std::cout << *user << std::endl;
    }

    return 0;
}*/
