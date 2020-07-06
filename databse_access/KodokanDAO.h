//
// Created by piotr on 20/07/01.
//

#ifndef RASPBERRY_SQL_KODOKANDAO_H
#define RASPBERRY_SQL_KODOKANDAO_H

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "UserDAO.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

struct SubscriptionType{
    int id;
    std::string name;
    int length;
    int price;
};

class KodokanDAO {
private:
    // connection string
    const char* server_name = "kodokanserver.mysql.database.azure.com";
    const char* username = "azureuser";
    const char* username_visual_studio = "azureuser@kodokanserver";
    const char* password = "Kodokan123";
    const char* database_name = "kodokan_database";

    // sql driver
    sql::Driver* driver;

    // sql connection
    sql::Connection* connection;

    // private c-tor and static instance (singleton)
    KodokanDAO();
    static KodokanDAO* instance;

    // restarts counting if needed, private
    void update_receipt_number(int new_number);

public:
    // public getInstance is the only way to instantiate KodokanDAO
    static KodokanDAO* getInstance();

    // get user object using login and password or just rfid
    UserDAO* authorize_user(std::string login, std::string password);
    UserDAO* authorize_user(std::string rfid);

    // add new user (only obligatory fields)
    void add_user(std::string login, std::string email, std::string name, std::string surname, std::string password);

    // get possible subscription types
    std::vector<SubscriptionType> get_subscription_types();

    // get actual receipt number (counting restarts at midnight)
    int get_receipt_number();

    // print users (debug purposes)
    void list_users();

    std::vector<UserDAO> get_users();

    // get kodokan info
    std::vector<std::string> get_kodokan_info();

    // update kodokan info (if empty "" then the field stays unchanged)
    void update_kodokan_info(std::string nazwa_firmy, std::string adres, std::string nip);
    void update_nazwa_firmy(std::string nazwa_firmy);
    void update_adres(std::string adres);
    void update_nip(std::string nip);

    // subscription types
    void add_subscription_type(SubscriptionType new_type);
    void delete_subscription_type(int id);
    void edit_subscription_type_name(int id, std::string new_name);
    void edit_subscription_type_length(int id, int new_length);
    void edit_subscription_type_price(int id, int new_price);

    ~KodokanDAO();
};

#endif //RASPBERRY_SQL_KODOKANDAO_H
