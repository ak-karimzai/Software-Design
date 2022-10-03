#include "authrepositoryimplpg.h"

#include "../exceptions/exception.h"
#include "querygenerators.h"

#include <iostream>

using std::cout;
using std::endl;

AuthRepositoryImplPg::AuthRepositoryImplPg(const std::string &connectionParams) : connectionParams(connectionParams)
{
    try {
        logger = Logger::getInstance();
        connection = std::shared_ptr<pqxx::connection>(
                        new pqxx::connection(this->connectionParams.c_str())
                    );
        if (!connection->is_open()) {
            logger->logWarning("connection error with database with this connection params: " + connectionParams);
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

AuthRepositoryImplPg::~AuthRepositoryImplPg()
{

}

void AuthRepositoryImplPg::addNewUser(const std::string &login, const std::string &password, const int teacherId)
{
    try {
        pqxx::connection conn(this->connectionParams.c_str());
        if (!conn.is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        pqxx::work work(conn);
        int numberOfRow = getNumberOfRows();
        std::cout << numberOfRow << std::endl;
        std::string query = AuthQueryGenerator::getNewUserQuery(numberOfRow + 1,
                                                                login,
                                                                password,
                                                                teacherId);
        work.exec(query);
        std::cout << "called" << std::endl;
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataUpdateException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

void AuthRepositoryImplPg::changeUserPassword(const int teacherId, const std::string &newPassword)
{
    try {
        pqxx::connection conn(this->connectionParams.c_str());
        if (!conn.is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = AuthQueryGenerator::changeUserPasswordQuery(teacherId,
                                                                   newPassword
        );
        pqxx::work work(conn);
        work.exec(query);
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataUpdateException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

void AuthRepositoryImplPg::changeUserLogin(const int teacherId, const std::string &newLogin)
{
    try {
        pqxx::connection conn(this->connectionParams.c_str());
        if (!conn.is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = AuthQueryGenerator::changeUserLoginQuery(teacherId,
                                                                   newLogin
        );
        pqxx::work work(conn);
        work.exec(query);
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataUpdateException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

Auth AuthRepositoryImplPg::getUserDetails(const int teacherId)
{
    Auth auth;
    try {
        pqxx::connection conn(this->connectionParams.c_str());
        if (!conn.is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = AuthQueryGenerator::getLoginDetailsQuery(teacherId);
        pqxx::work work(conn);
        pqxx::result result = work.exec(query);

        auth = Auth(
                result[0][0].as<int>(),
                result[0][1].as<std::string>(),
                result[0][2].as<std::string>(),
                result[0][3].as<int>()
        );
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
    return auth;
}

void AuthRepositoryImplPg::deleteUserDetails(const int authId)
{
    try {
        pqxx::connection conn(this->connectionParams.c_str());
        if (!conn.is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = AuthQueryGenerator::getDeleteDetailsQuery(authId);
        pqxx::work work(conn);
        pqxx::result result = work.exec(query);
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataDeleteException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

void AuthRepositoryImplPg::deleteUserDetailsByTeacherId(const int teacherId)
{
    try {
        pqxx::connection conn(this->connectionParams.c_str());
        if (!conn.is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = AuthQueryGenerator::getDeleteDetailsByTIdQuery(teacherId);
        pqxx::work work(conn);
        pqxx::result result = work.exec(query);
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataDeleteException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

std::vector<Auth> AuthRepositoryImplPg::getUsers()
{
    std::vector<Auth> auths;
    try {
        pqxx::connection conn(this->connectionParams.c_str());
        if (!conn.is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = AuthQueryGenerator::getUsersQuery();
        pqxx::work work(conn);
        pqxx::result results = work.exec(query);

        for (const auto & result : results) {
            auths.push_back(
                 Auth(
                    result[0].as<int>(),
                    result[1].as<std::string>(),
                    result[2].as<std::string>(),
                    result[3].as<int>()
                    )
             );
        }
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
    return auths;
}

int AuthRepositoryImplPg::getNumberOfRows()
{
    int numberOfRows = 0;
    try {
        pqxx::connection conn(this->connectionParams.c_str());
        if (!conn.is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = AuthQueryGenerator::getNumberOfRowsQuery();
        pqxx::work work(conn);
        pqxx::result result = work.exec(query);
        numberOfRows = result[0][0].as<int>();
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
    return numberOfRows;
}

