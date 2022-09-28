#include "studentdisplay.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const std::string MENU_COMMANDS = "\n\n\
0. exit\n\
1. display all gorups\n\
2. display student subjects\n\
3. display group students\n\
4. display group students sorted by marks\n\
->";

StudentDisplay::StudentDisplay(StudentFacade &studentFacade) : studentFacade(studentFacade)
{}

void StudentDisplay::displayAllGroups()
{
    try {
        cout << "Group lists: ";
        auto groups = studentFacade.getAllGroupsList();
        for (const auto & group : groups) {
            cout << group << endl;
        }
    }  catch (std::exception e) {
        cout << e.what() << endl;
    }
}

void StudentDisplay::displayStudentSubjects()
{
    int studentId;
    try {
        cout << "Enter the student id: ";
        cin >> studentId;
        cout << "student " << studentId << " subjects: " << endl;
        auto subjects = studentFacade.getStudentSubjects(studentId);
        for (const auto & subject : subjects) {
            cout << subject << endl;
        }
    }  catch (std::exception e) {
        cout << e.what() << endl;
    }
}

void StudentDisplay::displayGroupStudents()
{
    int groupId;
    try {
        cout << "Enter the group id: ";
        cin >> groupId;
        cout << "group " << groupId << " students: " << endl;
        auto subjects = studentFacade.getStudentSubjects(groupId);
        for (const auto & subject : subjects) {
            cout << subject << endl;
        }
    }  catch (std::exception e) {
        cout << e.what() << endl;
    }
}

void StudentDisplay::displayStudentGroupByMarks()
{
    int groupId;
    try {
        cout << "Enter the group id: ";
        cin >> groupId;
        cout << "group " << groupId << " students: " << endl;
        auto subjects = studentFacade.getGroupStudentsSortedByAverageMarks(groupId);
        for (const auto & subject : subjects) {
            cout << subject << endl;
        }
    }  catch (std::exception e) {
        cout << e.what() << endl;
    }
}

void StudentDisplay::startDisplay()
{
    int choice;
    do {
        cout << MENU_COMMANDS;
        cin >> choice;
        execute(choice);
    } while (choice != 0);
}

void StudentDisplay::execute(const int command)
{
    if (command == 1) {
        displayAllGroups();
    } else if (command == 2) {
        displayStudentSubjects();
    } else if (command == 3) {
        displayGroupStudents();
    } else if (command == 4) {
        displayStudentGroupByMarks();
    }
}

//1. display all gorups\n\
//2. display student subjects\n\
//3. display group students\n\
//4. display group students sorted by marks\n\
//->";
