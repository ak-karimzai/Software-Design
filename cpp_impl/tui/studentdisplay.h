#ifndef STUDENTDISPLAY_H
#define STUDENTDISPLAY_H

#include "facades/studentfacade.h"
#include "display.h"

class StudentDisplay : public Display
{
public:
    StudentDisplay(StudentFacade &studentFacade);

    void displayAllGroups();
    void displayStudentSubjects();
    void displayGroupStudents();
    void displayStudentGroupByMarks();
    void startDisplay();

protected:
    void execute(const int command);

private:
    StudentFacade & studentFacade;
};

#endif // STUDENTDISPLAY_H
