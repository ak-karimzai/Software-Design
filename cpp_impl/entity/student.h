#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
public:
    Student();
    Student(int id, const std::string &fullName, const std::string &admissionNumber, int groupId);
    ~Student();

    int getId() const;
    void setId(int newId);

    const std::string &fullName() const;
    void setFullName(const std::string &newFullName);

    const std::string &admissionNumber() const;
    void setAdmissionNumber(const std::string &newAdmissionNumber);

    int groupId() const;
    void setGroupId(int newGroupId);

private:
    int _id;
    std::string _fullName;
    std::string _admissionNumber;
    int _groupId;
};

#endif // STUDENT_H
