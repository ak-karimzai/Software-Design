#ifndef GROUPREPOSITORYIMPLPG_H
#define GROUPREPOSITORYIMPLPG_H

#include "../repositories/grouprepository.h"

class GroupRepositoryImplPg : public GroupRepository
{
    // GroupRepository interface
public:
    void addNewGroup(const Group &newGroup);
    void addNewGroup(const int id, const std::string groupName, const int teacherId);
    void addNewGroup(const std::string groupName, const int teacherId);
    void changeGroupName(const int id, const std::string newGroupName);
    void changeGroupTeacherId(const int id, const int newTeacherId);
    std::vector<Group> getAllGroups();
    std::vector<Group> getTeacherGroups(int teacherId);
};

#endif // GROUPREPOSITORYIMPLPG_H
