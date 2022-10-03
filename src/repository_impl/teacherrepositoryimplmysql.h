#ifndef TEACHERREPOSITORYIMPLMYSQL_H
#define TEACHERREPOSITORYIMPLMYSQL_H

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "../repositories/teacherrepository.h"
#include "../logger/logger.h"



class TeacherRepositoryImplMySql : public TeacherRepository
{
    // TeacherRepository interface
public:
    TeacherRepositoryImplMySql(const std::string &hostUrl, const std::string &user, const std::string &password);


    ~TeacherRepositoryImplMySql();
    Teacher getTeacher(const std::string &teacherName);
    Teacher getTeacher(const int teacherId);
    void addNewTeacher(const std::string teacherFullName, const std::string teacherRegestrationNumber);
    void deleteTeacher(const int id);
    void renameTeacher(int id, std::string newName);
    void changeTeacherRegestrationNumber(int id, std::string newRegestrationNumber);
    std::vector<Teacher> getAllTeachers();
    Teacher getTeacherByRegNum(const std::string &teacherRegNum);

private:
    int getNumberOfRows();

private:
    std::string hostUrl;
    std::string user;
    std::string password;

private:
    sql::Driver * driver;
    sql::Connection * con;
    Logger * logger;
};

#endif // TEACHERREPOSITORYIMPLMYSQL_H
