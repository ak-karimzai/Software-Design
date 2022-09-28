#include "auth.h"

Auth::Auth()
{

}

Auth::~Auth()
{

}

Auth::Auth(int id, const std::string &login, const std::string &password, int teacher_id) : id(id),
    login(login),
    password(password),
    teacherId(teacher_id)
{}

int Auth::getId() const
{
    return id;
}

void Auth::setId(int newId)
{
    id = newId;
}

const std::string &Auth::getLogin() const
{
    return login;
}

void Auth::setLogin(const std::string &newLogin)
{
    login = newLogin;
}

const std::string &Auth::getPassword() const
{
    return password;
}

void Auth::setPassword(const std::string &newPassword)
{
    password = newPassword;
}

int Auth::getTeacherId() const
{
    return teacherId;
}

void Auth::setTeacherId(int newTeacherId)
{
    teacherId = newTeacherId;
}

std::ostream& operator<<(std::ostream& os, const Auth& auth)
{
    os << "id: "<< auth.getId() << '\n' <<
          "login: " << auth.getLogin() << '\n' <<
          "password: " << auth.getPassword() << '\n' <<
          "teacher id: " << auth.getTeacherId();
    return os;
}
