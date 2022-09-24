#ifndef STUDENTCONTROLLER_H
#define STUDENTCONTROLLER_H

#include "../repositories/studentrepository.h"

#include <string>
#include <vector>

class StudentController
{
public:
    StudentController(StudentRepository * studentRepository);
    ~StudentController();

    void addStudent(const std::string studentFullName,
                    const std::string studentAdmissionNumber,
                    const int studentGroupId);

    Student getStudentById(const int id);
    int getStudentGroup(const int id);
    std::vector<Student> getAllStudents();
    std::vector<Student> getAllStudentsByGroupId(const int id);
    void changeStudentName(const int id, const std::string newStudentName);
    void changeStudentGroup(const int id, const int newGroupId);
    void deleteStudent(const int id);
private:
    StudentRepository *studentRepository;
};

#endif // STUDENTCONTROLLER_H
