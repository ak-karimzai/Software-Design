#ifndef TEACHERDISPLAY_H
#define TEACHERDISPLAY_H

#include "display.h"

#include "facades/teacherfacade.h"

class TeacherDisplay : public Display
{
public:
    TeacherDisplay(int teacherId, TeacherFacade *teacherManager);

    void startDisplay();

protected:
    void addNewStudent();
    void removeStudent();
    void addNewGroup();
    void showAllGroups();
    void removeGroup();
    void addSubject();
    void deleteStubject();
    void sortGroupStudentsByAverageMarks();
    void showStudentSubjects();
    void showAllGroupStudent();
    void executeCommand(const int command);

private:
    TeacherFacade * teacherFacade;
    Teacher teacher;
    bool selected;
};

#endif // TEACHERDISPLAY_H
