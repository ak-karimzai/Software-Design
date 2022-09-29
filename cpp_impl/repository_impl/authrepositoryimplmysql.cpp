#include "authrepositoryimplmysql.h"

#include "../exceptions/exception.h"
#include "querygenerators.h"

#include <iostream>

using std::cout;
using std::endl;

AuthRepositoryImplMySql::AuthRepositoryImplMySql(const std::string &hostUrl, const std::string &user, const std::string &password) : hostUrl(hostUrl),
    user(user),
    password(password)
{
    driver = get_driver_instance();
    con = driver->connect(hostUrl, user, password);

    if (!con->isValid()) {
        throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

AuthRepositoryImplMySql::~AuthRepositoryImplMySql()
{
    con->close();
    delete con;
}

void AuthRepositoryImplMySql::addNewUser(const std::string &login, const std::string &password, const int teacherId)
{
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        int numberOfRow = getNumberOfRows();
        std::string query = AuthQueryGenerator::getNewUserQuery(numberOfRow + 1,
                                                                login,
                                                                password,
                                                                teacherId);
        sql::ResultSet *res = stm->executeQuery(query);

        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void AuthRepositoryImplMySql::changeUserPassword(const int teacherId, const std::string &newPassword)
{
    try {

        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = AuthQueryGenerator::changeUserPasswordQuery(teacherId,
                                                                   newPassword
        );
        sql::ResultSet *res = stm->executeQuery(query);

        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void AuthRepositoryImplMySql::changeUserLogin(const int teacherId, const std::string &newLogin)
{
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = AuthQueryGenerator::changeUserLoginQuery(teacherId,
                                                                   newLogin
        );

        sql::ResultSet *res = stm->executeQuery(query);

        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

Auth AuthRepositoryImplMySql::getUserDetails(const int teacherId)
{
    Auth auth;
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = AuthQueryGenerator::getLoginDetailsQuery(teacherId);

        sql::ResultSet *res = stm->executeQuery(query);

        if (res->next())
            auth = Auth(
                    res->getInt(1),
                    res->getString(2),
                    res->getString(3),
                    res->getInt(4)
            );

        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return auth;
}

void AuthRepositoryImplMySql::deleteUserDetails(const int authId)
{
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = AuthQueryGenerator::getDeleteDetailsQuery(authId);
        sql::ResultSet *res = stm->executeQuery(query);

        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void AuthRepositoryImplMySql::deleteUserDetailsByTeacherId(const int teacherId)
{
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        sql::Statement *stm = con->createStatement();
        std::string query = AuthQueryGenerator::getDeleteDetailsByTIdQuery(teacherId);
        sql::ResultSet *res = stm->executeQuery(query);

        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

std::vector<Auth> AuthRepositoryImplMySql::getUsers()
{
    std::vector<Auth> auths;
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        sql::Statement *stm = con->createStatement();
        std::string query = AuthQueryGenerator::getUsersQuery();
        sql::ResultSet *res = stm->executeQuery(query);
        while (res->next()) {
            auths.push_back(
                        Auth(
                            res->getInt(1),
                            res->getString(2),
                            res->getString(3),
                            res->getInt(4)
                            )
                        );
        }
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return auths;
}

int AuthRepositoryImplMySql::getNumberOfRows()
{
    int numberOfRows = 0;
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        sql::Statement *stm = con->createStatement();
        std::string query = AuthQueryGenerator::getNumberOfRowsQuery();
        sql::ResultSet *res = stm->executeQuery(query);

        if (res->next())
            numberOfRows = res->getInt(1);

        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return numberOfRows;
}
