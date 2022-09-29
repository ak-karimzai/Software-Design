#include <gtest/gtest.h>

#include "../repository_impl/studentrepositoryimplpg.h"
#include "../repository_impl/studentrepositoryimplmysql.h"
#include "../controllers/studentcontroller.h"

#include "../repository_impl/teacherrepositoryimplpg.h"
#include "../repository_impl/teacherrepositoryimplmysql.h"
#include "../controllers/teachercontroller.h"

#include "../repository_impl/grouprepositoryimplpg.h"
#include "../repository_impl/grouprepositoryimplmysql.h"
#include "../controllers/groupcontroller.h"

#include "../repository_impl/subjectrepositoryimplpg.h"
#include "../repository_impl/subjectrepositoryimplmysql.h"
#include "../controllers/subjectconstroller.h"

#include "../repository_impl/authrepositoryimplpg.h"
#include "../repository_impl/authrepositoryimplmysql.h"
#include "../controllers/authcontroller.h"

const std::string conn = std::string("dbname = school ") +
                         std::string("user = khalid ") +
                         std::string("password = 1234abcd ") +
                         std::string("hostaddr = 127.0.0.1 ") +
                         std::string("port = 5432");

const std::string url = "tcp://127.0.0.1:3306/result_sheet";
const std::string user = "root";
const std::string password = "";

TEST(PGStudentRepository, TestGetByName)
{
    StudentRepositoryImplPg studetRepository = StudentRepositoryImplPg(conn);
    StudentController studentController(&studetRepository);

    studentController.addStudent("AAAA", "19iu14", 1);
    Student student = studentController.getStudentByName("AAAA");

    ASSERT_EQ(student.fullName(), "AAAA");
    ASSERT_EQ(student.admissionNumber(), "19iu14");
    ASSERT_EQ(student.groupId(), 1);

    studentController.deleteStudent(student.getId());
}


TEST(PGStudentRepository, TestChangeStudentName)
{
    StudentRepositoryImplPg studetRepository = StudentRepositoryImplPg(conn);
    StudentController studentController(&studetRepository);


    studentController.changeStudentName(1, "Test name");

    Student student = studentController.getStudentByName("Test name");

    ASSERT_EQ(student.fullName(), "Test name");
    ASSERT_EQ(student.admissionNumber(), "19iu10");
    ASSERT_EQ(student.groupId(), 1);

}


TEST(PGStudentRepository, TestGroupAllStudents)
{
    StudentRepositoryImplPg studetRepository = StudentRepositoryImplPg(conn);
    StudentController studentController(&studetRepository);


    studentController.changeStudentName(1, "Test name");

    auto students = studentController.getAllStudentsByGroupId(1);

    for (const auto & student : students) {
        ASSERT_EQ(student.groupId(), 1);
    }
}

TEST(PGTeacherRepository, TestAddTeacherAndGetByName)
{
    TeacherRepositoryImplPg teacherRepo = TeacherRepositoryImplPg(conn);
    TeacherController teacherController(&teacherRepo);

    teacherController.addNewTeacher("new teacher", "a12332");

    Teacher teacher = teacherController.getTeacherByName("new teacher");

    ASSERT_EQ(teacher.getFullName(), "new teacher");
    ASSERT_EQ(teacher.getRegisterNumber(), "a12332");

    teacherController.deleteTeacher(teacher.getId());
}

TEST(PGTeacherRepository, TestTeacherRename)
{
    TeacherRepositoryImplPg teacherRepo = TeacherRepositoryImplPg(conn);
    TeacherController teacherController(&teacherRepo);

    teacherController.addNewTeacher("New teacher", "a2323");

    Teacher teacher = teacherController.getTeacherByName("New teacher");

    teacherController.changeTeacherName(teacher.getId(), "new name");

    teacher = teacherController.getTeacherByName("new name");

    ASSERT_EQ(teacher.getFullName(), "new name");
    ASSERT_EQ(teacher.getRegisterNumber(), "a2323");

    teacherController.deleteTeacher(teacher.getId());
}


TEST(PGTeacherRepository, TestChangeTeacherRegestrationNumber)
{
    TeacherRepositoryImplPg teacherRepo = TeacherRepositoryImplPg(conn);
    TeacherController teacherController(&teacherRepo);

    teacherController.addNewTeacher("New teacher", "a2323");

    Teacher teacher = teacherController.getTeacherByName("New teacher");

    teacherController.
        changeTeacherRegestrationNumber(teacher.getId(), "new reg");

    teacher = teacherController.getTeacherByName("New teacher");

    ASSERT_EQ(teacher.getFullName(), "New teacher");
    ASSERT_EQ(teacher.getRegisterNumber(), "new reg");

    teacherController.deleteTeacher(teacher.getId());
}


TEST(PGGroupRepository, TestAddGroup)
{
    GroupRepositoryImplPg groupRepo = GroupRepositoryImplPg(conn);
    GroupController groupController(&groupRepo);

    groupController.addGroup("iu7-833n", 1);

    auto group = groupController.getGroup("iu7-833n");

    ASSERT_EQ(group.getName(), "iu7-833n");
    ASSERT_EQ(group.getTeacherId(), 1);

    groupController.deleteGroup(group.getId());
}

TEST(PGGroupRepository, TestRenameGroup)
{
    GroupRepositoryImplPg groupRepo = GroupRepositoryImplPg(conn);
    GroupController groupController(&groupRepo);

    groupController.addGroup("iu7-833n", 1);

    auto group = groupController.getGroup("iu7-833n");

    groupController.changeGroupName(group.getId(), "iu7-99b");

    group = groupController.getGroup("iu7-99b");
    ASSERT_EQ(group.getName(), "iu7-99b");
    ASSERT_EQ(group.getTeacherId(), 1);

    groupController.deleteGroup(group.getId());
}


TEST(PGGroupRepository, TestGetGroupByTeacherId)
{
    GroupRepositoryImplPg groupRepo = GroupRepositoryImplPg(conn);
    GroupController groupController(&groupRepo);

    auto groups = groupController.getAllGroupsByTeacherId(1);
    for (const auto & group : groups) {
        ASSERT_EQ(group.getTeacherId(), 1);
    }
}

TEST(PGSubjectRepository, TestAddSubject)
{
    SubjectRepositoryImplPg subjectRepo = SubjectRepositoryImplPg(conn);
    SubjectController subjectController(&subjectRepo);

    subjectController.addNewSubject("Math", 34, 1);

    auto subject = subjectController.getSubject("Math");

    ASSERT_EQ(subject.getSubjectName(), "Math");
    ASSERT_EQ(subject.getMarks(), 34);

    subjectController.deleteSubject(subject.getId());
}


TEST(PGSubjectRepository, TestRenameSubject)
{
    SubjectRepositoryImplPg subjectRepo = SubjectRepositoryImplPg(conn);
    SubjectController subjectController(&subjectRepo);

    subjectController.addNewSubject("Math", 34, 1);

    auto subject = subjectController.getSubject("Math");

    subjectController.changeSubjectName(subject.getId(), "Physics");

    subject = subjectController.getSubject("Physics");

    ASSERT_EQ(subject.getSubjectName(), "Physics");
    ASSERT_EQ(subject.getMarks(), 34);

    subjectController.deleteSubject(subject.getId());
}

TEST(PGSubjectRepository, TestStudentSubjects)
{
    SubjectRepositoryImplPg subjectRepo = SubjectRepositoryImplPg(conn);
    SubjectController subjectController(&subjectRepo);

    auto subjects = subjectController.getAllSubjectByStudentId(1);

    for (const auto & subject : subjects) {
        ASSERT_EQ(subject.getStudentId(), 1);
    }
}

TEST(PGAuthRepository, TestAddUserToAuth)
{
    AuthRepositoryImplPg authRepository = AuthRepositoryImplPg(conn);
    AuthController authController(&authRepository);

    authController.addNewUser("Khalid", "khalid", 1);

    Auth userDetails = authController.getUserDetails(1);

    ASSERT_EQ(userDetails.getTeacherId(), 1);
    ASSERT_EQ(userDetails.getLogin(), "Khalid");
    ASSERT_EQ(userDetails.getPassword(), "khalid");

    authController.deleteUserDetailsByTeacherId(userDetails.getTeacherId());

}

TEST(PGAuthRepository, TestChangeUserLogin)
{
    AuthRepositoryImplPg authRepository = AuthRepositoryImplPg(conn);
    AuthController authController(&authRepository);

    authController.addNewUser("Khalid", "khalid", 1);

    authController.changeUserLogin(1, "new Login");

    Auth userDetails = authController.getUserDetails(1);

    ASSERT_EQ(userDetails.getTeacherId(), 1);
    ASSERT_EQ(userDetails.getLogin(), "new Login");
    ASSERT_EQ(userDetails.getPassword(), "khalid");

    authController.deleteUserDetails(userDetails.getId());

}

TEST(PGAuthRepository, TestChangeUserPassword)
{
    AuthRepositoryImplPg authRepository = AuthRepositoryImplPg(conn);
    AuthController authController(&authRepository);

    authController.addNewUser("Khalid", "khalid", 1);

    authController.changeUserPassword(1, "new password");

    Auth userDetails = authController.getUserDetails(1);

    ASSERT_EQ(userDetails.getTeacherId(), 1);
    ASSERT_EQ(userDetails.getLogin(), "Khalid");
    ASSERT_EQ(userDetails.getPassword(), "new password");

    authController.deleteUserDetails(userDetails.getId());

}

TEST(MySqlAuthRepository, TestAddUserToAuth)
{
    AuthRepositoryImplMySql authRepository = AuthRepositoryImplMySql(url, user, password);
    AuthController authController(&authRepository);

    authController.addNewUser("khalid", "khalid", 1);

    Auth userDetails = authController.getUserDetails(1);

    ASSERT_EQ(userDetails.getTeacherId(), 1);
    ASSERT_EQ(userDetails.getLogin(), "khalid");
    ASSERT_EQ(userDetails.getPassword(), "khalid");

    authController.deleteUserDetailsByTeacherId(userDetails.getTeacherId());

}

TEST(MySqlAuthRepository, TestChangeUserLogin)
{
    AuthRepositoryImplMySql authRepository = AuthRepositoryImplMySql(url, user, password);
    AuthController authController(&authRepository);

    authController.addNewUser("Khalid", "khalid", 1);

    authController.changeUserLogin(1, "new Login");

    Auth userDetails = authController.getUserDetails(1);

    ASSERT_EQ(userDetails.getTeacherId(), 1);
    ASSERT_EQ(userDetails.getLogin(), "new Login");
    ASSERT_EQ(userDetails.getPassword(), "khalid");

    authController.deleteUserDetails(userDetails.getId());

}

TEST(MySqlAuthRepository, TestChangeUserPassword)
{
    AuthRepositoryImplMySql authRepository = AuthRepositoryImplMySql(url, user, password);
    AuthController authController(&authRepository);

    authController.addNewUser("Khalid", "khalid", 1);

    authController.changeUserPassword(1, "new password");

    Auth userDetails = authController.getUserDetails(1);

    ASSERT_EQ(userDetails.getTeacherId(), 1);
    ASSERT_EQ(userDetails.getLogin(), "Khalid");
    ASSERT_EQ(userDetails.getPassword(), "new password");

    authController.deleteUserDetails(userDetails.getId());

}

TEST(MySqlGroupRepository, TestAddGroup)
{
    GroupRepositoryImplMySql groupRepo = GroupRepositoryImplMySql(url, user, password);
    GroupController groupController(&groupRepo);

    groupController.addGroup("iu7-833n", 1);

    auto group = groupController.getGroup("iu7-833n");

    ASSERT_EQ(group.getName(), "iu7-833n");
    ASSERT_EQ(group.getTeacherId(), 1);

    groupController.deleteGroup(group.getId());
}

TEST(MySqlGroupRepository, TestRenameGroup)
{
    GroupRepositoryImplMySql groupRepo = GroupRepositoryImplMySql(url, user, password);
    GroupController groupController(&groupRepo);

    groupController.addGroup("iu7-833n", 1);

    auto group = groupController.getGroup("iu7-833n");

    groupController.changeGroupName(group.getId(), "iu7-99b");

    group = groupController.getGroup("iu7-99b");
    ASSERT_EQ(group.getName(), "iu7-99b");
    ASSERT_EQ(group.getTeacherId(), 1);

    groupController.deleteGroup(group.getId());
}


TEST(MySqlGroupRepository, TestGetGroupByTeacherId)
{
    GroupRepositoryImplMySql groupRepo = GroupRepositoryImplMySql(url, user, password);
    GroupController groupController(&groupRepo);

    auto groups = groupController.getAllGroupsByTeacherId(1);
    for (const auto & group : groups) {
        ASSERT_EQ(group.getTeacherId(), 1);
    }
}

TEST(MySqlStudentRepository, TestGetByName)
{
    StudentRepositoryImplMySql studetRepository = StudentRepositoryImplMySql(url, user, password);
    StudentController studentController(&studetRepository);

    studentController.addStudent("AAAA", "19iu14", 1);
    Student student = studentController.getStudentByName("AAAA");

    ASSERT_EQ(student.fullName(), "AAAA");
    ASSERT_EQ(student.admissionNumber(), "19iu14");
    ASSERT_EQ(student.groupId(), 1);

    studentController.deleteStudent(student.getId());
}


TEST(MySqlStudentRepository, TestChangeStudentName)
{
    StudentRepositoryImplMySql studetRepository = StudentRepositoryImplMySql(url, user, password);
    StudentController studentController(&studetRepository);


    studentController.changeStudentName(1, "Test name");

    Student student = studentController.getStudentByName("Test name");

    ASSERT_EQ(student.fullName(), "Test name");
    ASSERT_EQ(student.admissionNumber(), "19iu10");
    ASSERT_EQ(student.groupId(), 1);

}


TEST(MySqlStudentRepository, TestGroupAllStudents)
{
    StudentRepositoryImplMySql studetRepository = StudentRepositoryImplMySql(url, user, password);
    StudentController studentController(&studetRepository);


    studentController.changeStudentName(1, "Test name");

    auto students = studentController.getAllStudentsByGroupId(1);

    for (const auto & student : students) {
        ASSERT_EQ(student.groupId(), 1);
    }
}

TEST(MySqlSubjectRepository, TestAddSubject)
{
    SubjectRepositoryImplMySql subjectRepo = SubjectRepositoryImplMySql(url, user, password);
    SubjectController subjectController(&subjectRepo);

    subjectController.addNewSubject("Math", 34, 1);

    auto subject = subjectController.getSubject("Math");

    ASSERT_EQ(subject.getSubjectName(), "Math");
    ASSERT_EQ(subject.getMarks(), 34);

    subjectController.deleteSubject(subject.getId());
}


TEST(MySqlSubjectRepository, TestRenameSubject)
{
    SubjectRepositoryImplMySql subjectRepo = SubjectRepositoryImplMySql(url, user, password);
    SubjectController subjectController(&subjectRepo);

    subjectController.addNewSubject("math", 40, 1);

    auto subject = subjectController.getSubject("math");

    subjectController.changeSubjectName(subject.getId(), "physics");

    subject = subjectController.getSubject("physics");

    ASSERT_EQ(subject.getSubjectName(), "physics");
    ASSERT_EQ(subject.getMarks(), 40);

    subjectController.deleteSubject(subject.getId());
}

TEST(MySqlSubjectRepository, TestStudentSubjects)
{
    SubjectRepositoryImplMySql subjectRepo = SubjectRepositoryImplMySql(url, user, password);
    SubjectController subjectController(&subjectRepo);

    auto subjects = subjectController.getAllSubjectByStudentId(1);

    for (const auto & subject : subjects) {
        ASSERT_EQ(subject.getStudentId(), 1);
    }
}

TEST(MySqlTeacherRepository, TestAddTeacherAndGetByName)
{
    TeacherRepositoryImplMySql teacherRepo = TeacherRepositoryImplMySql(url, user, password);
    TeacherController teacherController(&teacherRepo);

    teacherController.addNewTeacher("new teacher", "a12332");

    Teacher teacher = teacherController.getTeacherByName("new teacher");

    ASSERT_EQ(teacher.getFullName(), "new teacher");
    ASSERT_EQ(teacher.getRegisterNumber(), "a12332");

    teacherController.deleteTeacher(teacher.getId());
}

TEST(MySqlTeacherRepository, TestTeacherRename)
{
    TeacherRepositoryImplMySql teacherRepo = TeacherRepositoryImplMySql(url, user, password);
    TeacherController teacherController(&teacherRepo);

    teacherController.addNewTeacher("New teacher", "a2323");

    Teacher teacher = teacherController.getTeacherByName("New teacher");

    teacherController.changeTeacherName(teacher.getId(), "new name");

    teacher = teacherController.getTeacherByName("new name");

    ASSERT_EQ(teacher.getFullName(), "new name");
    ASSERT_EQ(teacher.getRegisterNumber(), "a2323");

    teacherController.deleteTeacher(teacher.getId());
}


TEST(MySqlTeacherRepository, TestChangeTeacherRegestrationNumber)
{
    TeacherRepositoryImplMySql teacherRepo = TeacherRepositoryImplMySql(url, user, password);
    TeacherController teacherController(&teacherRepo);

    teacherController.addNewTeacher("New teacher", "a2323");

    Teacher teacher = teacherController.getTeacherByName("New teacher");

    teacherController.
        changeTeacherRegestrationNumber(teacher.getId(), "new reg");

    teacher = teacherController.getTeacherByName("New teacher");

    ASSERT_EQ(teacher.getFullName(), "New teacher");
    ASSERT_EQ(teacher.getRegisterNumber(), "new reg");

    teacherController.deleteTeacher(teacher.getId());
}
