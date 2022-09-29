#include "repository_impl/studentrepositoryimplpg.h"
#include "repository_impl/subjectrepositoryimplpg.h"
#include "repository_impl/teacherrepositoryimplpg.h"
#include "repository_impl/grouprepositoryimplpg.h"
#include "repository_impl/authrepositoryimplpg.h"

#include "repository_impl/studentrepositoryimplmysql.h"
#include "repository_impl/subjectrepositoryimplmysql.h"
#include "repository_impl/teacherrepositoryimplmysql.h"
#include "repository_impl/grouprepositoryimplmysql.h"
#include "repository_impl/authrepositoryimplmysql.h"

#include "controllers/studentcontroller.h"
#include "controllers/subjectconstroller.h"
#include "controllers/groupcontroller.h"
#include "controllers/authcontroller.h"

#include "tui/facades/studentfacade.h"
#include "tui/authdisplay.h"

#include "config/config.h"

#include <iostream>

int main(int argc, char* argv[])
{

    std::shared_ptr<StudentRepository> studentRepository;
    std::shared_ptr<SubjectRepository> subjectRepository;
    std::shared_ptr<GroupRepository> groupRepository;
    std::shared_ptr<TeacherRepository> teacherRepository;
    std::shared_ptr<AuthRepository> authRepositry;

    if (argc != 2) {
        std::cout << "usage: app.exe [DBMS NAME]" << std::endl;
        return -1;
    }

    if (std::strcmp(argv[1], "psql") == 0) {
        std::string conn = getPGConfig();
        std::cout << conn << std::endl;
        studentRepository = std::shared_ptr<StudentRepository>(new StudentRepositoryImplPg(conn));
        subjectRepository = std::shared_ptr<SubjectRepository>(new SubjectRepositoryImplPg(conn));
        groupRepository = std::shared_ptr<GroupRepository>(new GroupRepositoryImplPg(conn));
        teacherRepository = std::shared_ptr<TeacherRepository>(new TeacherRepositoryImplPg(conn));
        authRepositry = std::shared_ptr<AuthRepository>(new AuthRepositoryImplPg(conn));
    } else if (std::strcmp(argv[1], "mysql") == 0) {
        auto mySqlCofig = getMySqlConfig();
        studentRepository = std::shared_ptr<StudentRepository>(new StudentRepositoryImplMySql(mySqlCofig.getUrl(),
                                                                                              mySqlCofig.getUser(),
                                                                                              mySqlCofig.getPassword()));
        subjectRepository = std::shared_ptr<SubjectRepository>(new SubjectRepositoryImplMySql(mySqlCofig.getUrl(),
                                                                                              mySqlCofig.getUser(),
                                                                                              mySqlCofig.getPassword()));
        groupRepository = std::shared_ptr<GroupRepository>(new GroupRepositoryImplMySql(mySqlCofig.getUrl(),
                                                                                        mySqlCofig.getUser(),
                                                                                        mySqlCofig.getPassword()));
        teacherRepository = std::shared_ptr<TeacherRepository>(new TeacherRepositoryImplMySql(mySqlCofig.getUrl(),
                                                                                              mySqlCofig.getUser(),
                                                                                              mySqlCofig.getPassword()));
        authRepositry = std::shared_ptr<AuthRepository>(new AuthRepositoryImplMySql(mySqlCofig.getUrl(),
                                                                                    mySqlCofig.getUser(),
                                                                                    mySqlCofig.getPassword()));
    } else {
        std::cout << "usage: app.exe [DBMS NAME]" << std::endl;
        return -1;
    }

    StudentController studentController(studentRepository.get());
    SubjectController subjectController(subjectRepository.get());
    GroupController groupController(groupRepository.get());
    TeacherController teacherController(teacherRepository.get());
    AuthController authController(authRepositry.get());

    StudentFacade studentFacade(&studentController, &groupController, &subjectController);
    AuthFacade authFacade(&authController);
    TeacherFacade teacherFacade(&teacherController, &groupController, &subjectController, &studentController);

    AuthDisplay authdisplay(authFacade, studentFacade, teacherFacade);
    authdisplay.startDisplay();
    return 0;
}
