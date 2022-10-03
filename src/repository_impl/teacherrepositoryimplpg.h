#ifndef TEACHERREPOSITORYIMPLPG_H
#define TEACHERREPOSITORYIMPLPG_H

#include "../repositories/teacherrepository.h"
#include "../logger/logger.h"

#include <memory>
#include <pqxx/pqxx>

class TeacherRepositoryImplPg : public TeacherRepository
{
    // TeacherRepository interface
public:
    TeacherRepositoryImplPg(const std::string &connectionParams);
    ~TeacherRepositoryImplPg();

    Teacher getTeacher(const std::string &teacherName);
    Teacher getTeacher(const int teacherId);
    void addNewTeacher(const std::string teacherFullName, const std::string teacherRegestrationNumber);
    void deleteTeacher(const int id);
    void renameTeacher(int id, std::string newName);
    void changeTeacherRegestrationNumber(int id, std::string newRegestrationNumber);
    std::vector<Teacher> getAllTeachers();
    Teacher getTeacherByRegNum(const std::string &teacherRegNum);

private:
    int getNumberOfRows();

private:
    std::string connectionParams;
    std::shared_ptr<pqxx::connection> connection;
    Logger * logger;
};

#endif // TEACHERREPOSITORYIMPLPG_H
