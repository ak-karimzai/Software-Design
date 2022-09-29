#include "teacherdisplay.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const std::string MENU_COMMANDS = "\n\n\
0. exit\n\
1. Add new student\n\
2. remove student\n\
3. create new group\n\
4. delete group\n\
5. display all groups\n\
6. add subject\n\
7. delete subject\n\
8. sort group students by average marks\n\
9. display student subjects\n\
10. display group students\n\
->";

TeacherDisplay::TeacherDisplay(int teacherId, TeacherFacade *teacherManager) : teacherFacade(teacherManager)
{
    teacher = teacherManager->getTeacher(teacherId);
    if (teacher.getId() == teacherId) {
        selected = true;
    } else {
        selected = false;
    }
}

void TeacherDisplay::addNewStudent()
{
    std::string name, admissionNumber;
    int groupId;
    cout << "Enter student full name: ";
    std::getline(cin, name);
    std::getline(cin, name);

    cout << "Enter student admission number: ";
    std::getline(cin, admissionNumber);

    cout << "Enter group id: ";
    cin >> groupId;

    try {
        teacherFacade->addNewStudent(name, admissionNumber, groupId);
    }  catch (std::exception & e) {
        cout << e.what() << endl;
    }
}

void TeacherDisplay::removeStudent()
{
    int id;
    cout << "Enter student id: ";
    cin >> id;
    try {
        teacherFacade->removeStudent(id);
    }  catch (std::exception & e) {
        cout << e.what() << endl;
    }
}

void TeacherDisplay::addNewGroup()
{
    std::string groupName;

    cout << "Enter group name: ";
    std::getline(cin, groupName);
    std::getline(cin, groupName);

    try {
        teacherFacade->createNewGroup(groupName, teacher.getId());
    } catch (std::exception & e) {
        cout << e.what() << endl;
    }
}

void TeacherDisplay::showAllGroups()
{
    try {
        auto groups = teacherFacade->getTeacherGroups(teacher.getId());
        for (const auto & group : groups) {
            cout << group << endl;
        }
    }  catch (std::exception & e) {
        cout << e.what() << endl;
    }
}

void TeacherDisplay::removeGroup()
{
    int groupId;
    cout << "Enter group id: " << endl;
    cin >> groupId;
    try {
        auto groups = teacherFacade->getTeacherGroups(teacher.getId());
        for (const auto & group : groups) {
            if (group.getId() == groupId) {
                teacherFacade->removeGroup(groupId);
                break;
            }
        }
    }  catch (std::exception & e) {
        cout << e.what() << endl;
    }
}

void TeacherDisplay::addSubject()
{
    std::string subjectName;
    int marks, studentId;

    cout << "Enter subject name: ";
    std::getline(cin, subjectName);
    std::getline(cin, subjectName);

    cout << "Enter subject marks: ";
    cin >> marks;

    cout << "Enter subject student id: ";
    cin >> studentId;

    try {
        teacherFacade->addNewSubject(subjectName, marks, studentId);
    }  catch (std::exception & e) {
        cout << e.what() << endl;
    }
}

void TeacherDisplay::deleteStubject()
{
    int subjectId;
    cout << "Enter subject id: ";
    cin >> subjectId;

    try {
        teacherFacade->deleteSubject(subjectId);
    } catch (std::exception & e) {
        cout << e.what() << endl;
    }
}

void TeacherDisplay::sortGroupStudentsByAverageMarks()
{
    int groupId;
    cout << "Enter group id: ";
    cin >> groupId;

    try {
        auto groups = teacherFacade->getGroupStudentsSortedByAverageMarks(groupId);
        for (const auto & group : groups) {
            cout << group << endl;
        }
    }  catch (std::exception & e) {
        cout << e.what() << endl;
    }
}

void TeacherDisplay::showStudentSubjects()
{
    int studentId;
    cout << "Enter student id: ";
    cin >> studentId;

    try {
        auto subjects = teacherFacade->getStudentSubjects(studentId);
        for (const auto & subject : subjects) {
            cout << subject << endl;
        }
    }  catch (std::exception & e) {
        cout << e.what() << endl;
    }
}

void TeacherDisplay::showAllGroupStudent()
{
    int groupId;
    cout << "Enter group id: ";
    cin >> groupId;
    try {
        auto students = teacherFacade->getGroupStudents(groupId);
        for (const auto & student : students) {
            cout << student << endl;
        }
    }  catch (std::exception & e) {
        cout << e.what() << endl;
    }
}

void TeacherDisplay::executeCommand(const int command)
{
    if (command == 1) {
        addNewStudent();
    } else if (command == 2) {
        removeStudent();
    } else if (command == 3) {
        addNewGroup();
    } else if (command == 4) {
        removeGroup();
    } else if (command == 5) {
        showAllGroups();
    } else if (command == 6) {
        addSubject();
    } else if (command == 7) {
        deleteStubject();
    } else if (command == 8) {
        sortGroupStudentsByAverageMarks();
    } else if (command == 9) {
        showStudentSubjects();
    } else if (command == 10) {
        showAllGroupStudent();
    }
}

void TeacherDisplay::startDisplay()
{
    int choice;

    do {
        cout << MENU_COMMANDS;
        cin >> choice;
        executeCommand(choice);
    } while (choice != 0);
}

