#include "teacher.h"


int Teacher::getId() const
{
    return id;
}

void Teacher::setId(int newId)
{
    id = newId;
}

const std::string &Teacher::getFullName() const
{
    return fullName;
}

void Teacher::setFullName(const std::string &newFullName)
{
    fullName = newFullName;
}

const std::string &Teacher::getRegisterNumber() const
{
    return registerNumber;
}

void Teacher::setRegisterNumber(const std::string &newRegisterNumber)
{
    registerNumber = newRegisterNumber;
}

Teacher::Teacher(int id, const std::string &fullName, const std::string &registerNumber) : id(id),
    fullName(fullName),
    registerNumber(registerNumber)
{}


Teacher::Teacher() {

}

Teacher::~Teacher() {

}
