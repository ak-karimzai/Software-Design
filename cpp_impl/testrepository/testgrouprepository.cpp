#include "testgrouprepository.h"

#include <iostream>

TestGroupRepository::~TestGroupRepository()
{

}

void TestGroupRepository::addNewGroup(const std::string groupName, const int teacherId)
{
    int index = this->groups.size();
    this->groups.push_back(Group(index, groupName, teacherId));
}

void TestGroupRepository::changeGroupName(const int id, const std::string newGroupName)
{
    for (auto & group : this->groups) {
        if (group.getId() == id) {
            group.setName(newGroupName);
            break;
        }
    }
}

void TestGroupRepository::deleteGroup(const int id)
{
    int index = -1;
    for (int i = 0; i < (int) this->groups.size(); i++) {
        if (groups[i].getId() == id) {
            index = i;
        }
    }
    if (index != -1) {
        groups.erase(groups.begin() + index);
    }
}

std::vector<Group> TestGroupRepository::getAllGroups()
{
    return groups;
}

TestGroupRepository::TestGroupRepository(const std::vector<Group> &groups) : groups(groups)
{}
