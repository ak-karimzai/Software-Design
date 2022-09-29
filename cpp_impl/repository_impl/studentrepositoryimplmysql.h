#ifndef STUDENTREPOSITORYIMPLMYSQL_H
#define STUDENTREPOSITORYIMPLMYSQL_H


#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "../repositories/studentrepository.h"


class StudentRepositoryImplMySql : public StudentRepository
{
    // StudentRepository interface
public:
    StudentRepositoryImplMySql(const std::string &hostUrl, const std::string &user, const std::string &password);


    ~StudentRepositoryImplMySql();
    void addStudent(const std::string studentName, const std::string admissionNumber, const int groupId);
    void removeStudent(const int id);
    void changeStudentName(int id, const std::string newName);
    Student getStudent(const int id);
    Student getStudent(const std::string & studentName);

    std::vector<Student> getAllStudents();
    std::vector<Student> getGroupAllStudents(int groupId);

private:
    int getNumberOfRows();

private:
    std::string hostUrl;
    std::string user;
    std::string password;

private:
    sql::Driver * driver;
    sql::Connection * con;
};

#endif // STUDENTREPOSITORYIMPLMYSQL_H
