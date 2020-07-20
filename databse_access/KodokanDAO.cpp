//
// Created by piotr on 20/07/01.
//

#include "KodokanDAO.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

KodokanDAO* KodokanDAO::instance = nullptr;

KodokanDAO* KodokanDAO::getInstance() {
    if (instance == nullptr) {
        instance = new KodokanDAO();
    }
    return instance;
}

std::vector<SubscriptionType> KodokanDAO::get_subscription_types()
{
    try {
        std::vector<SubscriptionType> subscriptions;
        auto* statement = connection->createStatement();
        auto result = statement->executeQuery("SELECT * FROM subscription_types");
        while (result->next())
        {
            subscriptions.push_back(SubscriptionType
            {
                    result->getInt("id"),
                    result->getString("name"),
                    result->getInt("length"),
                    result->getInt("price")
            });
        }
        return subscriptions;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
        return std::vector<SubscriptionType>();
    }
}

void KodokanDAO::add_subscription_type(SubscriptionType new_type)
{
    try {
        auto* prepared_statement = connection->prepareStatement(
                "INSERT INTO subscription_types(name, length, price) values (?, ?, ?)"
        );
        prepared_statement->setString(1, new_type.name);
        prepared_statement->setString(2, std::to_string(new_type.length));
        prepared_statement->setString(3, std::to_string(new_type.price));
        prepared_statement->executeUpdate();
        delete prepared_statement;
    }
    catch(const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void KodokanDAO::delete_subscription_type(int id)
{
    try {
        auto* prepared_statement = connection->prepareStatement(
                "DELETE FROM subscription_types WHERE id = ?"
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

void KodokanDAO::edit_subscription_type_name(int id, std::string new_name)
{
    try {
        auto* prepared_statement = connection->prepareStatement(
                "UPDATE subscription_types SET name = ? WHERE id = ?"
        );
        prepared_statement->setString(1, new_name);
        prepared_statement->setInt(2, id);
        prepared_statement->executeUpdate();
        delete prepared_statement;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void KodokanDAO::edit_subscription_type_length(int id, int new_length)
{
    try {
        auto* prepared_statement = connection->prepareStatement(
                "UPDATE subscription_types SET length = ? WHERE id = ?"
        );
        prepared_statement->setInt(1, new_length);
        prepared_statement->setInt(2, id);
        prepared_statement->executeUpdate();
        delete prepared_statement;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void KodokanDAO::edit_subscription_type_price(int id, int new_price)
{
    try {
        auto* prepared_statement = connection->prepareStatement(
                "UPDATE subscription_types SET price = ? WHERE id = ?"
        );
        prepared_statement->setInt(1, new_price);
        prepared_statement->setInt(2, id);
        prepared_statement->executeUpdate();
        delete prepared_statement;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }
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

UserDAO* KodokanDAO::authorize_user(std::string email, std::string password)
{
    std::string hashed_pswd = password; // complicated hashing function
    try {
        auto* prepared_statement = connection->prepareStatement(
                "SELECT * FROM users WHERE email LIKE ? AND hashed_pswd LIKE ?"
        );
        prepared_statement->setString(1, email);
        prepared_statement->setString(2, hashed_pswd);
        auto result = prepared_statement->executeQuery();
        if (result->next()) {
            return new UserDAO(
                    connection,
                    result->getInt("id"),
                    result->getString("login"),
                    result->getString("email"),
                    result->getString("creation_date"),
                    result->getString("name"),
                    result->getString("surname"),
                    result->getString("hashed_pswd"),
                    result->getString("rfid")
            );
        }
        return nullptr;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
        return nullptr;
    }
}

UserDAO* KodokanDAO::authorize_user(std::string rfid)
{
    try {
        auto* prepared_statement = connection->prepareStatement(
                "SELECT * FROM users WHERE rfid LIKE ?"
        );
        prepared_statement->setString(1, rfid);
        auto result = prepared_statement->executeQuery();
        if (result->next()) {
            return new UserDAO(
                connection,
                result->getInt("id"),
                result->getString("login"),
                result->getString("email"),
                result->getString("creation_date"),
                result->getString("name"),
                result->getString("surname"),
                result->getString("hashed_pswd"),
                result->getString("rfid")
            );
        }
        return nullptr;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
        return nullptr;
    }
}

void KodokanDAO::add_user(std::string login, std::string email, std::string name, std::string surname, std::string password)
{
    std::string hashed_password = password; // complicated hashing function
    try {
        auto* prepared_statement = connection->prepareStatement(
            "INSERT INTO users(login, email, hashed_pswd, name, surname) values (?, ?, ?, ?, ?)"
        );
        prepared_statement->setString(1, login);
        prepared_statement->setString(2, email);
        prepared_statement->setString(3, hashed_password);
        prepared_statement->setString(4, name);
        prepared_statement->setString(5, surname);
        prepared_statement->executeUpdate();
        delete prepared_statement;
    }
    catch(const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

/*std::vector<std::string> KodokanDAO::get_subscription_types()
{
    try {
        auto* statement = connection->createStatement();
        auto result = statement->executeQuery("SELECT name FROM subscription_types");
        std::vector<std::string> subscription_names;
        while (result->next()) {
            subscription_names.emplace_back(result->getString("name"));
        }
        return subscription_names;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
        return std::vector<std::string>();
    }
}*/

std::string get_todays_date()
{
    return "2020-07-01";
}

std::vector<UserDAO> KodokanDAO::get_users()
{
    try {
        std::vector<UserDAO> users;
        auto* statement = connection->createStatement();
        auto result = statement->executeQuery("SELECT * FROM users");
        while (result->next())
        {
            users.push_back(UserDAO(
                    connection,
                    result->getInt("id"),
                    result->getString("login"),
                    result->getString("email"),
                    result->getString("creation_date"),
                    result->getString("name"),
                    result->getString("surname"),
                    result->getString("hashed_pswd"),
                    result->getString("rfid")));
        }
        return users;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
        return std::vector<UserDAO>();
    }
}


void KodokanDAO::update_receipt_number(int new_number)
{
    try {
        auto* prepared_statement = connection->prepareStatement(
            "UPDATE ostatni_paragon SET ostatni_nr_par = ?, data_ostatniego_par = ?"
        );
        prepared_statement->setInt(1, new_number);
        prepared_statement->setString(2, get_todays_date());
        prepared_statement->executeUpdate();
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

int KodokanDAO::get_receipt_number()
{
    try {
        auto* statement = connection->createStatement();
        auto result = statement->executeQuery("SELECT * from ostatni_paragon");
        if (result->next()) {
            std::string data_par = result->getString("data_ostatniego_par");
            if(data_par == get_todays_date())
            {
                int nowy_numer_par = result->getInt("ostatni_nr_par") + 1;
                update_receipt_number(nowy_numer_par);
                return nowy_numer_par;
            }
            else update_receipt_number(0);
        }
        return 1;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
        return 0;
    }
}

std::vector<std::string> KodokanDAO::get_kodokan_info()
{
    try {
        auto* statement = connection->createStatement();
        auto result = statement->executeQuery("SELECT * from kodokan_info");
        std::vector<std::string> kodokan_info;
        while (result->next()) {
            kodokan_info.emplace_back(result->getString("nazwa_firmy"));
            kodokan_info.emplace_back(result->getString("adres"));
            kodokan_info.emplace_back(result->getString("nip"));
        }
        return kodokan_info;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
        return std::vector<std::string>();
    }
}

void KodokanDAO::update_kodokan_info(std::string nazwa_firmy, std::string adres, std::string nip)
{
    if(!nazwa_firmy.empty()){
        update_nazwa_firmy(nazwa_firmy);
    }
    if(!adres.empty()){
        update_adres(adres);
    }
    if(!nip.empty()){
        update_nip(nip);
    }
}

void KodokanDAO::update_nazwa_firmy(std::string nazwa_firmy)
{
    try {
        auto* prepared_statement = connection->prepareStatement(
                "UPDATE kodokan_info SET nazwa_firmy = ?"
        );
        prepared_statement->setString(1, nazwa_firmy);
        prepared_statement->executeUpdate();
        delete prepared_statement;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void KodokanDAO::update_adres(std::string adres)
{
    try {
        auto* prepared_statement = connection->prepareStatement(
                "UPDATE kodokan_info SET adres = ?"
        );
        prepared_statement->setString(1, adres);
        prepared_statement->executeUpdate();
        delete prepared_statement;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void KodokanDAO::update_nip(std::string nip)
{
    try {
        auto* prepared_statement = connection->prepareStatement(
                "UPDATE kodokan_info SET nip = ?"
        );
        prepared_statement->setString(1, nip);
        prepared_statement->executeUpdate();
        delete prepared_statement;
    }
    catch (const sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
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
