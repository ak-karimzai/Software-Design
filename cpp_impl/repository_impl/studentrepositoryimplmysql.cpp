#include "studentrepositoryimplmysql.h"

#include "../exceptions/exception.h"
#include "querygenerators.h"

#include <iostream>

using std::cout;
using std::endl;

void StudentRepositoryImplMySql::addStudent(const std::string studentName, const std::string admissionNumber, const int groupId)
{
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        int rowNumbers = getNumberOfRows();
        std::string query = StudentQueryGenerator::getAddStudentQuery(rowNumbers + 1,
                                                                   studentName,
                                                                   admissionNumber,
                                                                   groupId);
        sql::ResultSet *res = stm->executeQuery(query);

        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void StudentRepositoryImplMySql::removeStudent(const int id)
{
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = StudentQueryGenerator::getRemoveStudentQuery(id);
        sql::ResultSet *res = stm->executeQuery(query);

        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void StudentRepositoryImplMySql::changeStudentName(int id, const std::string newName)
{
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = StudentQueryGenerator::getChangeStudentNameQuery(id, newName);
        sql::ResultSet *res = stm->executeQuery(query);

        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

Student StudentRepositoryImplMySql::getStudent(int id)
{
    Student student;
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = StudentQueryGenerator::getStudentQuery(id);
        sql::ResultSet *res = stm->executeQuery(query);

        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return student;
}

Student StudentRepositoryImplMySql::getStudent(const std::string &studentName)
{
    Student student;
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = StudentQueryGenerator::getStudentQuery(studentName);
        sql::ResultSet *res = stm->executeQuery(query);

        if (res->next())
            student = Student(res->getInt(1),
                              res->getString(2),
                              res->getString(3),
                              res->getInt(4));

        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return student;
}

std::vector<Student> StudentRepositoryImplMySql::getAllStudents()
{
    std::vector<Student> students;
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = StudentQueryGenerator::getAllStudentsQuery();
        sql::ResultSet *res = stm->executeQuery(query);


        while (res->next()) {
            students.push_back(
                      Student(res->getInt(1),
                              res->getString(2),
                              res->getString(3),
                              res->getInt(4))
                     );
        }

        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return students;
}

std::vector<Student> StudentRepositoryImplMySql::getGroupAllStudents(int groupId)
{
    std::vector<Student> students;
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = StudentQueryGenerator::getGroupAllStudentsQuery(groupId);
        sql::ResultSet *res = stm->executeQuery(query);


        while (res->next()) {
            students.push_back(
                      Student(res->getInt(1),
                              res->getString(2),
                              res->getString(3),
                              res->getInt(4))
                     );
        }

        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return students;
}

int StudentRepositoryImplMySql::getNumberOfRows()
{
    int numberOfRows = 0;
    try {
        if (!con->isValid()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        sql::Statement *stm = con->createStatement();
        std::string query = StudentQueryGenerator::getNumberOfRowsQuery();
        sql::ResultSet *res = stm->executeQuery(query);

        if (res->next())
            numberOfRows = res->getInt(1);

        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return numberOfRows;
}

StudentRepositoryImplMySql::~StudentRepositoryImplMySql()
{
}

StudentRepositoryImplMySql::StudentRepositoryImplMySql(const std::string &hostUrl, const std::string &user, const std::string &password) : hostUrl(hostUrl),
    user(user),
    password(password)
{
    driver = get_driver_instance();
    con = driver->connect(hostUrl, user, password);

    if (!con->isValid()) {
        throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
}
