#include "authrepositoryimplpg.h"

#include "../exceptions/exception.h"
#include "querygenerators.h"

#include <iostream>

using std::cout;
using std::endl;

AuthRepositoryImplPg::AuthRepositoryImplPg(const std::string &connectionParams) : connectionParams(connectionParams)
{
    try {
        connection = std::shared_ptr<pqxx::connection>(
                        new pqxx::connection(this->connectionParams.c_str())
                    );
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

AuthRepositoryImplPg::~AuthRepositoryImplPg()
{

}

void AuthRepositoryImplPg::addNewUser(const std::string &login, const std::string &password, const int teacherId)
{
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        pqxx::work work(*connection);
        int numberOfRow = getNumberOfRows();
        std::string query = AuthQueryGenerator::getNewUserQuery(numberOfRow + 1,
                                                                login,
                                                                password,
                                                                teacherId);
        work.exec(query);
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void AuthRepositoryImplPg::changeUserPassword(const int teacherId, const std::string &newPassword)
{
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = AuthQueryGenerator::changeUserPasswordQuery(teacherId,
                                                                   newPassword
        );
        pqxx::work work(*connection);
        work.exec(query);
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void AuthRepositoryImplPg::changeUserLogin(const int teacherId, const std::string &newLogin)
{
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = AuthQueryGenerator::changeUserLoginQuery(teacherId,
                                                                   newLogin
        );
        pqxx::work work(*connection);
        work.exec(query);
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

Auth AuthRepositoryImplPg::getUserDetails(const int teacherId)
{
    Auth auth;
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = AuthQueryGenerator::getLoginDetailsQuery(teacherId);
        pqxx::work work(*connection);
        pqxx::result result = work.exec(query);

        auth = Auth(
                result[0][0].as<int>(),
                result[0][1].as<std::string>(),
                result[0][2].as<std::string>(),
                result[0][3].as<int>()
        );
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return auth;
}

void AuthRepositoryImplPg::deleteUserDetails(const int authId)
{
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = AuthQueryGenerator::getDeleteDetailsQuery(authId);
        pqxx::work work(*connection);
        pqxx::result result = work.exec(query);
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void AuthRepositoryImplPg::deleteUserDetailsByTeacherId(const int teacherId)
{
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = AuthQueryGenerator::getDeleteDetailsByTIdQuery(teacherId);
        pqxx::work work(*connection);
        pqxx::result result = work.exec(query);
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

std::vector<Auth> AuthRepositoryImplPg::getUsers()
{
    std::vector<Auth> auths;
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = AuthQueryGenerator::getUsersQuery();
        pqxx::work work(*connection);
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
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return auths;
}

int AuthRepositoryImplPg::getNumberOfRows()
{
    int numberOfRows = 0;
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = AuthQueryGenerator::getNumberOfRowsQuery();
        pqxx::work work(*connection);
        pqxx::result result = work.exec(query);
        numberOfRows = result[0][0].as<int>();
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return numberOfRows;
}

