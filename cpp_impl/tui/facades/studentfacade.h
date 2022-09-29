#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "../../controllers/groupcontroller.h"
#include "../../controllers/studentcontroller.h"
#include "../../controllers/subjectconstroller.h"

#include <memory>

class StudentFacade
{
public:
    StudentFacade(StudentController *studentController,
                   GroupController *groupController,
                   SubjectController *subjectController);

    std::vector<Group> getAllGroupsList();
    std::vector<Subject> getStudentSubjects(const int studentId);
    std::vector<Student> getGroupStudents(const int groupId);
    std::vector<Student> getGroupStudentsSortedByAverageMarks(const int groupId);

private:
    double averageStudentSubjectsMarks(const std::vector<Subject> subjects);

private:
    StudentController * studentController;
    GroupController * groupController;
    SubjectController * subjectController;
};

#endif // STUDENTMANAGER_H
