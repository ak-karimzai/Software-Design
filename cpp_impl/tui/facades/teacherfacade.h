#ifndef TEACHERMANAGER_H
#define TEACHERMANAGER_H

#include "../../controllers/teachercontroller.h"
#include "../../controllers/groupcontroller.h"
#include "../../controllers/subjectconstroller.h"
#include "../../controllers/studentcontroller.h"

#include <memory>
#include <vector>

class TeacherFacade
{
public:
    TeacherFacade(TeacherController *teacherController, GroupController *groupController, SubjectController *subjectConstroller, StudentController *studentController);

    void addNewTeacher(const std::string & teacherName,
                       const std::string & teacherRegestrationNumber);

    Teacher getTeacher(const std::string & teacherRegestrationNumber);

    void addNewStudent(const std::string & studentName,
                       const std::string & studentAdmission,
                       const int studentGroupId);
    void removeStudent(const int studentId);
    void createNewGroup(const std::string & groupName,
                        const int teacherId);
    void removeGroup(const int groupId);
    void addNewSubject(const std::string & subjectName,
                       const int marks,
                       const int studentId);
    void deleteSubject(const int subjectId);
    void deleteTeacher(const int teacherId);
    std::vector<Student> getGroupStudentsSortedByAverageMarks(const int groupId);
    std::vector<Subject> getStudentSubjects(const int studentId);
    std::vector<Teacher> getTeachers();
    Teacher getTeacher(const int teacherId);
    std::vector<Student> getGroupStudents(const int groupId);
    std::vector<Group> getTeacherGroups(const int teacherId);

private:
    double averageStudentSubjectsMarks(const std::vector<Subject> subjects);

private:
    TeacherController * teacherController;
    GroupController * groupController;
    SubjectController * subjectConstroller;
    StudentController * studentController;
};

#endif // TEACHERMANAGER_H
