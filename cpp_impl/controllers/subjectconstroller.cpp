#include "subjectconstroller.h"


SubjectConstroller::SubjectConstroller(SubjectRepository *subjectRepository)
{
    this->subjectRepository = subjectRepository;
}

SubjectConstroller::~SubjectConstroller()
{

}

void SubjectConstroller::addNewSubject(const std::string &subjectName, const int marks, const int studentId)
{
    this->subjectRepository->addNewSubject(subjectName, marks, studentId);
}

std::vector<Subject> SubjectConstroller::getAllSubjectByStudentId(const int studentId)
{
    return this->subjectRepository->getSubjectByStudent(studentId);
}

void SubjectConstroller::changeSubjectMarks(int subjectId, const int newSubjectMarks)
{
    this->subjectRepository->changeSubjectMarks(subjectId, newSubjectMarks);
}

void SubjectConstroller::changeSubjectName(int subjectId, const std::string &newName)
{
    this->subjectRepository->changeSubjectName(subjectId, newName);
}

void SubjectConstroller::deleteSubject(int subjectId)
{
    this->subjectRepository->deleteSubject(subjectId);
}
