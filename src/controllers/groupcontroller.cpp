#include "groupcontroller.h"


GroupController::~GroupController()
{

}

void GroupController::addGroup(const std::string name, const int teacherID)
{
    this->groupRepository->addNewGroup(name, teacherID);
}

Group GroupController::getGroup(const std::string &groupName)
{
    return this->groupRepository->getGroup(groupName);
}

std::vector<Group> GroupController::getAllGroups()
{
    return this->groupRepository->getAllGroups();
}

std::vector<Group> GroupController::getAllGroupsByTeacherId(const int id)
{
    return this->groupRepository->getTeacherGroups(id);
}

void GroupController::changeGroupName(const int id, std::string newGroupName)
{
    this->groupRepository->changeGroupName(id, newGroupName);
}

void GroupController::changeGroupTeacherId(const int id, const int teacherId)
{
    this->groupRepository->changeGroupTeacherId(id, teacherId);
}

void GroupController::deleteGroup(const int id)
{
    this->groupRepository->deleteGroup(id);
}

GroupController::GroupController(GroupRepository *groupRepository) : groupRepository(groupRepository)
{}
