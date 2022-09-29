#include "teststudentrepository.h"

TestStudentRepository::~TestStudentRepository()
{
}

void TestStudentRepository::addStudent(const std::string studentName, const std::string admissionNumber, const int groupId)
{
    int index = students.size() + 1;
    students.push_back(Student(index, studentName, admissionNumber, groupId));
}

void TestStudentRepository::removeStudent(const int id)
{
    int index = -1;
    for (auto & student : students) {
        if (student.getId() == id) {
            index = id;
        }
    }
    if (index != -1) {
        students.erase(students.begin() + index);
    }
}

void TestStudentRepository::changeStudentName(const int id, const std::string newName)
{
    for (auto & student : students) {
        if (student.getId() == id) {
            student.setFullName(newName);
        }
    }
}

Student TestStudentRepository::getStudent(const int id)
{
    Student res;
    for (auto & student : students) {
        if (student.getId() == id) {
            res = student;
        }
    }
    return res;
}

int TestStudentRepository::getStudentGroup(const int id)
{
    Student res;
    for (auto & student : students) {
        if (student.getId() == id) {
            res = student;
        }
    }
    return res.groupId();
}

std::vector<Student> TestStudentRepository::getAllStudents()
{
    return students;
}

TestStudentRepository::TestStudentRepository(const std::vector<Student> &students) : students(students)
{}
