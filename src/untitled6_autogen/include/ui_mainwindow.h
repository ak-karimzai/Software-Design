/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_teacher;
    QLabel *label_2;
    QPushButton *addStudentButton;
    QPushButton *addGroupButton;
    QComboBox *groupStudents;
    QPushButton *addSubjectButton;
    QPushButton *showSubjects;
    QComboBox *teacherGroups;
    QPushButton *showStudents;
    QLabel *label;
    QTableWidget *resultList;
    QComboBox *teachersList;
    QLabel *label_3;
    QPushButton *showGroups;
    QLabel *label_4;
    QPushButton *removeGroup;
    QPushButton *removeStudent;
    QPushButton *removeSubject;
    QWidget *page_2;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *enterToApp;
    QLineEdit *loginEntry;
    QLineEdit *passwordEntry;
    QWidget *page_3;
    QComboBox *teacherListForAdmin;
    QLabel *label_7;
    QPushButton *addNewTeacher;
    QPushButton *removeTeacher;
    QLineEdit *teacherName;
    QLineEdit *teacherAdmNo;
    QLineEdit *teacherLogin;
    QLineEdit *teacherPass;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *page;
    QPushButton *adminClicked;
    QPushButton *teacherClicked;
    QPushButton *studentClicked;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(585, 546);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, 10, 551, 501));
        page_teacher = new QWidget();
        page_teacher->setObjectName(QString::fromUtf8("page_teacher"));
        label_2 = new QLabel(page_teacher);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 100, 81, 41));
        addStudentButton = new QPushButton(page_teacher);
        addStudentButton->setObjectName(QString::fromUtf8("addStudentButton"));
        addStudentButton->setGeometry(QRect(170, 470, 131, 25));
        addGroupButton = new QPushButton(page_teacher);
        addGroupButton->setObjectName(QString::fromUtf8("addGroupButton"));
        addGroupButton->setGeometry(QRect(10, 470, 121, 25));
        groupStudents = new QComboBox(page_teacher);
        groupStudents->setObjectName(QString::fromUtf8("groupStudents"));
        groupStudents->setGeometry(QRect(80, 110, 321, 25));
        addSubjectButton = new QPushButton(page_teacher);
        addSubjectButton->setObjectName(QString::fromUtf8("addSubjectButton"));
        addSubjectButton->setGeometry(QRect(350, 470, 131, 25));
        showSubjects = new QPushButton(page_teacher);
        showSubjects->setObjectName(QString::fromUtf8("showSubjects"));
        showSubjects->setGeometry(QRect(410, 150, 121, 25));
        teacherGroups = new QComboBox(page_teacher);
        teacherGroups->setObjectName(QString::fromUtf8("teacherGroups"));
        teacherGroups->setGeometry(QRect(80, 70, 321, 25));
        showStudents = new QPushButton(page_teacher);
        showStudents->setObjectName(QString::fromUtf8("showStudents"));
        showStudents->setGeometry(QRect(410, 110, 121, 25));
        label = new QLabel(page_teacher);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 60, 81, 41));
        resultList = new QTableWidget(page_teacher);
        resultList->setObjectName(QString::fromUtf8("resultList"));
        resultList->setGeometry(QRect(80, 150, 321, 281));
        teachersList = new QComboBox(page_teacher);
        teachersList->setObjectName(QString::fromUtf8("teachersList"));
        teachersList->setGeometry(QRect(80, 30, 321, 25));
        label_3 = new QLabel(page_teacher);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 20, 81, 41));
        showGroups = new QPushButton(page_teacher);
        showGroups->setObjectName(QString::fromUtf8("showGroups"));
        showGroups->setGeometry(QRect(410, 70, 121, 25));
        label_4 = new QLabel(page_teacher);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, -10, 261, 31));
        label_4->setTextFormat(Qt::AutoText);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);
        removeGroup = new QPushButton(page_teacher);
        removeGroup->setObjectName(QString::fromUtf8("removeGroup"));
        removeGroup->setGeometry(QRect(10, 440, 121, 25));
        removeStudent = new QPushButton(page_teacher);
        removeStudent->setObjectName(QString::fromUtf8("removeStudent"));
        removeStudent->setGeometry(QRect(170, 440, 131, 25));
        removeSubject = new QPushButton(page_teacher);
        removeSubject->setObjectName(QString::fromUtf8("removeSubject"));
        removeSubject->setGeometry(QRect(350, 440, 131, 25));
        stackedWidget->addWidget(page_teacher);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(150, 120, 67, 17));
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(146, 190, 71, 20));
        enterToApp = new QPushButton(page_2);
        enterToApp->setObjectName(QString::fromUtf8("enterToApp"));
        enterToApp->setGeometry(QRect(190, 270, 221, 41));
        loginEntry = new QLineEdit(page_2);
        loginEntry->setObjectName(QString::fromUtf8("loginEntry"));
        loginEntry->setGeometry(QRect(240, 104, 191, 51));
        passwordEntry = new QLineEdit(page_2);
        passwordEntry->setObjectName(QString::fromUtf8("passwordEntry"));
        passwordEntry->setGeometry(QRect(240, 170, 191, 51));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        teacherListForAdmin = new QComboBox(page_3);
        teacherListForAdmin->setObjectName(QString::fromUtf8("teacherListForAdmin"));
        teacherListForAdmin->setGeometry(QRect(190, 70, 301, 25));
        label_7 = new QLabel(page_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(70, 70, 67, 17));
        addNewTeacher = new QPushButton(page_3);
        addNewTeacher->setObjectName(QString::fromUtf8("addNewTeacher"));
        addNewTeacher->setGeometry(QRect(180, 450, 211, 25));
        removeTeacher = new QPushButton(page_3);
        removeTeacher->setObjectName(QString::fromUtf8("removeTeacher"));
        removeTeacher->setGeometry(QRect(190, 110, 211, 25));
        teacherName = new QLineEdit(page_3);
        teacherName->setObjectName(QString::fromUtf8("teacherName"));
        teacherName->setGeometry(QRect(180, 200, 211, 41));
        teacherAdmNo = new QLineEdit(page_3);
        teacherAdmNo->setObjectName(QString::fromUtf8("teacherAdmNo"));
        teacherAdmNo->setGeometry(QRect(180, 270, 211, 41));
        teacherLogin = new QLineEdit(page_3);
        teacherLogin->setObjectName(QString::fromUtf8("teacherLogin"));
        teacherLogin->setGeometry(QRect(180, 340, 211, 41));
        teacherPass = new QLineEdit(page_3);
        teacherPass->setObjectName(QString::fromUtf8("teacherPass"));
        teacherPass->setGeometry(QRect(180, 400, 211, 41));
        label_8 = new QLabel(page_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 210, 131, 20));
        label_9 = new QLabel(page_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(40, 280, 131, 20));
        label_10 = new QLabel(page_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(40, 350, 131, 20));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(page_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(40, 410, 131, 20));
        label_11->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_3);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        adminClicked = new QPushButton(page);
        adminClicked->setObjectName(QString::fromUtf8("adminClicked"));
        adminClicked->setGeometry(QRect(130, 110, 301, 31));
        teacherClicked = new QPushButton(page);
        teacherClicked->setObjectName(QString::fromUtf8("teacherClicked"));
        teacherClicked->setGeometry(QRect(130, 160, 301, 31));
        studentClicked = new QPushButton(page);
        studentClicked->setObjectName(QString::fromUtf8("studentClicked"));
        studentClicked->setGeometry(QRect(130, 220, 301, 31));
        stackedWidget->addWidget(page);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 585, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Result Sheet", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Students", nullptr));
        addStudentButton->setText(QCoreApplication::translate("MainWindow", "Add new Student", nullptr));
        addGroupButton->setText(QCoreApplication::translate("MainWindow", "Add new Group", nullptr));
        addSubjectButton->setText(QCoreApplication::translate("MainWindow", "Add new Subject", nullptr));
        showSubjects->setText(QCoreApplication::translate("MainWindow", "Show Subjects", nullptr));
        showStudents->setText(QCoreApplication::translate("MainWindow", "Show Students", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Groups", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "teacher", nullptr));
        showGroups->setText(QCoreApplication::translate("MainWindow", "Show Groups", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Result Sheet", nullptr));
        removeGroup->setText(QCoreApplication::translate("MainWindow", "Remove Group", nullptr));
        removeStudent->setText(QCoreApplication::translate("MainWindow", "Remove Student", nullptr));
        removeSubject->setText(QCoreApplication::translate("MainWindow", "Remove Subject", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "login", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "password", nullptr));
        enterToApp->setText(QCoreApplication::translate("MainWindow", "enter", nullptr));
        loginEntry->setInputMask(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "Teachers", nullptr));
        addNewTeacher->setText(QCoreApplication::translate("MainWindow", "Add new teacher", nullptr));
        removeTeacher->setText(QCoreApplication::translate("MainWindow", "Remove Teacher", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Teacher full name", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Teacher Reg No:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        adminClicked->setText(QCoreApplication::translate("MainWindow", "Login As Administrator", nullptr));
        teacherClicked->setText(QCoreApplication::translate("MainWindow", "Login As Teacher", nullptr));
        studentClicked->setText(QCoreApplication::translate("MainWindow", "Continue As Student", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
