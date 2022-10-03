#include "studentrepositoryimplpg.h"

#include "../exceptions/exception.h"
#include "querygenerators.h"

#include <iostream>

using std::cout;
using std::endl;

void StudentRepositoryImplPg::addStudent(const std::string studentName, const std::string admissionNumber, const int groupId)
{
    try {
        if (!connection->is_open()) {
            logger->logWarning("connection error with database with this connection params: " + connectionParams);
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        int rowNumbers = getNumberOfRows();
        std::string query = StudentQueryGenerator::getAddStudentQuery(rowNumbers + 1,
                                                                   studentName,
                                                                   admissionNumber,
                                                                   groupId);
        pqxx::work work(*connection);
        work.exec(query);
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataUpdateException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

void StudentRepositoryImplPg::removeStudent(const int id)
{
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = StudentQueryGenerator::getRemoveStudentQuery(id);
        pqxx::work work(*connection);
        work.exec(query);
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataDeleteException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

void StudentRepositoryImplPg::changeStudentName(int id, const std::string newName)
{
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = StudentQueryGenerator::getChangeStudentNameQuery(id, newName);
        pqxx::work work(*connection);
        work.exec(query);
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataUpdateException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

Student StudentRepositoryImplPg::getStudent(int id)
{
    Student student;
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = StudentQueryGenerator::getStudentQuery(id);
        pqxx::work work(*connection);
        pqxx::result result = work.exec(query);

        try {
            student = Student(result[0][0].as<int>(),
                              result[0][1].as<std::string>(),
                              result[0][2].as<std::string>(),
                              result[0][3].as<int>());
        } catch (const std::exception & e) {
            cout << e.what() << endl;
        }
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
    return student;
}

Student StudentRepositoryImplPg::getStudent(const std::string &studentName)
{
    Student student;
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = StudentQueryGenerator::getStudentQuery(studentName);
        pqxx::work work(*connection);
        pqxx::result result = work.exec(query);

        student = Student(result[0][0].as<int>(),
                          result[0][1].as<std::string>(),
                          result[0][2].as<std::string>(),
                          result[0][3].as<int>());
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
    return student;
}

std::vector<Student> StudentRepositoryImplPg::getAllStudents()
{
    std::vector<Student> students;
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = StudentQueryGenerator::getAllStudentsQuery();
        pqxx::work work(*connection);
        pqxx::result results = work.exec(query);

        for (const auto & result : results) {
            students.push_back(
                        Student(result[0].as<int>(),
                              result[1].as<std::string>(),
                              result[2].as<std::string>(),
                              result[3].as<int>())
                     );
        }
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
    return students;
}

std::vector<Student> StudentRepositoryImplPg::getGroupAllStudents(int groupId)
{
    std::vector<Student> students;
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = StudentQueryGenerator::getGroupAllStudentsQuery(groupId);
        pqxx::work work(*connection);
        pqxx::result result = work.exec(query);

        pqxx::result results = work.exec(query);

        for (const auto & result : results) {
            students.push_back(
                        Student(result[0].as<int>(),
                              result[1].as<std::string>(),
                              result[2].as<std::string>(),
                              result[3].as<int>())
                     );
        }
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
    return students;
}

int StudentRepositoryImplPg::getNumberOfRows()
{
    int numberOfRows = 0;
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = StudentQueryGenerator::getNumberOfRowsQuery();
        pqxx::work work(*connection);
        pqxx::result result = work.exec(query);
        numberOfRows = result[0][0].as<int>();
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
    return numberOfRows;
}


StudentRepositoryImplPg::StudentRepositoryImplPg(const std::string &connectionParams) : connectionParams(connectionParams)
{
    try {
        logger = Logger::getInstance();
        connection = std::shared_ptr<pqxx::connection>(
                    new pqxx::connection(this->connectionParams.c_str())
        );
        if (!connection->is_open()) {
            logger->logError("connection error with database with this connection params: " + connectionParams);
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

StudentRepositoryImplPg::~StudentRepositoryImplPg()
{
}
