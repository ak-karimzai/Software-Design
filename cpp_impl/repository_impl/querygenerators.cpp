#include "querygenerators.h"

#include <sstream>

std::string GroupQueryGenerator::getNewGroupQuery(const int id, const std::string &groupName, const int teacherId)
{
    std::stringstream ss;
    ss << "insert into tbl_group(group_id, group_name, teacher_id) values(" << id <<
          ",'" << groupName << "', " << teacherId << ")";
    return ss.str();
}

std::string GroupQueryGenerator::groupNameChangeQuery(const int groupId, const std::string &newGroupName)
{
    std::stringstream ss;
    ss << "update tbl_group " <<
          "set group_name = '" << newGroupName << "'" <<
          "where group_id = " << groupId;
    return ss.str();
}

std::string GroupQueryGenerator::getGroupTeacherChangeQuery(const int id, const int newTeacherId)
{
    std::stringstream ss;
    ss << "update tbl_group " <<
          "set teacher_id = " << newTeacherId << " " <<
          "where group_id = " << id;
    return ss.str();
}

std::string GroupQueryGenerator::getAllGroupsQuery()
{
    std::stringstream ss;
    ss << "select * from tbl_group ";
    return ss.str();
}

std::string GroupQueryGenerator::getAllGroupsQuery(const int teacherId)
{
    std::stringstream ss;
    ss << "select * from tbl_group " <<
          "where teacher_id = " << teacherId;
    return ss.str();
}

std::string GroupQueryGenerator::deleteGroupQuery(const int groupId)
{
    std::stringstream ss;
    ss << "delete from tbl_group " <<
          "where group_id = " << groupId;
    return ss.str();
}

std::string GroupQueryGenerator::getGroupQuery(const std::string &groupName)
{
    std::stringstream ss;
    ss << "select * from tbl_group " <<
          "where group_name like '" << groupName << "'";
    return ss.str();
}

std::string GroupQueryGenerator::getNumberOfRowsQuery()
{
    std::stringstream ss;
    ss << "select max(group_id) from tbl_group ";
    return ss.str();
}

std::string StudentQueryGenerator::getAddStudentQuery(const int id,
                                                      const std::string &studentName,
                                                      const std::string &admissionNumber,
                                                      const int groupId)
{
    std::stringstream ss;
    ss << "insert into tbl_student(student_id, student_name, student_admission, group_id) values " <<
        "(" << id << ",'" << studentName << "', '" << admissionNumber << "', " << groupId << ")";
    return ss.str();
}

std::string StudentQueryGenerator::getRemoveStudentQuery(const int id)
{
    std::stringstream ss;
    ss << "delete from tbl_student " <<
          "where student_id = " << id;
    return ss.str();
}

std::string StudentQueryGenerator::getChangeStudentNameQuery(const int id, const std::string &newName)
{
    std::stringstream ss;
    ss << "update tbl_student " <<
          "set student_name = '" << newName << "' " <<
          "where student_id = " << id;
    return ss.str();
}

std::string StudentQueryGenerator::getStudentQuery(const int id)
{
    std::stringstream ss;
    ss << "select * from tbl_student " <<
          "where student_id = " << id;
    return ss.str();
}

std::string StudentQueryGenerator::getStudentQuery(const std::string & studentName)
{
    std::stringstream ss;
    ss << "select * from tbl_student " <<
          "where student_name like '" << studentName << "'";
    return ss.str();
}

std::string StudentQueryGenerator::getAllStudentsQuery()
{
    std::stringstream ss;
    ss << "select * from tbl_student";
    return ss.str();
}

std::string StudentQueryGenerator::getGroupAllStudentsQuery(const int id)
{
    std::stringstream ss;
    ss << "select * from tbl_student " <<
          "where group_id = " << id;
    return ss.str();
}

std::string StudentQueryGenerator::getNumberOfRowsQuery()
{
    std::stringstream ss;
    ss << "select max(student_id) from tbl_student ";
    return ss.str();
}

std::string SubjectQueryGenerator::getAddSubjectQuery(const int id,
                                                      const std::string &sujectName,
                                                      const int marks,
                                                      const int studentId)
{
    std::stringstream ss;
    ss << "insert into tbl_subject(subject_id, subject_name, marks, student_id) "
       << "values (" << id << ",'" << sujectName << "', " << marks << ", " << studentId
       << ")";
    return ss.str();
}

std::string SubjectQueryGenerator::getChangeSubjectNameQuery(const int id, const std::string &newSubjectName)
{
    std::stringstream ss;
    ss << "update tbl_subject " <<
          "set subject_name = '" << newSubjectName << "' " <<
          "where subject_id = " << id;
    return ss.str();
}

std::string SubjectQueryGenerator::getChangeSubjectMarksQuery(const int id, const int marks)
{
    std::stringstream ss;
    ss << "update tbl_subject " <<
          "set marks = " << marks << " " <<
          "where subject_id = id";
    return ss.str();
}

std::string SubjectQueryGenerator::getChangeSubjectStudentIdQuery(const int id, const int sudentId)
{
    std::stringstream ss;
    ss << "update tbl_subject " <<
          "set student_id = " << sudentId << " " <<
          "where subject_id = id";
    return ss.str();
}

std::string SubjectQueryGenerator::getAllSubjectQuery()
{
    std::stringstream ss;
    ss << "select * from tbl_subject";
    return ss.str();
}

std::string SubjectQueryGenerator::getSubjectByStudentQuery(const int studentId)
{
    std::stringstream ss;
    ss << "select * from tbl_subject " <<
          "where student_id = " << studentId;
    return ss.str();
}

std::string SubjectQueryGenerator::getDeleteSubjectQuery(const int id)
{
    std::stringstream ss;
    ss << "delete from tbl_subject " <<
          "where subject_id = " << id;
    return ss.str();
}

std::string SubjectQueryGenerator::getSubjectQuery(const std::string &subjectName)
{
    std::stringstream ss;
    ss << "select * from tbl_subject " <<
          "where subject_name like '" << subjectName << "'";
    return ss.str();
}

std::string SubjectQueryGenerator::getNumberOfRowsQuery()
{
    std::stringstream ss;
    ss << "select max(subject_id) from tbl_subject ";
    return ss.str();
}

std::string TeacherQueryGenerator::getAddNewTeacherQuery(const int id,
                                                         const std::string &teacherFullName,
                                                         const std::string &teacherRegestrationNumber)
{
    std::stringstream ss;
    ss << "insert into tbl_teacher(teacher_id, teacher_name, regestration_number) values "
       << "( " << id << ", '" << teacherFullName << "', '" << teacherRegestrationNumber << "')";
    return ss.str();
}

std::string TeacherQueryGenerator::getDeleteTeacherQuery(const int id)
{
    std::stringstream ss;
    ss << "delete from tbl_teacher " <<
          "where teacher_id = " << id;
    return ss.str();
}

std::string TeacherQueryGenerator::getRenameTeacherQuery(const int id, const std::string &newName)
{
    std::stringstream ss;
    ss << "update tbl_teacher " <<
          "set teacher_name = '" << newName << "'" <<
          "where teacher_id = " << id;
    return ss.str();
}

std::string TeacherQueryGenerator::getChangeTeacherRegestrationNumberQuery(const int id,
                                                                           const std::string &newRegestrationNumber)
{
    std::stringstream ss;
    ss << "update tbl_teacher " <<
          "set regestration_number = '" << newRegestrationNumber << "'" <<
          "where teacher_id = " << id;
    return ss.str();
}

std::string TeacherQueryGenerator::getAllTeachersQuery()
{
    std::stringstream ss;
    ss << "select * from tbl_teacher";
    return ss.str();
}


std::string TeacherQueryGenerator::getTeacherQuery(const std::string & teacherName)
{
    std::stringstream ss;
    ss << "select * from tbl_teacher " <<
          "where teacher_name like '" << teacherName << "'";
    return ss.str();
}

std::string TeacherQueryGenerator::getTeacherQuery(const int teacherId)
{
    std::stringstream ss;
    ss << "select * from tbl_teacher " <<
          "where teacher_id = "<< teacherId;
    return ss.str();
}

std::string TeacherQueryGenerator::getTeacherByRegQuery(const std::string &teacherRegNum)
{
    std::stringstream ss;
    ss << "select * from tbl_teacher " <<
          "where regestration_number like '" << teacherRegNum << "'";
    return ss.str();
}

std::string TeacherQueryGenerator::getNumberOfRowsQuery()
{
    std::stringstream ss;
    ss << "select max(teacher_id) from tbl_teacher ";
    return ss.str();
}

std::string AuthQueryGenerator::getNewUserQuery(const int id, const std::string &login, const std::string &password, const int teacherId)
{
    std::stringstream ss;
    ss << "insert into tbl_auth(auth_id, login, password, teacher_id) values (" << id << ", '" <<
          login << "', '" << password << "', " << teacherId << ")";
    return ss.str();
}

std::string AuthQueryGenerator::changeUserPasswordQuery(const int teacherId, const std::string &newPassword)
{
    std::stringstream ss;
    ss << "update tbl_auth " <<
          "set password = '" <<
          newPassword << "' " <<
          "where teacher_id = " <<
          teacherId;
    return ss.str();
}

std::string AuthQueryGenerator::changeUserLoginQuery(const int teacherId, const std::string &newLogin)
{
    std::stringstream ss;
    ss << "update tbl_auth " <<
          "set login = '" <<
          newLogin << "' " <<
          "where teacher_id = " <<
          teacherId;
    return ss.str();
}

std::string AuthQueryGenerator::getLoginDetailsQuery(const int teacherId)
{
    std::stringstream ss;
    ss << "select * from tbl_auth " <<
          "where teacher_id = " << teacherId;
    return ss.str();
}

std::string AuthQueryGenerator::getUsersQuery()
{
    std::stringstream ss;
    ss << "select * from tbl_auth ";
    return ss.str();
}

std::string AuthQueryGenerator::getDeleteDetailsQuery(const int authId)
{
    std::stringstream ss;
    ss << "delete from tbl_auth " <<
          "where auth_id = " << authId;
    return ss.str();
}

std::string AuthQueryGenerator::getDeleteDetailsByTIdQuery(const int teacherId)
{
    std::stringstream ss;
    ss << "delete from tbl_auth " <<
          "where teacher_id = " << teacherId;
    return ss.str();
}

std::string AuthQueryGenerator::getNumberOfRowsQuery()
{
    std::stringstream ss;
    ss << "select max(auth_id) from tbl_auth ";
    return ss.str();
}
