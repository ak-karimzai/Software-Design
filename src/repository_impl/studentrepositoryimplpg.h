#ifndef STUDENTREPOSITORYIMPLPG_H
#define STUDENTREPOSITORYIMPLPG_H

#include "../repositories/studentrepository.h"
#include "../logger/logger.h"

#include <pqxx/pqxx>

class StudentRepositoryImplPg : public StudentRepository
{
    // StudentRepository interface
public:
    StudentRepositoryImplPg(const std::string &connectionParams);

    ~StudentRepositoryImplPg();
    void addStudent(const std::string studentName, const std::string admissionNumber, const int groupId);
    void removeStudent(const int id);
    void changeStudentName(int id, const std::string newName);
    Student getStudent(const int id);
    Student getStudent(const std::string & studentName);

    std::vector<Student> getAllStudents();
    std::vector<Student> getGroupAllStudents(int groupId);

private:
    int getNumberOfRows();

private:
    std::string connectionParams;
    std::shared_ptr<pqxx::connection> connection;
    Logger * logger;
};

#endif // STUDENTREPOSITORYIMPLPG_H
