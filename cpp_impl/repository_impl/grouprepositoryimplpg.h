#ifndef GROUPREPOSITORYIMPLPG_H
#define GROUPREPOSITORYIMPLPG_H

#include "../repositories/grouprepository.h"

#include <memory>
#include <pqxx/pqxx>
#include <string>

class GroupRepositoryImplPg : public GroupRepository
{
public:

    GroupRepositoryImplPg(const std::string &connectionParams);
    ~GroupRepositoryImplPg();
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
    std::string connectionParams;
    std::shared_ptr<pqxx::connection> connection;
};

#endif // GROUPREPOSITORYIMPLPG_H
