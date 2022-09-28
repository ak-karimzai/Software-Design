#ifndef TESTSTUDENTREPOSITORY_H
#define TESTSTUDENTREPOSITORY_H

#include "../repositories/studentrepository.h"

#include <vector>

class TestStudentRepository : public StudentRepository
{
    // StudentRepository interface
public:
    TestStudentRepository(const std::vector<Student> &students);
    ~TestStudentRepository();
    void addStudent(const std::string studentName, const std::string admissionNumber, const int groupId);
    void removeStudent(const int id);
    void changeStudentName(const int id, const std::string newName);
    Student getStudent(const int id);
    int getStudentGroup(const int id);
    std::vector<Student> getAllStudents();
private:
    std::vector<Student> students;
};

#endif // TESTSTUDENTREPOSITORY_H
