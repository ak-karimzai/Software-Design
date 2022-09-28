#ifndef QUERYGENERATORS_H
#define QUERYGENERATORS_H

#include <string>

class GroupQueryGenerator
{
public:

    static std::string getNewGroupQuery(const int id, const std::string & groupName, const int teacherId);
    static std::string groupNameChangeQuery(const int groupId, const std::string & newGroupName);
    static std::string getGroupTeacherChangeQuery(const int id, const int newTeacherId);
    static std::string getAllGroupsQuery();
    static std::string getAllGroupsQuery(const int teacherId);
    static std::string deleteGroupQuery(const int groupId);
    static std::string getGroupQuery(const std::string & groupName);
    static std::string getNumberOfRowsQuery();

};

class StudentQueryGenerator
{
public:

    static std::string getAddStudentQuery(const int id,
                                          const std::string & studentName,
                                          const std::string & admissionNumber,
                                          const int groupId);
    static std::string getRemoveStudentQuery(const int id);
    static std::string getChangeStudentNameQuery(const int id,
                                                 const std::string & newName);
    static std::string getStudentQuery(const int id);
    static std::string getStudentQuery(const std::string & studentName);
    static std::string getAllStudentsQuery();
    static std::string getGroupAllStudentsQuery(const int id);
    static std::string getNumberOfRowsQuery();
};

class SubjectQueryGenerator
{
public:

//    static std::string;
    static std::string getAddSubjectQuery(const int id,
                                          const std::string & studentName,
                                          const int admissionNumber,
                                          const int groupId);
    static std::string getChangeSubjectNameQuery(const int id,
                                                 const std::string & newSubjectName);
    static std::string getChangeSubjectMarksQuery(const int id,
                                                 const int marks);
    static std::string getChangeSubjectStudentIdQuery(const int id,
                                                 const int sudentId);
    static std::string getAllSubjectQuery();
    static std::string getSubjectByStudentQuery(const int studentId);

    static std::string getDeleteSubjectQuery(const int id);
    static std::string getSubjectQuery(const std::string & subjectName);
    static std::string getNumberOfRowsQuery();

};

class TeacherQueryGenerator
{
public:

    static std::string getAddNewTeacherQuery(const int id,
                                             const std::string & teacherFullName,
                                             const std::string & teacherRegestrationNumber);

    static std::string getDeleteTeacherQuery(const int id);
    static std::string getRenameTeacherQuery(const int id,
                                             const std::string & newName);
    static std::string getChangeTeacherRegestrationNumberQuery(const int id,
                                                               const std::string & newRegestrationNumber);
    static std::string getAllTeachersQuery();
    static std::string getTeacherQuery(const std::string & teacherName);
    static std::string getTeacherQuery(const int teacherId);
    static std::string getTeacherByRegQuery(const std::string & teacherRegNum);
    static std::string getNumberOfRowsQuery();
};


class AuthQueryGenerator
{
public:

    static std::string getNewUserQuery(const int id,
                                       const std::string & login,
                                       const std::string & password,
                                       const int teacherId);
    static std::string changeUserPasswordQuery(const int teacherId,
                                               const std::string & newPassword);
    static std::string changeUserLoginQuery(const int teacherId,
                                               const std::string & newLogin);
    static std::string getLoginDetailsQuery(const int teacherId);
    static std::string getUsersQuery();
    static std::string getDeleteDetailsQuery(const int authId);
    static std::string getDeleteDetailsByTIdQuery(const int teacherId);
    static std::string getNumberOfRowsQuery();
};

#endif // QUERYGENERATORS_H
