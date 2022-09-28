#include "grouprepositoryimplpg.h"

#include <iostream>

#include "../exceptions/exception.h"
#include "querygenerators.h"

using std::cout;
using std::endl;

GroupRepositoryImplPg::GroupRepositoryImplPg(const std::string &connectionParams) : connectionParams(connectionParams)
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

GroupRepositoryImplPg::~GroupRepositoryImplPg()
{

}

void GroupRepositoryImplPg::addNewGroup(const std::string groupName, const int teacherId)
{
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        int numberOfRows = getNumberOfRows();
        std::string query = GroupQueryGenerator::getNewGroupQuery(numberOfRows + 1,
                                                                  groupName,
                                                                  teacherId);
        pqxx::work work(*connection);
        work.exec(query);
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void GroupRepositoryImplPg::changeGroupName(const int id, const std::string newGroupName)
{
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = GroupQueryGenerator::groupNameChangeQuery(id, newGroupName);
        pqxx::work work(*connection);
        work.exec(query);
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void GroupRepositoryImplPg::changeGroupTeacherId(const int id, const int newTeacherId)
{
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = GroupQueryGenerator::getGroupTeacherChangeQuery(id, newTeacherId);
        pqxx::work work(*connection);
        work.exec(query);
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void GroupRepositoryImplPg::deleteGroup(const int groupId)
{
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = GroupQueryGenerator::deleteGroupQuery(groupId);
        pqxx::work work(*connection);
        work.exec(query);
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

Group GroupRepositoryImplPg::getGroup(const std::string &groupName)
{
    Group group;
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = GroupQueryGenerator::getGroupQuery(groupName);
        pqxx::work work(*connection);
        pqxx::result result = work.exec(query);

        group = Group(result[0][0].as<int>(),
              result[0][1].as<std::string>(),
              result[0][2].as<int>());

        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return group;
}

std::vector<Group> GroupRepositoryImplPg::getAllGroups()
{
    std::vector<Group> groups;
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = GroupQueryGenerator::getAllGroupsQuery();
        pqxx::work work(*connection);
        pqxx::result results = work.exec(query);

        for (const auto & result : results) {
            groups.push_back(
                        Group(result[0].as<int>(),
                              result[1].as<std::string>(),
                              result[2].as<int>())
            );
        }

        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return groups;
}

std::vector<Group> GroupRepositoryImplPg::getTeacherGroups(int teacherId)
{
    std::vector<Group> groups;
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = GroupQueryGenerator::getAllGroupsQuery(teacherId);
        pqxx::work work(*connection);
        pqxx::result results = work.exec(query);

        for (const auto & result : results) {
            groups.push_back(
                        Group(result[0].as<int>(),
                              result[1].as<std::string>(),
                              result[2].as<int>())
            );
        }

        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return groups;
}

int GroupRepositoryImplPg::getNumberOfRows()
{
    int numberOfRows = 0;
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = GroupQueryGenerator::getNumberOfRowsQuery();
        pqxx::work work(*connection);
        pqxx::result result = work.exec(query);
        numberOfRows = result[0][0].as<int>();
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return numberOfRows;
}
