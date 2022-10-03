#include "teacherrepositoryimplmysql.h"

#include "../exceptions/exception.h"
#include "querygenerators.h"

#include <iostream>

using std::cout;
using std::endl;

void TeacherRepositoryImplMySql::addNewTeacher(const std::string teacherFullName,
                                            const std::string teacherRegestrationNumber)
{
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        int rowNumbers = getNumberOfRows();
        std::string query = TeacherQueryGenerator::getAddNewTeacherQuery(rowNumbers + 1,
                                                                         teacherFullName,
                                                                         teacherRegestrationNumber
        );
        sql::ResultSet *res = stm->executeQuery(query);

        logger->logInfo(query + " executed!");
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
}

void TeacherRepositoryImplMySql::deleteTeacher(const int id)
{
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = TeacherQueryGenerator::getDeleteTeacherQuery(id);
        sql::ResultSet *res = stm->executeQuery(query);

        logger->logInfo(query + " executed!");
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
}

void TeacherRepositoryImplMySql::renameTeacher(int id, std::string newName)
{
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = TeacherQueryGenerator::getRenameTeacherQuery(id,
                                                                        newName);
        sql::ResultSet *res = stm->executeQuery(query);

        logger->logInfo(query + " executed!");
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
}

void TeacherRepositoryImplMySql::changeTeacherRegestrationNumber(int id, std::string newRegestrationNumber)
{
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = TeacherQueryGenerator::getChangeTeacherRegestrationNumberQuery(id,
                                                                        newRegestrationNumber);
        sql::ResultSet *res = stm->executeQuery(query);

        logger->logInfo(query + " executed!");
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
}

std::vector<Teacher> TeacherRepositoryImplMySql::getAllTeachers()
{
    std::vector<Teacher> teachers;
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = TeacherQueryGenerator::getAllTeachersQuery();

        sql::ResultSet *res = stm->executeQuery(query);

        while (res->next()) {
            teachers.push_back(
                        Teacher(
                            res->getInt(1),
                            res->getString(2),
                            res->getString(3)
                        )
            );
        }

        logger->logInfo(query + " executed!");
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
    return teachers;
}

Teacher TeacherRepositoryImplMySql::getTeacherByRegNum(const std::string &teacherRegNum)
{
    Teacher teacher;
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = TeacherQueryGenerator::getTeacherByRegQuery(teacherRegNum);
        sql::ResultSet *res = stm->executeQuery(query);

        if (res->next())
            teacher = Teacher(
                        res->getInt(1),
                        res->getString(2),
                        res->getString(3)
                    );

        logger->logInfo(query + " executed!");
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
    return teacher;
}

Teacher TeacherRepositoryImplMySql::getTeacher(const std::string &teacherName)
{
    Teacher teacher;
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = TeacherQueryGenerator::getTeacherQuery(teacherName);
        sql::ResultSet *res = stm->executeQuery(query);

        if (res->next())
            teacher = Teacher(
                        res->getInt(1),
                        res->getString(2),
                        res->getString(3)
                    );

        logger->logInfo(query + " executed!");
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
    return teacher;
}

Teacher TeacherRepositoryImplMySql::getTeacher(const int teacherId)
{
    Teacher teacher;
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }

        sql::Statement *stm = con->createStatement();
        std::string query = TeacherQueryGenerator::getTeacherQuery(teacherId);
        sql::ResultSet *res = stm->executeQuery(query);

        if (res->next())
            teacher = Teacher(
                        res->getInt(1),
                        res->getString(2),
                        res->getString(3)
                    );

        logger->logInfo(query + " executed!");
        delete res;
        delete stm;
    }  catch (const std::exception & e) {
        logger->logError(e.what());;
    }
    return teacher;
}

int TeacherRepositoryImplMySql::getNumberOfRows()
{
    int numberOfRows = 0;
    try {
        if (!con->isValid()) {
            logger->logWarning("Connection problem with mysql dbms!");
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        sql::Statement *stm = con->createStatement();
        std::string query = TeacherQueryGenerator::getNumberOfRowsQuery();
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

TeacherRepositoryImplMySql::~TeacherRepositoryImplMySql()
{
    con->close();
    delete con;
}

TeacherRepositoryImplMySql::TeacherRepositoryImplMySql(const std::string &hostUrl, const std::string &user, const std::string &password) : hostUrl(hostUrl),
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
