#ifndef TESTAUTHREPOSITORY_H
#define TESTAUTHREPOSITORY_H

#include "../repositories/authrepository.h"

class TestAuthRepository : public AuthRepository
{
public:
    TestAuthRepository(const std::vector<Auth> &auths);

    void addNewUser(const std::string &login, const std::string &password, const int teacherId);
    void changeUserPassword(const int teacherId, const std::string &newPassword);
    void changeUserLogin(const int teacherId, const std::string &newLogin);
    Auth getUserDetails(const int teacherId);
    std::vector<Auth> getUsers();
private:
    std::vector<Auth> auths;
};

#endif // TESTAUTHREPOSITORY_H
