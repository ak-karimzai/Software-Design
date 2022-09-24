#include "testteacherrepository.h"

void TestTeacherRepository::addNewTeacher(const std::string teacherFullName, const std::string teacherRegestrationNumber)
{
    int numberOfTeachers = this->teachers.size();
    this->teachers.push_back(Teacher(numberOfTeachers + 1, teacherFullName, teacherRegestrationNumber));
}

void TestTeacherRepository::deleteTeacher(const int id)
{
    int indx = -1;
    for (int i = 0; i < (int) this->teachers.size(); i++) {
        if (this->teachers[i].getId() == id) {
            indx = id;
        }
    }
    if (indx != -1) {
        this->teachers.erase(this->teachers.begin() + indx);
    }
}

void TestTeacherRepository::renameTeacher(int id, std::string newName)
{
    for (auto & teacher : this->teachers) {
        if (teacher.getId() == id) {
            teacher.setFullName(newName);
        }
    }
}

std::vector<Teacher> TestTeacherRepository::getAllTeachers()
{
    return this->teachers;
}

TestTeacherRepository::TestTeacherRepository(const std::vector<Teacher> &teachers) : teachers(teachers)
{}

TestTeacherRepository::~TestTeacherRepository()
{

}
