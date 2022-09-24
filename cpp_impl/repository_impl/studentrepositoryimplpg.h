#ifndef STUDENTREPOSITORYIMPLPG_H
#define STUDENTREPOSITORYIMPLPG_H

#include "../repositories/studentrepository.h"

class StudentRepositoryImplPg : public StudentRepository
{
    // StudentRepository interface
public:
    void addStudent(const Student &newStudent);
    void addStudent(const std::string studentName, const std::string admissionNumber, const int groupId);
    void addStudent(const int id, const std::string studentName, const std::string admissionNumber, const int groupId);
    void removeStudent(const int id);
    void changeStudentName(int id, const std::string newName);
    Student getStudent(int id);
    std::vector<Student> getAllStudents();
    std::vector<Student> getAllGroupStudents(int groupId);
};

#endif // STUDENTREPOSITORYIMPLPG_H
