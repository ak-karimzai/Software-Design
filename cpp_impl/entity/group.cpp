#include "group.h"

Group::Group()
{

}

Group::Group(int id, const std::string &name, int teacherId) : id(id),
    name(name),
    teacherId(teacherId)
{}

int Group::getId() const
{
    return id;
}

void Group::setId(int newId)
{
    id = newId;
}

const std::string &Group::getName() const
{
    return name;
}

void Group::setName(const std::string &newName)
{
    name = newName;
}

int Group::getTeacherId() const
{
    return teacherId;
}

void Group::setTeacherId(int newTeacherId)
{
    teacherId = newTeacherId;
}

std::ostream& operator<<(std::ostream& os, const Group& group)
{
    os << "id: " << group.getId() << '\n' <<
          "name: " << group.getName() << '\n' <<
          "teacher id: " << group.getTeacherId();
    return os;
}

