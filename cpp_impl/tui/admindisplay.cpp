#include "admindisplay.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const std::string MENU_COMMANDS = "\n\n\
0. exit\n\
1. Add new teacher.\n\
2. all teacher list.\n\
3. remove teacher.\n\
->";

AdminDisplay::AdminDisplay(TeacherFacade &teacherFacade, AuthFacade &authFacade) : teacherFacade(teacherFacade),
    authFacade(authFacade)
{}

void AdminDisplay::startDisplay()
{
    int choice;
    do {
        cout << MENU_COMMANDS;
        cin >> choice;
        executeCommand(choice);
    } while (choice != 0);
}

void AdminDisplay::addNewTeacher()
{
    std::string teacherName, teacherRegestrationNumber;
    std::string login, password;

    cout << "Enter teacher full name: ";
    std::getline(cin, teacherName);
    std::getline(cin, teacherName);

    cout << "Enter teacher regestration number: ";
    std::getline(cin, teacherRegestrationNumber);

    cout << "Enter teacher login: ";
    std::getline(cin, login);

    cout << "Enter teacher password: ";
    std::getline(cin, password);

    try {
        teacherFacade.addNewTeacher(teacherName, teacherRegestrationNumber);
        Teacher teacher = teacherFacade.getTeacher(teacherRegestrationNumber);
        cout << teacher << endl;
//        authFacade.registerNewUser(login, password, teacher.getId());
    }  catch (std::exception & e) {
        cout << e.what() << endl;
    }
}

void AdminDisplay::displayTeacherList()
{
    auto teachers = teacherFacade.getTeachers();
    for (const auto & teacher : teachers) {
        cout << teacher << endl;
    }
}

void AdminDisplay::removeTeacher()
{
    int teacherId;
    cout << "Enter teacher id: ";
    cin >> teacherId;

    try {
        authFacade.deleteUserLoginByTeacherId(teacherId);
        teacherFacade.deleteTeacher(teacherId);
    }  catch (std::exception & e) {
        cout << e.what() << endl;
    }
}

void AdminDisplay::executeCommand(const int command)
{
    if (command == 1) {
        addNewTeacher();
    } else if (command == 2) {
        displayTeacherList();
    } else if (command == 3) {
        removeTeacher();
    }
}
