#ifndef TEACHERREPOSITORYIMPLPG_H
#define TEACHERREPOSITORYIMPLPG_H

#include "../repositories/teacherrepository.h"

#include <memory>
#include <pqxx/pqxx>

class TeacherRepositoryImplPg : public TeacherRepository
{
    // TeacherRepository interface
public:
    TeacherRepositoryImplPg(const std::string &connectionParams);
    ~TeacherRepositoryImplPg();

    Teacher getTeacher(const std::string &teacherName);
    void addNewTeacher(const std::string teacherFullName, const std::string teacherRegestrationNumber);
    void deleteTeacher(const int id);
    void renameTeacher(int id, std::string newName);
    void changeTeacherRegestrationNumber(int id, std::string newRegestrationNumber);
    std::vector<Teacher> getAllTeachers();
private:
    std::string connectionParams;
    std::shared_ptr<pqxx::connection> connection;
};

#endif // TEACHERREPOSITORYIMPLPG_H
