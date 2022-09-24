#include "studentcontroller.h"

StudentController::~StudentController()
{

}

void StudentController::addStudent(const std::string studentFullName, const std::string studentAdmissionNumber, const int studentGroupId)
{
    this->studentRepository->addStudent(studentFullName, studentAdmissionNumber, studentGroupId);
}

Student StudentController::getStudentById(const int id)
{
    return this->studentRepository->getStudent(id);
}

int StudentController::getStudentGroup(const int id)
{
    return this->studentRepository->getStudentGroup(id);
}

std::vector<Student> StudentController::getAllStudents()
{
    return this->studentRepository->getAllStudents();
}

std::vector<Student> StudentController::getAllStudentsByGroupId(const int id)
{
    return this->studentRepository->getAllGroupStudents(id);
}

void StudentController::changeStudentName(const int id, const std::string newStudentName)
{
    this->studentRepository->changeStudentName(id, newStudentName);
}

void StudentController::changeStudentGroup(const int id, const int newGroupId)
{
    this->studentRepository->changeStudentGroup(id, newGroupId);
}

void StudentController::deleteStudent(const int id)
{
    this->studentRepository->removeStudent(id);
}

StudentController::StudentController(StudentRepository *studentRepository) : studentRepository(studentRepository)
{}
