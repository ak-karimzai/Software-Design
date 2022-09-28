#ifndef TESTSUBJECTREPOSITORY_H
#define TESTSUBJECTREPOSITORY_H

#include "../repositories/subjectrepository.h"

#include <vector>

class TestSubjectRepository : public SubjectRepository
{
public:
    TestSubjectRepository(const std::vector<Subject> &subjects);

    ~TestSubjectRepository();


    void addNewSubject(const std::string subjectName, const int marks, const int studentId);
    void changeSubjectName(const int id, std::string newSubjectName);
    void deleteSubject(const int id);
    std::vector<Subject> getSubjectByStudent(int studentId);
private:
    std::vector<Subject> subjects;
};

#endif // TESTSUBJECTREPOSITORY_H
