#ifndef SUBJECTREPOSITORY_H
#define SUBJECTREPOSITORY_H

#include "../entity/subject.h"

#include <vector>

class SubjectRepository
{
public:
    SubjectRepository() {}
    virtual void addNewSubject(const Subject &newSubject);
    virtual void addNewSubject(const std::string subjectName,
                               const int marks,
                               const int studentId);
    virtual void addNewSubject(const int id,
                               const std::string subjectName,
                               const int marks,
                               const int studentId);
    virtual void changeSubjectName(const int id, std::string newSubjectName);
    virtual void changeSubjectMarks(const int id, const int newMarks);
    virtual void changeSubjectStudentId(const int id, const int studentId);
    virtual void deleteSubject(const int id);
    virtual std::vector<Subject> getAllSubject();
    virtual std::vector<Subject> getSubjectByStudent(int studentId);
};

#endif // SUBJECTREPOSITORY_H
