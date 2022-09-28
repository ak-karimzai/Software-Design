#ifndef SUBJECTCONSTROLLER_H
#define SUBJECTCONSTROLLER_H

#include "../repositories/subjectrepository.h"

#include <string>
#include <vector>

class SubjectController
{
public:
    SubjectController(SubjectRepository * subjectRepository);
    ~SubjectController();

    void addNewSubject(const std::string & subjectName,
                    const int marks,
                    const int studentId);
    std::vector<Subject> getAllSubjectByStudentId(const int studentId);
    void changeSubjectMarks(int subjectId,
                            const int newSubjectMarks);
    void changeSubjectName(int subjectId,
                           const std::string & newName);
    void deleteSubject(int subjectId);
    Subject getSubject(const std::string & subjectName);
private:
    SubjectRepository *subjectRepository;
};

#endif // SUBJECTCONSTROLLER_H
