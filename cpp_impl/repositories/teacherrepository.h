#ifndef TEACHERREPOSITORY_H
#define TEACHERREPOSITORY_H

#include "../entity/teacher.h"

#include <vector>

class TeacherRepository
{
public:
    TeacherRepository() {}
    virtual void addNewTeacher(const Teacher newTeacher);
    virtual void addNewTeacher(const std::string teacherFullName,
                               const std::string teacherRegestrationNumber);
    virtual void addNewTeacher(const int id, const std::string teacherFullName,
                               const std::string teacherRegestrationNumber);
    virtual void deleteTeacher(const int id);
    virtual void renameTeacher(int id, std::string newName);
    virtual void changeTeacherRegestrationNumber(int id, std::string newRegestrationNumber);
    virtual std::vector<Teacher> getAllTeachers();
};

#endif // TEACHERREPOSITORY_H
