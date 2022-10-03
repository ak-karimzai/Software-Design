#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "repository_impl/studentrepositoryimplpg.h"
#include "repository_impl/subjectrepositoryimplpg.h"
#include "repository_impl/teacherrepositoryimplpg.h"
#include "repository_impl/grouprepositoryimplpg.h"
#include "repository_impl/authrepositoryimplpg.h"


#include "controllers/studentcontroller.h"
#include "controllers/subjectconstroller.h"
#include "controllers/groupcontroller.h"
#include "controllers/authcontroller.h"
#include "controllers/teachercontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initComos();
    void deleteStudent(const Student & student);
    void initAdminComos();
    void showError(const std::string & msg);

private slots:
    void showGroups();
    void addNewTeacher();
    void showStudents();
    void showSubjects();
    void removeTeacher();
    void removeStudent();
    void removeGroup();
    void removeSubject();
    void checkLoginAndPassword();
    void addGroup();
    void addSubject();
    void addStudent();
    void studentUI();
    void teacherUI();
    void adminUI();
    void authUI();

private:
    std::shared_ptr<StudentRepository> studentRepository;
    std::shared_ptr<SubjectRepository> subjectRepository;
    std::shared_ptr<GroupRepository> groupRepository;
    std::shared_ptr<TeacherRepository> teacherRepository;
    std::shared_ptr<AuthRepository> authRepositry;

    std::shared_ptr<StudentController> studentController;
    std::shared_ptr<SubjectController> subjectController;
    std::shared_ptr<GroupController> groupController;
    std::shared_ptr<TeacherController> teacherController;
    std::shared_ptr<AuthController> authController;

    std::vector<Teacher> teachers;
    std::vector<Group> groups;
    std::vector<Student> students;
    std::vector<Subject> subjects;

    bool loginAsStudent;
    bool loginAsAdmin;
    Teacher teacher;

private:
    Ui::MainWindow *ui;
    QMessageBox * messageBox;
};
#endif // MAINWINDOW_H
