#ifndef GROUPCONTROLLER_H
#define GROUPCONTROLLER_H

#include "../repositories/grouprepository.h"

#include <string>
#include <vector>

class GroupController
{
public:
    GroupController(GroupRepository *groupRepository);

    ~GroupController();

    void addGroup(const std::string name, const int teacherID);
    Group getGroup(const std::string & groupName);
    std::vector<Group> getAllGroups();
    std::vector<Group> getAllGroupsByTeacherId(const int id);
    void changeGroupName(const int id, std::string newGroupName);
    void changeGroupTeacherId(const int id, const int teacherId);
    void deleteGroup(const int id);
private:
    GroupRepository * groupRepository;
};

#endif // GROUPCONTROLLER_H
