#ifndef TEACHERREPOSITORYIMPLPG_H
#define TEACHERREPOSITORYIMPLPG_H

#include "teacherrepository.h"

class TeacherRepositoryImplPG : public TeacherRepository
{
    // TeacherRepository interface
public:
    void addNewTeacher(const Teacher newTeacher);
    void addNewTeacher(const std::string teacherFullName, const std::string teacherRegestrationNumber);
    void addNewTeacher(const int id, const std::string teacherFullName, const std::string teacherRegestrationNumber);
    void deleteTeacher(const int id);
    void renameTeacher(int id, std::string newName);
    void changeTeacherRegestrationNumber(int id, std::string newRegestrationNumber);
    std::vector<Teacher> getAllTeachers();
};

#endif // TEACHERREPOSITORYIMPLPG_H
