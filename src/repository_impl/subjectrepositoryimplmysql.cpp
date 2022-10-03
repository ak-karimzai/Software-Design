#include "subjectrepositoryimplmysql.h"

#include "../exceptions/exception.h"
#include "querygenerators.h"

#include <iostream>

using std::cout;
using std::endl;


SubjectRepositoryImplMySql::~SubjectRepositoryImplMySql()
{
    con->close();
    delete con;
}

void SubjectRepositoryImplMySql::addNewSubject(const std::string subjectName, const int marks, const int studentId)
{
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        int numberOfRows = getNumberOfRows();
        std::string query = SubjectQueryGenerator::getAddSubjectQuery(numberOfRows + 1,
                                                                   subjectName,
                                                                   marks,
                                                                   studentId);
        sql::ResultSet *res = stm->executeQuery(query);
        logger->logInfo(query + " executed!");
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
}

void SubjectRepositoryImplMySql::changeSubjectName(const int id, std::string newSubjectName)
{
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = SubjectQueryGenerator::getChangeSubjectNameQuery(id,
                                                                   newSubjectName);
        sql::ResultSet *res = stm->executeQuery(query);
        logger->logInfo(query + " executed!");
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
}

void SubjectRepositoryImplMySql::changeSubjectMarks(const int id, const int newMarks)
{
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = SubjectQueryGenerator::getChangeSubjectMarksQuery(id,
                                                                   newMarks);
        sql::ResultSet *res = stm->executeQuery(query);
        logger->logInfo(query + " executed!");
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
}

void SubjectRepositoryImplMySql::changeSubjectStudentId(const int id, const int studentId)
{
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = SubjectQueryGenerator::getChangeSubjectStudentIdQuery(id,
                                                                                studentId);
        sql::ResultSet *res = stm->executeQuery(query);
        delete res;
        delete stm;
        logger->logInfo(query + " executed!");
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
}

void SubjectRepositoryImplMySql::deleteSubject(const int id)
{
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = SubjectQueryGenerator::getDeleteSubjectQuery(id);
        sql::ResultSet *res = stm->executeQuery(query);
        delete res;
        delete stm;
        logger->logInfo(query + " executed!");
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
}

Subject SubjectRepositoryImplMySql::getSubject(const std::string &subjectName)
{
    Subject subject;
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = SubjectQueryGenerator::getSubjectQuery(subjectName);
        sql::ResultSet *res = stm->executeQuery(query);

        if (res->next())
            subject = Subject(
                res->getInt(1),
                res->getString(2),
                res->getInt(3),
                res->getInt(4)
            );

        logger->logInfo(query + " executed!");
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
    return subject;
}

std::vector<Subject> SubjectRepositoryImplMySql::getAllSubject()
{
    std::vector<Subject> subjects;
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = SubjectQueryGenerator::getAllSubjectQuery();
        sql::ResultSet *res = stm->executeQuery(query);

        while (res->next()) {
            subjects.push_back(
                        Subject(
                                res->getInt(1),
                                res->getString(2),
                                res->getInt(3),
                                res->getInt(4)
                               )
                        );
        }
        logger->logInfo(query + " executed!");
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
    return subjects;
}

std::vector<Subject> SubjectRepositoryImplMySql::getSubjectByStudent(int studentId)
{
    std::vector<Subject> subjects;
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = SubjectQueryGenerator::getSubjectByStudentQuery(studentId);
        sql::ResultSet *res = stm->executeQuery(query);

        while (res->next()) {
            subjects.push_back(
                        Subject(
                                res->getInt(1),
                                res->getString(2),
                                res->getInt(3),
                                res->getInt(4)
                               )
                        );
        }
        logger->logInfo(query + " executed!");
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
    return subjects;
}

int SubjectRepositoryImplMySql::getNumberOfRows()
{
    int numberOfRows = 0;
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        sql::Statement *stm = con->createStatement();
        std::string query = SubjectQueryGenerator::getNumberOfRowsQuery();
        sql::ResultSet *res = stm->executeQuery(query);

        if (res->next())
            numberOfRows = res->getInt(1);

        logger->logInfo(query + " executed!");
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
    return numberOfRows;
}

SubjectRepositoryImplMySql::SubjectRepositoryImplMySql(const std::string &hostUrl, const std::string &user, const std::string &password) : hostUrl(hostUrl),
    user(user),
    password(password)
{
    logger = Logger::getInstance();
    driver = get_driver_instance();
    con = driver->connect(hostUrl, user, password);

    if (!con->isValid()) {
        logger->logWarning("connection error with database with " + hostUrl + " " + user + " " + password);
        throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
}
