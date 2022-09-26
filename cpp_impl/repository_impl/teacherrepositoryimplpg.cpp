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
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = TeacherQueryGenerator::getAddNewTeacherQuery(
                                                                        teacherFullName,
                                                                        teacherRegestrationNumber
        );
        pqxx::work work(*connection);
        work.exec(query);
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void TeacherRepositoryImplPg::deleteTeacher(const int id)
{
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = TeacherQueryGenerator::getDeleteTeacherQuery(id);
        pqxx::work work(*connection);
        work.exec(query);
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void TeacherRepositoryImplPg::renameTeacher(int id, std::string newName)
{
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = TeacherQueryGenerator::getRenameTeacherQuery(id,
                                                                        newName);
        pqxx::work work(*connection);
        work.exec(query);
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void TeacherRepositoryImplPg::changeTeacherRegestrationNumber(int id, std::string newRegestrationNumber)
{
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = TeacherQueryGenerator::getChangeTeacherRegestrationNumberQuery(id,
                                                                        newRegestrationNumber);
        pqxx::work work(*connection);
        work.exec(query);
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

std::vector<Teacher> TeacherRepositoryImplPg::getAllTeachers()
{
    std::vector<Teacher> teachers;
    try {
        if (!connection->is_open()) {
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

        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return teachers;
}

Teacher TeacherRepositoryImplPg::getTeacher(const std::string &teacherName)
{
    Teacher teacher;
    try {
        if (!connection->is_open()) {
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

        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return teacher;
}

TeacherRepositoryImplPg::TeacherRepositoryImplPg(const std::string &connectionParams) : connectionParams(connectionParams)
{
    try {
        connection = std::shared_ptr<pqxx::connection>(
                    new pqxx::connection(this->connectionParams.c_str())
        );
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

TeacherRepositoryImplPg::~TeacherRepositoryImplPg()
{

}
