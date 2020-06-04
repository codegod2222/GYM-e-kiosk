#ifndef LOGGEDUSER_H
#define LOGGEDUSER_H
#include "QString"


class LoggedUser
{
public:
    LoggedUser(QString,QString,QString,QString);

    QString getFirstName();

    QString getLastName();

    QString getEmail();

    void setFirstName(QString);

    void setLastName(QString);

    void setEmail(QString);

    void setPassword(QString);

private:
    QString firstName;
    QString lastName;
    QString email;
    QString password;


};

#endif // LOGGEDUSER_H
