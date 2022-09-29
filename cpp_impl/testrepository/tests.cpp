#include <gtest/gtest.h>

#include "../testrepository/teststudentrepository.h"
#include "../controllers/studentcontroller.h"

#include "../testrepository/testteacherrepository.h"
#include "../controllers/teachercontroller.h"

#include "../testrepository/testgrouprepository.h"
#include "../controllers/groupcontroller.h"

#include "../testrepository/testsubjectrepository.h"
#include "../controllers/subjectconstroller.h"

#include "../testrepository/testauthrepository.h"
#include "../controllers/authcontroller.h"

TEST(TestStudentController, TestAdd)
{
    std::vector<Student> students = {
        Student(1, "Abc", "a123", 1),
        Student(2, "Abcd", "b423", 1),
        Student(3, "Abcde", "c523", 1)
    };

    TestStudentRepository testRepository(students);
    StudentController studentController(&testRepository);

    studentController.addStudent("Ahmad Khalid", "19iu10", 1);

    Student lastAddedStudent = studentController.getStudentById(4);

    ASSERT_EQ(lastAddedStudent.getId(), 4);
    ASSERT_EQ(lastAddedStudent.fullName(), "Ahmad Khalid");
    ASSERT_EQ(lastAddedStudent.admissionNumber(), "19iu10");
    ASSERT_EQ(lastAddedStudent.groupId(), 1);

    Student sndStudent = studentController.getStudentById(2);

    ASSERT_EQ(sndStudent.getId(), 2);
    ASSERT_EQ(sndStudent.fullName(), "Abcd");
    ASSERT_EQ(sndStudent.admissionNumber(), "b423");
    ASSERT_EQ(sndStudent.groupId(), 1);
}


TEST(TestStudentController, TestRemove)
{
    std::vector<Student> students = {
        Student(1, "Abc", "a123", 1),
        Student(2, "Abcd", "b423", 1),
        Student(3, "Abcde", "c523", 1)
    };

    TestStudentRepository testRepository(students);
    StudentController studentController(&testRepository);

    studentController.deleteStudent(3);

    Student lastAddedStudent = studentController.getStudentById(3);
    ASSERT_NE(lastAddedStudent.getId(), 3);
}

TEST(TestStudentController, TestGetGroup)
{
    std::vector<Student> students = {
        Student(1, "Abc", "a123", 1),
        Student(2, "Abcd", "b423", 2),
        Student(3, "Abcde", "c523", 10)
    };

    TestStudentRepository testRepository(students);
    StudentController studentController(&testRepository);

    int studentGroupId = studentController.getStudentGroup(3);

    ASSERT_EQ(studentGroupId, 10);
}

TEST(TestTeacherController, TestAddTeacher)
{
    std::vector<Teacher> teachers = {
        Teacher(1, "AAA", "123"),
        Teacher(2, "BBB", "345"),
        Teacher(3, "CCC", "433")
    };

    TestTeacherRepository teacherRepository(teachers);
    TeacherController teacherController(&teacherRepository);

    teacherController.addNewTeacher("DDD", "945");

    teachers = teacherController.getAllTeachers();
    auto lastAddedTeacher = teachers[teachers.size() - 1];

    ASSERT_EQ(lastAddedTeacher.getFullName(), "DDD");
    ASSERT_EQ(lastAddedTeacher.getRegisterNumber(), "945");
}

TEST(TestTeacherController, TestRemoveTeacher)
{
    std::vector<Teacher> teachers = {
        Teacher(1, "AAA", "123"),
        Teacher(2, "BBB", "345"),
        Teacher(3, "CCC", "433")
    };

    TestTeacherRepository teacherRepository(teachers);
    TeacherController teacherController(&teacherRepository);

    teacherController.deleteTeacher(3);

    teachers = teacherController.getAllTeachers();
    auto lastAddedTeacher = teachers[teachers.size() - 1];

    ASSERT_NE(lastAddedTeacher.getFullName(), "CCC");
    ASSERT_NE(lastAddedTeacher.getRegisterNumber(), "433");
}

TEST(TestTeacherController, TestChangeName)
{
    std::vector<Teacher> teachers = {
        Teacher(1, "AAA", "123"),
        Teacher(2, "BBB", "345"),
        Teacher(3, "CCC", "433")
    };

    TestTeacherRepository teacherRepository(teachers);
    TeacherController teacherController(&teacherRepository);

    teacherController.changeTeacherName(3, "Ahmad Khalid");

    teachers = teacherController.getAllTeachers();
    auto lastAddedTeacher = teachers[teachers.size() - 1];

    ASSERT_EQ(lastAddedTeacher.getFullName(), "Ahmad Khalid");
    ASSERT_EQ(lastAddedTeacher.getRegisterNumber(), "433");
}

TEST(TestGroupController, TestAddGroup) {
    std::vector<Group> groups = {
        Group(1, "AAA", 22),
        Group(2, "BBB", 23),
        Group(3, "CCC", 19)
    };

    TestGroupRepository groupRepository(groups);
    GroupController groupController(&groupRepository);

    groupController.addGroup("DDD", 54);

    groups = groupController.getAllGroups();
    auto group = groups[groups.size() - 1];

    ASSERT_EQ(group.getName(), "DDD");
    ASSERT_EQ(group.getTeacherId(), 54);
}

TEST(TestGroupController, TestRemoveGroup) {
    std::vector<Group> groups = {
        Group(1, "AAA", 22),
        Group(2, "BBB", 23),
        Group(3, "CCC", 19)
    };

    TestGroupRepository groupRepository(groups);
    GroupController groupController(&groupRepository);

    groupController.deleteGroup(3);

    groups = groupController.getAllGroups();
    auto group = groups[groups.size() - 1];

    ASSERT_NE(group.getName(), "CCC");
    ASSERT_NE(group.getTeacherId(), 19);
}

TEST(TestGroupController, TestRenameGroupName) {
    std::vector<Group> groups = {
        Group(1, "AAA", 22),
        Group(2, "BBB", 23),
        Group(3, "CCC", 19)
    };

    TestGroupRepository groupRepository(groups);
    GroupController groupController(&groupRepository);

    groupController.changeGroupName(3, "A1222");

    groups = groupController.getAllGroups();
    auto group = groups[groups.size() - 1];

    ASSERT_EQ(group.getName(), "A1222");
    ASSERT_EQ(group.getTeacherId(), 19);
}

TEST(TestSubjectController, TestAddSubject) {
    std::vector<Subject> subjects = {
        Subject(1, "AAA", 34, 1),
        Subject(2, "BBB", 36, 3),
        Subject(3, "CCC", 40, 9)
    };

    TestSubjectRepository subjectRepository(subjects);
    SubjectController subjectController(&subjectRepository);

    subjectController.addNewSubject("Math", 100, 3);

    subjects = subjectController.getAllSubjectByStudentId(3);

    ASSERT_NE(subjects.size(), 0);

    auto subject = subjects[subjects.size() - 1];

    ASSERT_EQ(subject.getSubjectName(), "Math");
    ASSERT_EQ(subject.getMarks(), 100);
    ASSERT_EQ(subject.getStudentId(), 3);
}


TEST(TestSubjectController, TestGetAllSubjects) {
    std::vector<Subject> subjects = {
        Subject(1, "AAA", 34, 1),
        Subject(2, "BBB", 36, 3),
        Subject(3, "CCC", 40, 9)
    };

    TestSubjectRepository subjectRepository(subjects);
    SubjectController subjectController(&subjectRepository);

    subjectController.addNewSubject("Math", 100, 3);

    subjects = subjectController.getAllSubjectByStudentId(3);
    auto subject = subjects[subjects.size() - 1];

    ASSERT_EQ(subject.getSubjectName(), "Math");
    ASSERT_EQ(subject.getMarks(), 100);
    ASSERT_EQ(subject.getStudentId(), 3);
}


TEST(TestAuthController, TestAddNewUser) {
    std::vector<Auth> auths = {
        Auth(1, "login", "password", 1),
        Auth(2, "newpass", "passnew", 2),
        Auth(3, "logpass", "passpass", 3)
    };

    TestAuthRepository authRepository(auths);
    AuthController authController(&authRepository);

    authController.addNewUser("khalid", "khalid", 4);

    auto auth = authController.getUserDetails(4);

    ASSERT_EQ(auth.getLogin(), "khalid");
    ASSERT_EQ(auth.getPassword(), "khalid");
    ASSERT_EQ(auth.getTeacherId(), 4);
}

TEST(TestAuthController, TestChangeUserPass) {
    std::vector<Auth> auths = {
        Auth(1, "login", "password", 1),
        Auth(2, "newpass", "passnew", 2),
        Auth(3, "logpass", "passpass", 3)
    };

    TestAuthRepository authRepository(auths);
    AuthController authController(&authRepository);

    authController.addNewUser("khalid", "khalid", 4);

    authController.changeUserPassword(4, "newPass");

    auto auth = authController.getUserDetails(4);

    ASSERT_EQ(auth.getLogin(), "khalid");
    ASSERT_EQ(auth.getPassword(), "newPass");
    ASSERT_EQ(auth.getTeacherId(), 4);
}

TEST(TestAuthController, TestChangeUserLogin) {
    std::vector<Auth> auths = {
        Auth(1, "login", "password", 1),
        Auth(2, "newpass", "passnew", 2),
        Auth(3, "logpass", "passpass", 3)
    };

    TestAuthRepository authRepository(auths);
    AuthController authController(&authRepository);

    authController.addNewUser("khalid", "khalid", 4);

    authController.changeUserLogin(4, "Ahmad Khalid");

    auto auth = authController.getUserDetails(4);

    ASSERT_EQ(auth.getLogin(), "Ahmad Khalid");
    ASSERT_EQ(auth.getPassword(), "khalid");
    ASSERT_EQ(auth.getTeacherId(), 4);
}
