#ifndef GROUPREPOSITORY_H
#define GROUPREPOSITORY_H

#include "../entity/group.h"

#include <vector>
#include <pqxx/pqxx>

class GroupRepository
{
public:
    virtual void addNewGroup(const Group &newGroup);
    virtual void addNewGroup(const int id,
                             const std::string groupName,
                             const int teacherId);
    virtual void addNewGroup(const std::string groupName,
                             const int teacherId);
    virtual void changeGroupName(const int id, const std::string newGroupName);
    virtual void changeGroupTeacherId(const int id, const int newTeacherId);
    virtual void deleteGroup(const int id);
    virtual Group getGroup(const std::string & groupName);
    virtual std::vector<Group> getAllGroups();
    virtual std::vector<Group> getTeacherGroups(int teacherId);
};

#endif // GROUPREPOSITORY_H
