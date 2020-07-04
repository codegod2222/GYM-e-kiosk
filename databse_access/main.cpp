//
// Created by piotr on 20/07/01.
//

#include "KodokanDAO.h"
#include "UserDAO.h"

// compiling on raspberry with line:
// g++ -Wall -I/usr/include/cppconn -o test main.cpp KodokanDAO.cpp UserDAO.cpp -L/usr/lib -lmysqlcppconn

int main()
{
    auto* first = KodokanDAO::getInstance();
    first->add_user("pampam", "pampam2@gmail.com", "pam", "pam", "abcdef");
    first->list_users();
    UserDAO* user = first->authorize_user("pampam", "abcdef");
    std::cout << first->get_receipt_number() << std::endl;
    std::cout << first->get_receipt_number() << std::endl;
    std::cout << first->get_receipt_number() << std::endl;
    if (user) {
        user->add_subscription(3);
        std::cout << user->name << std::endl;
    }

    delete user;
    delete first;
    return 0;
}
