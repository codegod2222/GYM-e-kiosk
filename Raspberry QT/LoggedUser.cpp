#include "LoggedUser.h"

LoggedUser::LoggedUser(QString firstName, QString lastName, QString email, QString password)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->password = password;
}

QString LoggedUser::getFirstName()
{
    return this->firstName;
}

QString LoggedUser::getLastName()
{
    return this->lastName;
}

QString LoggedUser::getEmail()
{
    return this->email;
}

void LoggedUser::setEmail(QString email)
{
    this->email = email;
}

void LoggedUser::setFirstName(QString firstName)
{
    this->firstName = firstName;
}

void LoggedUser::setLastName(QString lastName)
{
    this->lastName = lastName;
}
