#include "student.h"

int Student::getId() const
{
    return _id;
}

void Student::setId(int newId)
{
    _id = newId;
}

const std::string &Student::fullName() const
{
    return _fullName;
}

void Student::setFullName(const std::string &newFullName)
{
    _fullName = newFullName;
}

const std::string &Student::admissionNumber() const
{
    return _admissionNumber;
}

void Student::setAdmissionNumber(const std::string &newAdmissionNumber)
{
    _admissionNumber = newAdmissionNumber;
}

int Student::groupId() const
{
    return _groupId;
}

void Student::setGroupId(int newGroupId)
{
    _groupId = newGroupId;
}

std::ostream& operator<<(std::ostream& os, const Student& student)
{
    os << "id: " << student.getId() << '\n' <<
          "name: " << student.fullName() << '\n' <<
          "admission number: " << student.admissionNumber() << '\n' <<
          "group id: " << student.groupId();
    return os;
}

Student::~Student() {

}

Student::Student(int id, const std::string &fullName, const std::string &admissionNumber, int groupId) : _id(id),
    _fullName(fullName),
    _admissionNumber(admissionNumber),
    _groupId(groupId)
{}

Student::Student() {

}
