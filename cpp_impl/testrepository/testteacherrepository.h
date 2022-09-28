#ifndef TESTTEACHERREPOSITORY_H
#define TESTTEACHERREPOSITORY_H

#include "../repositories/teacherrepository.h"

#include <vector>

class TestTeacherRepository : public TeacherRepository
{
public:
    TestTeacherRepository(const std::vector<Teacher> &teachers);
    ~TestTeacherRepository();

    void addNewTeacher(const std::string teacherFullName,
                       const std::string teacherRegestrationNumber);
    void deleteTeacher(const int id);
    void renameTeacher(int id, std::string newName);
    std::vector<Teacher> getAllTeachers();
private:
    std::vector<Teacher> teachers;
};

#endif // TESTTEACHERREPOSITORY_H

