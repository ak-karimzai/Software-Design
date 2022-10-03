#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "inputdialog.h"
#include "studentdialog.h"

#include <QMenuBar>

const std::string conn = std::string("dbname = school ") +
                         std::string("user = khalid ") +
                         std::string("password = 1234abcd ") +
                         std::string("hostaddr = 127.0.0.1 ") +
                         std::string("port = 5432");

const std::string adminPass = "khalid";
const std::string adminLogin = "khalid";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    messageBox = new QMessageBox(this);

    ui->stackedWidget->setCurrentIndex(3);

    studentRepository = std::shared_ptr<StudentRepository>(new StudentRepositoryImplPg(conn));
    subjectRepository = std::shared_ptr<SubjectRepository>(new SubjectRepositoryImplPg(conn));
    groupRepository = std::shared_ptr<GroupRepository>(new GroupRepositoryImplPg(conn));
    teacherRepository = std::shared_ptr<TeacherRepository>(new TeacherRepositoryImplPg(conn));
    authRepositry = std::shared_ptr<AuthRepository>(new AuthRepositoryImplPg(conn));

    studentController = std::shared_ptr<StudentController>(new StudentController(studentRepository.get()));
    subjectController = std::shared_ptr<SubjectController>(new SubjectController(subjectRepository.get()));
    groupController = std::shared_ptr<GroupController>(new GroupController(groupRepository.get()));
    teacherController = std::shared_ptr<TeacherController>(new TeacherController(teacherRepository.get()));
    authController = std::shared_ptr<AuthController>(new AuthController(authRepositry.get()));

    loginAsStudent = false;
    loginAsAdmin = false;

    connect(ui->showGroups, SIGNAL(clicked()), this, SLOT(showGroups()));
    connect(ui->showStudents, SIGNAL(clicked()), this, SLOT(showStudents()));
    connect(ui->showSubjects, SIGNAL(clicked()), this, SLOT(showSubjects()));
    connect(ui->addGroupButton, SIGNAL(clicked()), this, SLOT(addGroup()));
    connect(ui->addStudentButton, SIGNAL(clicked()), this, SLOT(addStudent()));
    connect(ui->addSubjectButton, SIGNAL(clicked()), this, SLOT(addSubject()));
    connect(ui->adminClicked, SIGNAL(clicked()), this, SLOT(authUI()));
    connect(ui->studentClicked, SIGNAL(clicked()), this, SLOT(studentUI()));
    connect(ui->teacherClicked, SIGNAL(clicked()), this, SLOT(authUI()));
    connect(ui->enterToApp, SIGNAL(clicked()), this, SLOT(checkLoginAndPassword()));
    connect(ui->addNewTeacher, SIGNAL(clicked()), this, SLOT(addNewTeacher()));
    connect(ui->removeTeacher, SIGNAL(clicked()), this, SLOT(removeTeacher()));
    connect(ui->removeStudent, SIGNAL(clicked()), this, SLOT(removeStudent()));
    connect(ui->removeGroup, SIGNAL(clicked()), this, SLOT(removeGroup()));
    connect(ui->removeSubject, SIGNAL(clicked()), this, SLOT(removeSubject()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initComos()
{
    if (loginAsStudent) {
        teachers = teacherController->getAllTeachers();
    }
    for (const auto & teacher : teachers) {
        ui->teachersList->addItem(QString::fromStdString(teacher.getFullName()));
    }
}

void MainWindow::deleteStudent(const Student & student)
{
    const auto subjects = subjectController->getAllSubjectByStudentId(student.getId());
    for (const auto & subject : subjects) {
        subjectController->deleteSubject(subject.getId());
    }
    studentController->deleteStudent(student.getId());
}

void MainWindow::initAdminComos()
{
    ui->teacherListForAdmin->clear();
    teachers = teacherController->getAllTeachers();
    for (const auto & teacher : teachers) {
        ui->teacherListForAdmin->addItem(QString::fromStdString(teacher.getFullName()));
    }
}

void MainWindow::showError(const std::string &msg)
{
    std::cout << msg << std::endl;
    messageBox->setText(QString::fromStdString(msg));
    messageBox->setFixedSize(500,200);
    messageBox->setWindowIconText("Error");
    messageBox->show();
}

void MainWindow::showGroups()
{
    ui->teacherGroups->clear();
    int idx = ui->teachersList->currentIndex();
    if (idx >= 0 && teachers.size()) {
        try {
            groups =  groupController->getAllGroupsByTeacherId(teachers[idx].getId());
        }  catch (std::exception & e) {
            showError("An error with fetching data from database!");
        }
        for (const auto & group : groups) {
            ui->teacherGroups->addItem(QString::fromStdString(group.getName()));
        }
    }
}

void MainWindow::addNewTeacher()
{
    std::string teacherFullName = ui->teacherName->text().toStdString();
    std::string teacherRegNo = ui->teacherAdmNo->text().toStdString();
    std::string teacherLogin = ui->teacherLogin->text().toStdString();
    std::string teacherPass = ui->teacherPass->text().toStdString();

    if (teacherFullName == "" || teacherRegNo == "" ||
            teacherLogin == "" || teacherPass == "") {
        showError("You must fill all items for new regestration!");
        return;
    }
    try {
        teacherController->addNewTeacher(teacherFullName, teacherRegNo);

        auto tempTeacher = teacherController->getTeacherByRegNumber(teacherRegNo);
        if (tempTeacher.getRegisterNumber() == teacherRegNo) {
            std::cout << tempTeacher.getId() << std::endl;
            authController->addNewUser(teacherLogin, teacherPass, tempTeacher.getId());
        } else {
            showError("Error in regestration!");
        }
    }  catch (std::exception & e) {
        showError("Error on insert and update data source!");
    }
    initAdminComos();
}

void MainWindow::showStudents()
{
    ui->groupStudents->clear();
    try {
        int idx = ui->teacherGroups->currentIndex();
        if ((idx >= 0) && groups.size()) {
            students = studentController->getAllStudentsByGroupId(groups[idx].getId());
            for (const auto & student : students) {
                ui->groupStudents->addItem(QString::fromStdString(student.fullName()));
            }
        }
    }  catch (std::exception & e) {
        showError("Error on fetching data from data source!");
    }
}

void MainWindow::showSubjects()
{
    ui->resultList->clear();
    int idx = ui->groupStudents->currentIndex();
    if (idx >= 0 && students.size()) {
        Student sdt;
        try {
            sdt = students[idx];
            subjects = subjectController->getAllSubjectByStudentId(sdt.getId());
        } catch (std::exception & e) {
            showError("Error on fetching data from data source!");
        }
        ui->resultList->setColumnCount(3);
        ui->resultList->setRowCount(subjects.size() + 1);
        ui->resultList->setHorizontalHeaderItem(0, new QTableWidgetItem("Subject Name"));
        ui->resultList->setHorizontalHeaderItem(1, new QTableWidgetItem("Marks"));
        ui->resultList->setHorizontalHeaderItem(2, new QTableWidgetItem("Student Name"));
        int i, sum;
        i = sum = 0;
        for (const auto & subject : subjects) {
            ui->resultList->setItem(i, 0, new QTableWidgetItem(
                                        QString::fromStdString(subject.getSubjectName())));
            ui->resultList->setItem(i, 1, new QTableWidgetItem(
                                        QString::fromStdString(std::to_string(subject.getMarks()))));
            ui->resultList->setItem(i, 2, new QTableWidgetItem(
                                        QString::fromStdString(sdt.fullName())));
            sum += subject.getMarks();
            i++;
        }
        auto average = (int)(sum / (double) i * 100 + .5);
        average /= 100;
        ui->resultList->setItem(i, 1, new QTableWidgetItem(
                                    QString::fromStdString("sum = " + std::to_string(sum))));
        ui->resultList->setItem(i, 2, new QTableWidgetItem(
                                    QString::fromStdString("average = " + std::to_string(average))));
    }
}

void MainWindow::removeTeacher()
{
    int idx = ui->teacherListForAdmin->currentIndex();
    if (idx >= 0) {
        try {
            auto & teacher = teachers[idx];
            authController->deleteUserDetailsByTeacherId(teacher.getId());
            teacherController->deleteTeacher(teacher.getId());
        } catch (std::exception & e) {
            showError("Error on deleting data from data source!");
        }
    }
    initAdminComos();
}

void MainWindow::removeStudent()
{
    if (ui->groupStudents->currentText() == "") {
        return;
    }
    int idx = ui->groupStudents->currentIndex();
    const Student & student = students[idx];
    try {
        deleteStudent(student);
    } catch (std::exception & e) {
        showError("Error on deleting data from data source!");
    }
    showStudents();
}

void MainWindow::removeGroup()
{
    if (ui->teacherGroups->currentText() == "") {
        return;
    }
    int idx = ui->teacherGroups->currentIndex();
    const Group & group = groups[idx];
    try {
        auto students = studentController->getAllStudentsByGroupId(group.getId());
        for (const auto & student : students) {
            deleteStudent(student);
        }
        groupController->deleteGroup(group.getId());
    } catch (std::exception & e) {
        showError("Error on deleting data from data source!");
    }
    showGroups();
}

void MainWindow::removeSubject()
{
    if (ui->resultList->size().height() == 1) {
        return;
    }
    int idx = ui->resultList->currentRow();
    if (idx < 0 || idx >= subjects.size())
        return;
    const auto subject = subjects[idx];
    subjectController->deleteSubject(subject.getId());
    showSubjects();
}

void MainWindow::checkLoginAndPassword()
{
    std::string login = ui->loginEntry->text().toStdString();
    std::string password = ui->passwordEntry->text().toStdString();

    if (loginAsAdmin) {
        if (login == adminLogin &&
                password == adminPass) {
            adminUI();
        } else {
            showError("Incorect login or password!");
        }
    } else {
        std::vector<Auth> users;
        try {
            users = authController->getUsers();
        } catch (std::exception & e) {
            showError("Error on fetching data!");
        }
        int teacherId = -1;
        for (const auto & user : users) {
            if (user.getLogin() == login &&
                    user.getPassword() == password) {
                teacherId = user.getTeacherId();
                break;
            }
        }
        if (teacherId != -1) {
            teachers.clear();
            teachers.push_back(teacherController->getTeacherById(teacherId));
            teacherUI();
        } else {
            showError("Incorect login or password!");
        }
    }
}

void MainWindow::addGroup()
{
    bool ok;
    std::string name = QInputDialog::getText(0, "Input dialog",
                                             "Group Name:", QLineEdit::Normal,
                                             "", &ok).toStdString();
    if (name == "")
        showError("Incorect input!");
    else {
        try {
            groupController->addGroup(name, teachers[0].getId());
        } catch (std::exception & e) {
            showError("Error on updating data source!");
        }
    }
    showGroups();
}

void MainWindow::addSubject()
{
    if (ui->groupStudents->currentText() == "")
        return;
    auto subjectDetails = SubjectDialog::getSubjectDetails(this);
    if (subjectDetails.size() == 0) {
        return;
    }
    try {
       int studentIdx = ui->groupStudents->currentIndex();
       const Student sdt = students[studentIdx];
       std::string subjectName = subjectDetails[0].toStdString();
       int subjectMarks = subjectDetails[1].toInt();
       if (subjectName == "" || (subjectMarks <= 0 || subjectMarks > 100)) {
           showError("check subject input details!");
           return;
       }
       subjectController->addNewSubject(subjectDetails[0].toStdString(), subjectDetails[1].toInt(), sdt.getId());
    }  catch (std::exception & e) {
        showError("Error on updating data source :(");
    }
    showSubjects();
}

void MainWindow::addStudent()
{
    if (ui->teacherGroups->currentText() == "")
        return;

    auto studentDetails = StudentDialog::getStudentDetails(this);
    if (studentDetails.size() == 0) {
        return;
    }

    try {
        int groupIdx = ui->teacherGroups->currentIndex();
        const Group &group = groups[groupIdx];
        std::string studentFullName = studentDetails[0].toStdString();
        std::string studentAdmNo = studentDetails[1].toStdString();
        if (studentFullName == "" || studentAdmNo == "") {
            showError("Student filed must not empty!");
            return;
        }
        studentController->addStudent(studentFullName, studentAdmNo, group.getId());
    }  catch (std::exception & e) {
        showError("Error on inserting new student :( check regestration number!");
    }
    showStudents();
}

void MainWindow::studentUI()
{
    loginAsStudent = true;
    initComos();
    ui->addGroupButton->setDisabled(true);
    ui->addStudentButton->setDisabled(true);
    ui->addSubjectButton->setDisabled(true);
    ui->removeGroup->setDisabled(true);
    ui->removeStudent->setDisabled(true);
    ui->removeSubject->setDisabled(true);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::teacherUI()
{
    initComos();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::adminUI()
{
    ui->stackedWidget->setCurrentIndex(2);
    initAdminComos();
}

void MainWindow::authUI()
{
    QPushButton * senderButton = qobject_cast<QPushButton*>(sender());
    if (senderButton == ui->adminClicked) {
        loginAsAdmin = true;
    }
    initAdminComos();
    ui->stackedWidget->setCurrentIndex(1);
}
