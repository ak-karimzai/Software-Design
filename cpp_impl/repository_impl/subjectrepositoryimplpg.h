#ifndef SUBJECTREPOSITORYIMPLPG_H
#define SUBJECTREPOSITORYIMPLPG_H

#include "../repositories/subjectrepository.h"

#include <memory>
#include <pqxx/pqxx>

class SubjectRepositoryImplPg : public SubjectRepository
{    
    // SubjectRepository interface
public:
    SubjectRepositoryImplPg(const std::string &connectionParams);

    ~SubjectRepositoryImplPg();
    void addNewSubject(const std::string subjectName, const int marks, const int studentId);
    void changeSubjectName(const int id, std::string newSubjectName);
    void changeSubjectMarks(const int id, const int newMarks);
    void changeSubjectStudentId(const int id, const int studentId);
    void deleteSubject(const int id);
    Subject getSubject(const std::string & subjectName);
    std::vector<Subject> getAllSubject();
    std::vector<Subject> getSubjectByStudent(int studentId);
private:
    std::string connectionParams;
    std::shared_ptr<pqxx::connection> connection;
};

#endif // SUBJECTREPOSITORYIMPLPG_H
