#ifndef AUTHREPOSITORYIMPLMYSQL_H
#define AUTHREPOSITORYIMPLMYSQL_H

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "../repositories/authrepository.h"
#include "../exceptions/exception.h"

#include "../logger/logger.h"

class AuthRepositoryImplMySql : public AuthRepository
{
public:
    AuthRepositoryImplMySql(const std::string &hostUrl, const std::string &user, const std::string &password);

    ~AuthRepositoryImplMySql();
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
    std::string hostUrl;
    std::string user;
    std::string password;

private:
    sql::Driver * driver;
    sql::Connection * con;
    Logger * logger;
};

#endif // AUTHREPOSITORYIMPLMYSQL_H
