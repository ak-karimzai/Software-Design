#include "testauthrepository.h"

TestAuthRepository::TestAuthRepository(const std::vector<Auth> &auths) : auths(auths)
{}

void TestAuthRepository::addNewUser(const std::string &login, const std::string &password, const int teacherId)
{
    int index = auths.size();
    auths.push_back(
                Auth(index + 1, login, password, teacherId)
                );
}

void TestAuthRepository::changeUserPassword(const int teacherId, const std::string &newPassword)
{
    for (auto & auth : auths) {
        if (auth.getTeacherId() == teacherId) {
            auth.setPassword(newPassword);
            break;
        }
    }
}

void TestAuthRepository::changeUserLogin(const int teacherId, const std::string &newLogin)
{
    for (auto & auth : auths) {
        if (auth.getTeacherId() == teacherId) {
            auth.setLogin(newLogin);
            break;
        }
    }
}

Auth TestAuthRepository::getUserDetails(const int teacherId)
{
    for (auto & auth : auths) {
        if (auth.getTeacherId() == teacherId) {
            return auth;
        }
    }
    return Auth();
}

std::vector<Auth> TestAuthRepository::getUsers()
{
    return auths;
}
