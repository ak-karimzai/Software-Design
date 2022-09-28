#include "subjectconstroller.h"


SubjectController::SubjectController(SubjectRepository *subjectRepository)
{
    this->subjectRepository = subjectRepository;
}

SubjectController::~SubjectController()
{

}

void SubjectController::addNewSubject(const std::string &subjectName, const int marks, const int studentId)
{
    this->subjectRepository->addNewSubject(subjectName, marks, studentId);
}

std::vector<Subject> SubjectController::getAllSubjectByStudentId(const int studentId)
{
    return this->subjectRepository->getSubjectByStudent(studentId);
}

void SubjectController::changeSubjectMarks(int subjectId, const int newSubjectMarks)
{
    this->subjectRepository->changeSubjectMarks(subjectId, newSubjectMarks);
}

void SubjectController::changeSubjectName(int subjectId, const std::string &newName)
{
    this->subjectRepository->changeSubjectName(subjectId, newName);
}

void SubjectController::deleteSubject(int subjectId)
{
    this->subjectRepository->deleteSubject(subjectId);
}

Subject SubjectController::getSubject(const std::string &subjectName)
{
    return this->subjectRepository->getSubject(subjectName);
}
