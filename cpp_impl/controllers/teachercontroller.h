#ifndef TEACHERCONTROLLER_H
#define TEACHERCONTROLLER_H

#include "../repositories/teacherrepository.h"

#include <string>
#include <vector>

class TeacherController
{
public:
    TeacherController(TeacherRepository * teacherRepository);
    ~TeacherController();

    void addNewTeacher(std::string teacherName,
                       std::string teacherRegesteationNumber);
    std::vector<Teacher> getAllTeachers();
    Teacher getTeacherByName(const std::string & teacherName);
    Teacher getTeacherById(const int teacherId);
    Teacher getTeacherByRegNumber(const std::string & teacherRegNum);
    void deleteTeacher(const int id);
    void changeTeacherName(const int id,
                           std::string newTeacherName);
    void changeTeacherRegestrationNumber(const int id,
                                         std::string newRegestrationNumber);
private:
    TeacherRepository * teacherRepository;
};

#endif // TEACHERCONTROLLER_H
