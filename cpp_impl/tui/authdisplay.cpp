#include "authdisplay.h"

#include <iostream>
#include <memory>

using std::cout;
using std::cin;
using std::endl;

const std::string MENU_COMMANDS = "\n\n\
0. exit\n\
1. Login as administrator.\n\
2. Login as Teacher.\n\
3. continue as student.\n\
->";

AuthDisplay::AuthDisplay(AuthFacade &authFacade, StudentFacade &studentFacade, TeacherFacade &teacherFacade) : authFacade(authFacade),
    studentFacade(studentFacade),
    teacherFacade(teacherFacade)
{}

void AuthDisplay::startDisplay()
{
    int choice;
    do {
        cout << MENU_COMMANDS;
        cin >> choice;
        exectueCommand(choice);
    } while (choice != 0);
}

void AuthDisplay::exectueCommand(const int command)
{
    if (command == 1) {
        loginAsAdminstrator();
    } else if (command == 2) {
        loginAsTeacher();
    } else if (command == 3) {
        loginAsStudnet();
    }
}

void AuthDisplay::loginAsAdminstrator()
{
    std::string login, password;
    cout << "Enter login: ";
    getline(cin, login);
    getline(cin, login);

    cout << "Enter password: ";
    getline(cin, password);

    if (!authFacade.isAuthorizedAsAdmin(login, password)) {
        cout << "incorect login or password, try again!";
        return;
    }

    AdminDisplay adminDisplay(teacherFacade, authFacade);
    adminDisplay.startDisplay();
}

void AuthDisplay::loginAsTeacher()
{
    std::string login, password;
    cout << "Enter login: ";
    getline(cin, login);
    getline(cin, login);

    cout << "Enter password: ";
    getline(cin, password);

    int teacherId = authFacade.getTeacherId(login, password);
    if (teacherId <= 0) {
        cout << "Incorect login or password, try again!";
        return;
    }
    TeacherDisplay teacherDisplay(teacherId, &teacherFacade);
    teacherDisplay.startDisplay();
}

void AuthDisplay::loginAsStudnet()
{
    StudentDisplay studentDisplay(studentFacade);
    studentDisplay.startDisplay();
}
