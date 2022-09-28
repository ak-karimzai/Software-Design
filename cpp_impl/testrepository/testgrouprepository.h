#ifndef TESTGROUPREPOSITORY_H
#define TESTGROUPREPOSITORY_H

#include "../repositories/grouprepository.h"

#include <vector>

class TestGroupRepository : public GroupRepository
{
public:
    TestGroupRepository(const std::vector<Group> &groups);

    ~TestGroupRepository();

    void addNewGroup(const std::string groupName, const int teacherId);
    void changeGroupName(const int id, const std::string newGroupName);
    void deleteGroup(const int id);
    std::vector<Group> getAllGroups();
private:
    std::vector<Group> groups;
};

#endif // TESTGROUPREPOSITORY_H
