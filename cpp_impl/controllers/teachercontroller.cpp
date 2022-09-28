#include "teachercontroller.h"

TeacherController::TeacherController(TeacherRepository *teacherRepository)
{
    this->teacherRepository = teacherRepository;
}

TeacherController::~TeacherController()
{

}

void TeacherController::addNewTeacher(std::string teacherName, std::string teacherRegesteationNumber)
{
    this->teacherRepository->addNewTeacher(teacherName, teacherRegesteationNumber);
}

std::vector<Teacher> TeacherController::getAllTeachers()
{
    return this->teacherRepository->getAllTeachers();
}

Teacher TeacherController::getTeacherByName(const std::string &teacherName)
{
    return this->teacherRepository->getTeacher(teacherName);
}

Teacher TeacherController::getTeacherById(const int teacherId)
{
    return this->teacherRepository->getTeacher(teacherId);
}

Teacher TeacherController::getTeacherByRegNumber(const std::string &teacherRegNum)
{
    return this->teacherRepository->getTeacherByRegNum(teacherRegNum);
}

void TeacherController::deleteTeacher(const int id)
{
    this->teacherRepository->deleteTeacher(id);
}

void TeacherController::changeTeacherName(const int id, std::string newTeacherName)
{
    this->teacherRepository->renameTeacher(id, newTeacherName);
}

void TeacherController::changeTeacherRegestrationNumber(const int id, std::string newRegestrationNumber)
{
    this->teacherRepository->changeTeacherRegestrationNumber(id, newRegestrationNumber);
}
