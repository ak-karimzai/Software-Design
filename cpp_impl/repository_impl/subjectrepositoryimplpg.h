#ifndef SUBJECTREPOSITORYIMPLPG_H
#define SUBJECTREPOSITORYIMPLPG_H

#include "../repositories/subjectrepository.h"

class SubjectRepositoryImplPg : public SubjectRepository
{    
    // SubjectRepository interface
public:
    void addNewSubject(const Subject &newSubject);
    void addNewSubject(const std::string subjectName, const int marks, const int studentId);
    void addNewSubject(const int id, const std::string subjectName, const int marks, const int studentId);
    void changeSubjectName(const int id, std::string newSubjectName);
    void changeSubjectMarks(const int id, const int newMarks);
    void changeSubjectStudentId(const int id, const int studentId);
    std::vector<Subject> getAllSubject();
    std::vector<Subject> getSubjectByStudent(int studentId);
};

#endif // SUBJECTREPOSITORYIMPLPG_H
