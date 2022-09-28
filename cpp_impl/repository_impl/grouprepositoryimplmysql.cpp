#include "grouprepositoryimplmysql.h"

#include <iostream>

#include "../exceptions/exception.h"
#include "querygenerators.h"

using std::cout;
using std::endl;

GroupRepositoryImplMySql::~GroupRepositoryImplMySql()
{
    con->close();
    delete con;
}

void GroupRepositoryImplMySql::addNewGroup(const std::string groupName, const int teacherId)
{
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        int numberOfRows = getNumberOfRows();
        std::string query = GroupQueryGenerator::getNewGroupQuery(numberOfRows + 1,
                                                                  groupName,
                                                                  teacherId);
        sql::ResultSet *res = stm->executeQuery(query);
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void GroupRepositoryImplMySql::changeGroupName(const int id, const std::string newGroupName)
{
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = GroupQueryGenerator::groupNameChangeQuery(id, newGroupName);
        sql::ResultSet *res = stm->executeQuery(query);
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void GroupRepositoryImplMySql::changeGroupTeacherId(const int id, const int newTeacherId)
{
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = GroupQueryGenerator::getGroupTeacherChangeQuery(id, newTeacherId);
        sql::ResultSet *res = stm->executeQuery(query);
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void GroupRepositoryImplMySql::deleteGroup(const int groupId)
{
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = GroupQueryGenerator::deleteGroupQuery(groupId);
        sql::ResultSet *res = stm->executeQuery(query);
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

Group GroupRepositoryImplMySql::getGroup(const std::string &groupName)
{
    Group group;
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = GroupQueryGenerator::getGroupQuery(groupName);
        sql::ResultSet *res = stm->executeQuery(query);

        if (res->next())
            group = Group(res->getInt(1),
                          res->getString(2),
                          res->getInt(3));

        delete res;
        delete stm;

    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return group;
}

std::vector<Group> GroupRepositoryImplMySql::getAllGroups()
{
    std::vector<Group> groups;
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        sql::Statement *stm = con->createStatement();
        std::string query = GroupQueryGenerator::getAllGroupsQuery();
        sql::ResultSet *res = stm->executeQuery(query);

        while (res->next()) {
            groups.push_back(
                        Group(res->getInt(1),
                              res->getString(2),
                              res->getInt(3))
            );
        }

        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return groups;
}

std::vector<Group> GroupRepositoryImplMySql::getTeacherGroups(int teacherId)
{
    std::vector<Group> groups;
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        sql::Statement *stm = con->createStatement();
        std::string query = GroupQueryGenerator::getAllGroupsQuery(teacherId);
        sql::ResultSet *res = stm->executeQuery(query);

        while (res->next()) {
            groups.push_back(
                        Group(res->getInt(1),
                              res->getString(2),
                              res->getInt(3))
            );
        }

        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return groups;
}

int GroupRepositoryImplMySql::getNumberOfRows()
{
    int numberOfRows = 0;
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        sql::Statement *stm = con->createStatement();
        std::string query = GroupQueryGenerator::getNumberOfRowsQuery();
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

GroupRepositoryImplMySql::GroupRepositoryImplMySql(const std::string &hostUrl, const std::string &user, const std::string &password) : hostUrl(hostUrl),
    user(user),
    password(password)
{
    driver = get_driver_instance();
    con = driver->connect(hostUrl, user, password);

    if (!con->isValid()) {
        throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
}
