#include "testsubjectrepository.h"

#include <iostream>
TestSubjectRepository::~TestSubjectRepository()
{

}

void TestSubjectRepository::addNewSubject(const std::string subjectName, const int marks, const int studentId)
{
    int id = this->subjects.size() + 1;
    subjects.push_back(Subject(id, subjectName, marks, studentId));
}

void TestSubjectRepository::changeSubjectName(const int id, std::string newSubjectName)
{
    for (auto subject : subjects) {
        if (subject.getId() == id) {
            subject.setSubjectName(newSubjectName);
        }
    }
}

void TestSubjectRepository::deleteSubject(const int id)
{
    int index = -1;
    for (int i = 0; i < (int) subjects.size(); i++) {
        if (subjects[i].getId() == id) {
            index = id;
        }
    }
    if (index != -1) {
        subjects.erase(subjects.begin() + index);
    }
}

std::vector<Subject> TestSubjectRepository::getSubjectByStudent(int studentId)
{
    std::vector<Subject> res;
    for (auto & subject : subjects) {
        if (subject.getStudentId() == studentId) {
            res.push_back(subject);
        }
    }
    return subjects;
}

TestSubjectRepository::TestSubjectRepository(const std::vector<Subject> &subjects) : subjects(subjects)
{}
