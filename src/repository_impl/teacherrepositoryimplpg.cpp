#include "teacherrepositoryimplpg.h"

#include "../exceptions/exception.h"
#include "querygenerators.h"

#include <iostream>

using std::cout;
using std::endl;

void TeacherRepositoryImplPg::addNewTeacher(const std::string teacherFullName,
                                            const std::string teacherRegestrationNumber)
{
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        int rowNumbers = getNumberOfRows();
        std::string query = TeacherQueryGenerator::getAddNewTeacherQuery(rowNumbers + 1,
                                                                         teacherFullName,
                                                                         teacherRegestrationNumber
        );
        pqxx::work work(*connection);
        work.exec(query);
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataUpdateException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

void TeacherRepositoryImplPg::deleteTeacher(const int id)
{
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = TeacherQueryGenerator::getDeleteTeacherQuery(id);
        pqxx::work work(*connection);
        work.exec(query);
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataDeleteException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

void TeacherRepositoryImplPg::renameTeacher(int id, std::string newName)
{
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = TeacherQueryGenerator::getRenameTeacherQuery(id,
                                                                        newName);
        pqxx::work work(*connection);
        work.exec(query);
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataUpdateException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

void TeacherRepositoryImplPg::changeTeacherRegestrationNumber(int id, std::string newRegestrationNumber)
{
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = TeacherQueryGenerator::getChangeTeacherRegestrationNumberQuery(id,
                                                                        newRegestrationNumber);
        pqxx::work work(*connection);
        work.exec(query);
        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataUpdateException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

std::vector<Teacher> TeacherRepositoryImplPg::getAllTeachers()
{
    std::vector<Teacher> teachers;
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = TeacherQueryGenerator::getAllTeachersQuery();
        pqxx::work work(*connection);
        pqxx::result results = work.exec(query);

        for (const auto & result : results) {
            teachers.push_back(
                        Teacher(
                            result[0].as<int>(),
                            result[1].as<std::string>(),
                            result[2].as<std::string>()
                        )
            );
        }

        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
    return teachers;
}

Teacher TeacherRepositoryImplPg::getTeacherByRegNum(const std::string &teacherRegNum)
{
    Teacher teacher;
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = TeacherQueryGenerator::getTeacherByRegQuery(teacherRegNum);
        pqxx::work work(*connection);
        pqxx::result result = work.exec(query);

        teacher = Teacher(
                      result[0][0].as<int>(),
                      result[0][1].as<std::string>(),
                      result[0][2].as<std::string>()
        );

        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
    return teacher;
}

Teacher TeacherRepositoryImplPg::getTeacher(const std::string &teacherName)
{
    Teacher teacher;
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = TeacherQueryGenerator::getTeacherQuery(teacherName);
        pqxx::work work(*connection);
        pqxx::result result = work.exec(query);

        teacher = Teacher(
                      result[0][0].as<int>(),
                      result[0][1].as<std::string>(),
                      result[0][2].as<std::string>()
        );

        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
    return teacher;
}

Teacher TeacherRepositoryImplPg::getTeacher(const int teacherId)
{
    Teacher teacher;
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = TeacherQueryGenerator::getTeacherQuery(teacherId);
        pqxx::work work(*connection);
        pqxx::result result = work.exec(query);

        teacher = Teacher(
                      result[0][0].as<int>(),
                      result[0][1].as<std::string>(),
                      result[0][2].as<std::string>()
        );

        logger->logInfo(query + " executed!");
        work.commit();
    }  catch (const std::exception & e) {
        logger->logError(e.what());
        throw DataAccessException(__FILE__, typeid(*this).name(), __LINE__);
    }
    return teacher;
}

int TeacherRepositoryImplPg::getNumberOfRows()
{
    int numberOfRows = 0;
    try {
        if (!connection->is_open()) {
            logger->logWarning("Connection problem with psql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = TeacherQueryGenerator::getNumberOfRowsQuery();
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

TeacherRepositoryImplPg::TeacherRepositoryImplPg(const std::string &connectionParams) : connectionParams(connectionParams)
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

TeacherRepositoryImplPg::~TeacherRepositoryImplPg()
{

}
