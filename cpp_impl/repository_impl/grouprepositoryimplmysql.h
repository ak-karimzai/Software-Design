#ifndef GROUPREPOSITORYIMPLMYSQL_H
#define GROUPREPOSITORYIMPLMYSQL_H

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "../repositories/grouprepository.h"

class GroupRepositoryImplMySql : public GroupRepository
{
public:
    GroupRepositoryImplMySql(const std::string &hostUrl, const std::string &user, const std::string &password);



    ~GroupRepositoryImplMySql();
    void addNewGroup(const std::string groupName, const int teacherId);
    void changeGroupName(const int id, const std::string newGroupName);
    void changeGroupTeacherId(const int id, const int newTeacherId);
    void deleteGroup(const int groupId);
    Group getGroup(const std::string &groupName);
    std::vector<Group> getAllGroups();
    std::vector<Group> getTeacherGroups(int teacherId);

private:
    int getNumberOfRows();

private:
    std::string hostUrl;
    std::string user;
    std::string password;

private:
    sql::Driver * driver;
    sql::Connection * con;
};

#endif // GROUPREPOSITORYIMPLMYSQL_H
