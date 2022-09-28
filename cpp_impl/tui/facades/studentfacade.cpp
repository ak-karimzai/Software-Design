#include "studentfacade.h"

std::vector<Group> StudentFacade::getAllGroupsList()
{
    return groupController->getAllGroups();
}

std::vector<Subject> StudentFacade::getStudentSubjects(const int studentId)
{
    return subjectController->getAllSubjectByStudentId(studentId);
}

std::vector<Student> StudentFacade::getGroupStudents(const int groupId)
{
    return studentController->getAllStudentsByGroupId(groupId);
}

std::vector<Student> StudentFacade::getGroupStudentsSortedByAverageMarks(const int groupId)
{
    auto students = studentController->getAllStudentsByGroupId(groupId);
    std::sort(students.begin(), students.end(), [this](Student & lhs, Student & rhs) {
       return averageStudentSubjectsMarks(subjectController->getAllSubjectByStudentId(lhs.getId())) >
               averageStudentSubjectsMarks(subjectController->getAllSubjectByStudentId(rhs.getId()));
    });
    return students;
}

double StudentFacade::averageStudentSubjectsMarks(const std::vector<Subject> subjects)
{
    double average = 0.0;

    for (const auto & subject : subjects) {
        average += subject.getMarks();
    }

    if (subjects.size()) {
        average =  average / subjects.size();
    }
    return average;
}

StudentFacade::StudentFacade(StudentController *studentController, GroupController *groupController, SubjectController *subjectController) : studentController(studentController),
    groupController(groupController),
    subjectController(subjectController)
{}
