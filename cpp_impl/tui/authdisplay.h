#ifndef AUTHDISPLAY_H
#define AUTHDISPLAY_H

#include "display.h"

#include "teacherdisplay.h"
#include "studentdisplay.h"
#include "admindisplay.h"

#include "facades/authfacade.h"
#include "facades/studentfacade.h"
#include "facades/teacherfacade.h"

class AuthDisplay : public Display
{
public:
    AuthDisplay(AuthFacade &authFacade, StudentFacade &studentFacade, TeacherFacade &teacherFacade);

    void startDisplay() override;

protected:
    void exectueCommand(const int command);
    void loginAsAdminstrator();
    void loginAsTeacher();
    void loginAsStudnet();
private:
    AuthFacade & authFacade;
    StudentFacade & studentFacade;
    TeacherFacade & teacherFacade;
};

#endif // AUTHDISPLAY_H
