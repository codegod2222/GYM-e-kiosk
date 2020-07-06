//
// Created by piotr on 20/07/01.
//

#include "UserDAO.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

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

void UserDAO::update_user(std::string username,
                          std::string email,
                          std::string name,
                          std::string surname)
{
    if(!username.empty()){
        update_user_username(username);
    }
    if(!email.empty()){
        update_user_email(email);
    }
    if(!name.empty()){
        update_user_name(name);
    }
    if(!surname.empty()){
        update_user_surname(surname);
    }
}

void UserDAO::update_user_hashed_pswd(std::string new_password)
{
    try {
        auto* prepared_statement = connection->prepareStatement(
                "UPDATE users SET hashed_pswd = ? WHERE id = ?"
        );
        prepared_statement->setString(1, new_password);
        prepared_statement->setInt(2, id);
        prepared_statement->executeUpdate();
        this->username = username;
        delete prepared_statement;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void UserDAO::update_user_username(std::string username)
{
    try {
        auto* prepared_statement = connection->prepareStatement(
                "UPDATE users SET username = ? WHERE id = ?"
        );
        prepared_statement->setString(1, username);
        prepared_statement->setInt(2, id);
        prepared_statement->executeUpdate();
        this->username = username;
        delete prepared_statement;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void UserDAO::update_user_email(std::string email)
{
    try {
        auto* prepared_statement = connection->prepareStatement(
                "UPDATE users SET email = ? WHERE id = ?"
        );
        prepared_statement->setString(1, email);
        prepared_statement->setInt(2, id);
        prepared_statement->executeUpdate();
        this->email = email;
        delete prepared_statement;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void UserDAO::update_user_name(std::string name)
{
    try {
        auto* prepared_statement = connection->prepareStatement(
                "UPDATE users SET name = ? WHERE id = ?"
        );
        prepared_statement->setString(1, name);
        prepared_statement->setInt(2, id);
        prepared_statement->executeUpdate();
        this->name = name;
        delete prepared_statement;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void UserDAO::update_user_surname(std::string surname)
{
    try {
        auto* prepared_statement = connection->prepareStatement(
                "UPDATE users SET surname = ? WHERE id = ?"
        );
        prepared_statement->setString(1, surname);
        prepared_statement->setInt(2, id);
        prepared_statement->executeUpdate();
        this->surname = surname;
        delete prepared_statement;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

// storing only photos in databse, photos should be kept in the device's memory
void UserDAO::add_update_photo_path(std::string photo_path)
{
    try {
        auto* prepared_statement = connection->prepareStatement(
                "UPDATE users SET photo_path = ? WHERE id = ?"
        );
        prepared_statement->setString(1, photo_path);
        prepared_statement->setInt(2, id);
        prepared_statement->executeUpdate();
        this->photo_path = photo_path;
        delete prepared_statement;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

// add rfid
void UserDAO::add_update_rfid(std::string rfid)
{
    try {
        auto* prepared_statement = connection->prepareStatement(
                "UPDATE users SET rfid = ? WHERE id = ?"
        );
        prepared_statement->setString(1, rfid);
        prepared_statement->setInt(2, id);
        prepared_statement->executeUpdate();
        this->rfid = rfid;
        delete prepared_statement;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

// deletes the user from database
void UserDAO::delete_user()
{
    try {
        auto* prepared_statement = connection->prepareStatement(
                "DELETE FROM users WHERE id = ?"
        );
        prepared_statement->setInt(1, id);
        prepared_statement->executeUpdate();
        delete prepared_statement;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }
}
