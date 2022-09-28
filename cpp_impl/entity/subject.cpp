#include "subject.h"

Subject::Subject(int id, const std::string &subjectName, int marks, int studentId) : id(id),
    subjectName(subjectName),
    marks(marks),
    studentId(studentId)
{}

Subject::Subject()
{

}

Subject::~Subject()
{

}

int Subject::getId() const
{
    return id;
}

void Subject::setId(int newId)
{
    id = newId;
}

const std::string &Subject::getSubjectName() const
{
    return subjectName;
}

void Subject::setSubjectName(const std::string & newSubjectName)
{
    subjectName = newSubjectName;
}

int Subject::getMarks() const
{
    return marks;
}

void Subject::setMarks(int newMarks)
{
    marks = newMarks;
}

int Subject::getStudentId() const
{
    return studentId;
}

void Subject::setStudentId(int newStudentId)
{
    studentId = newStudentId;
}

std::ostream& operator<<(std::ostream& os, const Subject& subject)
{
    os << "id: " << subject.getId() << '\n' <<
          "name: " << subject.getSubjectName() << '\n' <<
          "marks: " << subject.getMarks() << '\n' <<
          "student id: " << subject.getStudentId();
    return os;
}
