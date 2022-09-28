#include "repository_impl/studentrepositoryimplpg.h"
#include "repository_impl/subjectrepositoryimplpg.h"
#include "repository_impl/teacherrepositoryimplpg.h"
#include "repository_impl/grouprepositoryimplpg.h"
#include "repository_impl/authrepositoryimplpg.h"

#include "controllers/studentcontroller.h"
#include "controllers/subjectconstroller.h"
#include "controllers/groupcontroller.h"
#include "controllers/authcontroller.h"

#include "tui/facades/studentfacade.h"
#include "tui/authdisplay.h"

const std::string conn = std::string("dbname = school ") +
                         std::string("user = khalid ") +
                         std::string("password = 1234abcd ") +
                         std::string("hostaddr = 127.0.0.1 ") +
                         std::string("port = 5432");

int main(int argc, char* argv[])
{
    std::shared_ptr<StudentRepository> studentRepository(new StudentRepositoryImplPg(conn));
    std::shared_ptr<SubjectRepository> subjectRepository(new SubjectRepositoryImplPg(conn));
    std::shared_ptr<GroupRepository> groupRepository(new GroupRepositoryImplPg(conn));
    std::shared_ptr<TeacherRepository> teacherRepository(new TeacherRepositoryImplPg(conn));
    std::shared_ptr<AuthRepository> authRepositry(new AuthRepositoryImplPg(conn));

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
