#ifndef AUTHREPOSITORYIMPLPG_H
#define AUTHREPOSITORYIMPLPG_H

#include "../repositories/authrepository.h"

#include <pqxx/pqxx>

#include "../logger/logger.h"

class AuthRepositoryImplPg : public AuthRepository
{
public:
    AuthRepositoryImplPg(const std::string &connectionParams);


    ~AuthRepositoryImplPg();
    void addNewUser(const std::string &login, const std::string &password, const int teacherId);
    void changeUserPassword(const int teacherId, const std::string &newPassword);
    void changeUserLogin(const int teacherId, const std::string &newLogin);
    Auth getUserDetails(const int teacherId);
    void deleteUserDetails(const int userId);
    void deleteUserDetailsByTeacherId(const int teacherId);
    std::vector<Auth> getUsers();    
private:
    int getNumberOfRows();

private:
    std::string connectionParams;
    std::shared_ptr<pqxx::connection> connection;
    Logger * logger;
};

#endif // AUTHREPOSITORYIMPLPG_H
