#ifndef SUBJECTREPOSITORYIMPLMYSQL_H
#define SUBJECTREPOSITORYIMPLMYSQL_H

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>


#include "../repositories/subjectrepository.h"


class SubjectRepositoryImplMySql : public SubjectRepository
{    
    // SubjectRepository interface
public:
    SubjectRepositoryImplMySql(const std::string &hostUrl, const std::string &user, const std::string &password);


    ~SubjectRepositoryImplMySql();
    void addNewSubject(const std::string subjectName, const int marks, const int studentId);
    void changeSubjectName(const int id, std::string newSubjectName);
    void changeSubjectMarks(const int id, const int newMarks);
    void changeSubjectStudentId(const int id, const int studentId);
    void deleteSubject(const int id);
    Subject getSubject(const std::string & subjectName);
    std::vector<Subject> getAllSubject();
    std::vector<Subject> getSubjectByStudent(int studentId);

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

#endif // SUBJECTREPOSITORYIMPLMYSQL_H
