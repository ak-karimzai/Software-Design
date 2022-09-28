#include "teacherfacade.h"

void TeacherFacade::addNewStudent(const std::string &studentName, const std::string &studentAdmission, const int studentGroupId)
{
    studentController->addStudent(studentName, studentAdmission, studentGroupId);
}

void TeacherFacade::removeStudent(const int studentId)
{
    studentController->deleteStudent(studentId);
}

void TeacherFacade::createNewGroup(const std::string &groupName, const int teacherId)
{
    groupController->addGroup(groupName, teacherId);
}

void TeacherFacade::removeGroup(const int groupId)
{
    groupController->deleteGroup(groupId);
}

void TeacherFacade::addNewSubject(const std::string &subjectName, const int marks, const int studentId)
{
    subjectConstroller->addNewSubject(subjectName, marks, studentId);
}

void TeacherFacade::deleteSubject(const int subjectId)
{
    subjectConstroller->deleteSubject(subjectId);
}

void TeacherFacade::deleteTeacher(const int teacherId)
{
    teacherController->deleteTeacher(teacherId);
}

std::vector<Student> TeacherFacade::getGroupStudentsSortedByAverageMarks(const int groupId)
{
    auto students = studentController->getAllStudentsByGroupId(groupId);
    std::sort(students.begin(), students.end(), [this](Student & lhs, Student & rhs) {
       return averageStudentSubjectsMarks(subjectConstroller->getAllSubjectByStudentId(lhs.getId())) >
               averageStudentSubjectsMarks(subjectConstroller->getAllSubjectByStudentId(rhs.getId()));
    });
    return students;
}

std::vector<Subject> TeacherFacade::getStudentSubjects(const int studentId)
{
    auto subjects = subjectConstroller->getAllSubjectByStudentId(studentId);
    return subjects;
}

std::vector<Teacher> TeacherFacade::getTeachers()
{
    return teacherController->getAllTeachers();
}

Teacher TeacherFacade::getTeacher(const int teacherId)
{
    return teacherController->getTeacherById(teacherId);
}

std::vector<Student> TeacherFacade::getGroupStudents(const int groupId)
{
    return studentController->getAllStudentsByGroupId(groupId);
}

std::vector<Group> TeacherFacade::getTeacherGroups(const int teacherId)
{
    return groupController->getAllGroupsByTeacherId(teacherId);
}

double TeacherFacade::averageStudentSubjectsMarks(const std::vector<Subject> subjects)
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

TeacherFacade::TeacherFacade(TeacherController *teacherController, GroupController *groupController, SubjectController *subjectConstroller, StudentController *studentController) : teacherController(teacherController),
    groupController(groupController),
    subjectConstroller(subjectConstroller),
    studentController(studentController)
{}

void TeacherFacade::addNewTeacher(const std::string &teacherName, const std::string &teacherRegestrationNumber)
{
    teacherController->addNewTeacher(teacherName, teacherRegestrationNumber);
}

Teacher TeacherFacade::getTeacher(const std::string &teacherRegestrationNumber)
{
    return teacherController->getTeacherByRegNumber(teacherRegestrationNumber);
}
