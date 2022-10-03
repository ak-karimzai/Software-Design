#include "subjectrepositoryimplpg.h"

#include "../exceptions/exception.h"
#include "querygenerators.h"

#include <iostream>

using std::cout;
using std::endl;

SubjectRepositoryImplPg::SubjectRepositoryImplPg(const std::string &connectionParams) : connectionParams(connectionParams)
{
    try {
        logger = Logger::getInstance();
        connection = std::shared_ptr<pqxx::connection>(
                    new pqxx::connection(this->connectionParams.c_str())
        );
        if (!connection->is_open()) {
            logger->logWarning("connection error with database with this connection params: " + connectionParams);
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

SubjectRepositoryImplPg::~SubjectRepositoryImplPg()
{

}

void SubjectRepositoryImplPg::addNewSubject(const std::string subjectName, const int marks, const int studentId)
{
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        int numberOfRows = getNumberOfRows();
        std::string query = SubjectQueryGenerator::getAddSubjectQuery(numberOfRows + 1,
                                                                   subjectName,
                                                                   marks,
                                                                   studentId);
        pqxx::work work(*connection);
        work.exec(query);
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataUpdateException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

void SubjectRepositoryImplPg::changeSubjectName(const int id, std::string newSubjectName)
{
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = SubjectQueryGenerator::getChangeSubjectNameQuery(id,
                                                                   newSubjectName);
        pqxx::work work(*connection);
        work.exec(query);
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataUpdateException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

void SubjectRepositoryImplPg::changeSubjectMarks(const int id, const int newMarks)
{
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = SubjectQueryGenerator::getChangeSubjectMarksQuery(id,
                                                                   newMarks);
        pqxx::work work(*connection);
        work.exec(query);
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataUpdateException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

void SubjectRepositoryImplPg::changeSubjectStudentId(const int id, const int studentId)
{
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = SubjectQueryGenerator::getChangeSubjectStudentIdQuery(id,
                                                                                studentId);
        pqxx::work work(*connection);
        work.exec(query);
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataUpdateException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

void SubjectRepositoryImplPg::deleteSubject(const int id)
{
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = SubjectQueryGenerator::getDeleteSubjectQuery(id);
        pqxx::work work(*connection);
        work.exec(query);
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataDeleteException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

Subject SubjectRepositoryImplPg::getSubject(const std::string &subjectName)
{
    Subject subject;
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = SubjectQueryGenerator::getSubjectQuery(subjectName);
        pqxx::work work(*connection);
        pqxx::result result = work.exec(query);

        subject = Subject(
            result[0][0].as<int>(),
            result[0][1].as<std::string>(),
            result[0][2].as<int>(),
            result[0][3].as<int>()
        );
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
    return subject;
}

std::vector<Subject> SubjectRepositoryImplPg::getAllSubject()
{
    std::vector<Subject> subjects;
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = SubjectQueryGenerator::getAllSubjectQuery();
        pqxx::work work(*connection);
        pqxx::result results = work.exec(query);

        for (const auto & result : results) {
            subjects.push_back(
                        Subject(
                            result[0].as<int>(),
                            result[1].as<std::string>(),
                            result[2].as<int>(),
                            result[3].as<int>()
                        )
            );
        }
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
    return subjects;
}

std::vector<Subject> SubjectRepositoryImplPg::getSubjectByStudent(int studentId)
{
    std::vector<Subject> subjects;
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = SubjectQueryGenerator::getSubjectByStudentQuery(studentId);
        pqxx::work work(*connection);
        pqxx::result results = work.exec(query);

        for (const auto & result : results) {
            subjects.push_back(
                        Subject(
                            result[0].as<int>(),
                            result[1].as<std::string>(),
                            result[2].as<int>(),
                            result[3].as<int>()
                        )
            );
        }
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
    return subjects;
}

int SubjectRepositoryImplPg::getNumberOfRows()
{
    int numberOfRows = 0;
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = SubjectQueryGenerator::getNumberOfRowsQuery();
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
