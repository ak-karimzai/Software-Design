#ifndef STUDENTREPOSITORY_H
#define STUDENTREPOSITORY_H

#include "../entity/student.h"

#include <vector>

class StudentRepository
{
public:
    StudentRepository() {}
    virtual void addStudent(const Student &newStudent);
    virtual void addStudent(const std::string studentName,
                            const std::string admissionNumber,
                            const int groupId);
    virtual void addStudent(const int id,
                            const std::string studentName,
                            const std::string admissionNumber,
                            const int groupId);
    virtual void removeStudent(const int id);
    virtual void changeStudentName(const int id, const std::string newName);
    virtual Student getStudent(const int id);
    virtual int getStudentGroup(const int id);
    virtual void changeStudentGroup(const int id, const int groupId);
    virtual std::vector<Student> getAllStudents();
    virtual std::vector<Student> getAllGroupStudents(int groupId);
};

#endif // STUDENTREPOSITORY_H
