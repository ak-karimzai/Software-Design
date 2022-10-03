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
    logger = Logger::getInstance();
    driver = get_driver_instance();
    con = driver->connect(hostUrl, user, password);

    if (!con->isValid()) {
        logger->logWarning("connection error with database with " + hostUrl + " " + user + " " + password);
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
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        int numberOfRow = getNumberOfRows();
        std::string query = AuthQueryGenerator::getNewUserQuery(numberOfRow + 1,
                                                                login,
                                                                password,
                                                                teacherId);
        auto res = stm->execute(query);
        if (res) {
            logger->logInfo(query + " executed!");
        } else {
            logger->logError("error on exectution of " + query);
        }

        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
}

void AuthRepositoryImplMySql::changeUserPassword(const int teacherId, const std::string &newPassword)
{
    try {

        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = AuthQueryGenerator::changeUserPasswordQuery(teacherId,
                                                                   newPassword
        );
        auto res = stm->execute(query);

        if (res) {
            logger->logInfo(query + " executed!");
        } else {
            logger->logError("error on exectution of " + query);
        }
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
}

void AuthRepositoryImplMySql::changeUserLogin(const int teacherId, const std::string &newLogin)
{
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = AuthQueryGenerator::changeUserLoginQuery(teacherId,
                                                                   newLogin
        );

        auto res = stm->execute(query);

        if (res) {
            logger->logInfo(query + " executed!");
        } else {
            logger->logError("error on exectution of " + query);
        }
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
}

Auth AuthRepositoryImplMySql::getUserDetails(const int teacherId)
{
    Auth auth;
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = AuthQueryGenerator::getLoginDetailsQuery(teacherId);

        sql::ResultSet *res = stm->executeQuery(query);

        if (res->next()) {
            auth = Auth(
                    res->getInt(1),
                    res->getString(2),
                    res->getString(3),
                    res->getInt(4)
            );
        } else {
            logger->logInfo( query + " executed! but table is empty.");
        }

        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
    return auth;
}

void AuthRepositoryImplMySql::deleteUserDetails(const int authId)
{
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = AuthQueryGenerator::getDeleteDetailsQuery(authId);
        auto res = stm->executeQuery(query);


        if (res) {
            logger->logInfo(query + " executed!");
        } else {
            logger->logError("error on exectution of " + query);
        }
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
}

void AuthRepositoryImplMySql::deleteUserDetailsByTeacherId(const int teacherId)
{
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        sql::Statement *stm = con->createStatement();
        std::string query = AuthQueryGenerator::getDeleteDetailsByTIdQuery(teacherId);
        auto res = stm->executeQuery(query);

        if (res) {
            logger->logInfo(query + " executed!");
        } else {
            logger->logError("error on exectution of " + query);
        }
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
}

std::vector<Auth> AuthRepositoryImplMySql::getUsers()
{
    std::vector<Auth> auths;
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
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
        logger->logInfo(query + " executed!");
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
    return auths;
}

int AuthRepositoryImplMySql::getNumberOfRows()
{
    int numberOfRows = 0;
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        sql::Statement * stm = con->createStatement();
        std::string query = AuthQueryGenerator::getNumberOfRowsQuery();
        sql::ResultSet * res = stm->executeQuery(query);

        if (res->next()) {
            numberOfRows = res->getInt(1);
        }
        logger->logInfo(query + " executed!");
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
    return numberOfRows;
}
