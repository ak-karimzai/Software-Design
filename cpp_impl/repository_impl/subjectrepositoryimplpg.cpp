#include "subjectrepositoryimplpg.h"

#include "../exceptions/exception.h"
#include "querygenerators.h"

#include <iostream>

using std::cout;
using std::endl;

SubjectRepositoryImplPg::SubjectRepositoryImplPg(const std::string &connectionParams) : connectionParams(connectionParams)
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

SubjectRepositoryImplPg::~SubjectRepositoryImplPg()
{

}

void SubjectRepositoryImplPg::addNewSubject(const std::string subjectName, const int marks, const int studentId)
{
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        int numberOfRows = getNumberOfRows();
        std::string query = SubjectQueryGenerator::getAddSubjectQuery(numberOfRows + 1,
                                                                   subjectName,
                                                                   marks,
                                                                   studentId);
        pqxx::work work(*connection);
        work.exec(query);
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void SubjectRepositoryImplPg::changeSubjectName(const int id, std::string newSubjectName)
{
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = SubjectQueryGenerator::getChangeSubjectNameQuery(id,
                                                                   newSubjectName);
        pqxx::work work(*connection);
        work.exec(query);
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void SubjectRepositoryImplPg::changeSubjectMarks(const int id, const int newMarks)
{
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = SubjectQueryGenerator::getChangeSubjectMarksQuery(id,
                                                                   newMarks);
        pqxx::work work(*connection);
        work.exec(query);
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void SubjectRepositoryImplPg::changeSubjectStudentId(const int id, const int studentId)
{
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = SubjectQueryGenerator::getChangeSubjectStudentIdQuery(id,
                                                                                studentId);
        pqxx::work work(*connection);
        work.exec(query);
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

void SubjectRepositoryImplPg::deleteSubject(const int id)
{
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = SubjectQueryGenerator::getDeleteSubjectQuery(id);
        pqxx::work work(*connection);
        work.exec(query);
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
}

Subject SubjectRepositoryImplPg::getSubject(const std::string &subjectName)
{
    Subject subject;
    try {
        if (!connection->is_open()) {
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

        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return subject;
}

std::vector<Subject> SubjectRepositoryImplPg::getAllSubject()
{
    std::vector<Subject> subjects;
    try {
        if (!connection->is_open()) {
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

        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return subjects;
}

std::vector<Subject> SubjectRepositoryImplPg::getSubjectByStudent(int studentId)
{
    std::vector<Subject> subjects;
    try {
        if (!connection->is_open()) {
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

        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return subjects;
}

int SubjectRepositoryImplPg::getNumberOfRows()
{
    int numberOfRows = 0;
    try {
        if (!connection->is_open()) {
            throw DataSourceAccessException(__FILE__, typeid(*this).name(), __LINE__);
        }
        std::string query = SubjectQueryGenerator::getNumberOfRowsQuery();
        pqxx::work work(*connection);
        pqxx::result result = work.exec(query);
        numberOfRows = result[0][0].as<int>();
        work.commit();
    }  catch (const std::exception & e) {
        cout << e.what() << endl;
    }
    return numberOfRows;
}
