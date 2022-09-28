#ifndef ADMINDISPLAY_H
#define ADMINDISPLAY_H

#include "display.h"

#include "facades/teacherfacade.h"
#include "facades/authfacade.h"

class AdminDisplay : public Display
{
public:
    AdminDisplay(TeacherFacade &teacherFacade, AuthFacade &authFacade);

    void startDisplay() override;

protected:
    void addNewTeacher();
    void displayTeacherList();
    void removeTeacher();
    void executeCommand(const int command);
private:
    TeacherFacade & teacherFacade;
    AuthFacade & authFacade;
};

#endif // ADMINDISPLAY_H
