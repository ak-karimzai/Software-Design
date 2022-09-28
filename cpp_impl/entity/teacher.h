#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <ostream>

class Teacher
{
public:
    ~Teacher();
    Teacher();
    Teacher(int id, const std::string &fullName, const std::string &registerNumber);
    int getId() const;
    void setId(int newId);
    const std::string &getFullName() const;
    void setFullName(const std::string &newFullName);
    const std::string &getRegisterNumber() const;
    void setRegisterNumber(const std::string &newRegisterNumber);
    friend std::ostream& operator<<(std::ostream& os, const Teacher& teacher);
private:
    int id;
    std::string fullName;
    std::string registerNumber;
};

#endif // TEACHER_H
