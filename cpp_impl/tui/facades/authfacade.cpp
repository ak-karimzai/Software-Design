#include "authfacade.h"

const std::string adminLogin = "khalid";
const std::string adminPassword = "khalid";

AuthFacade::AuthFacade(AuthController * controller) : controller(controller)
{}

int AuthFacade::getTeacherId(const std::string &login, const std::string &password)
{
    int userId = -1;
    auto users = controller->getUsers();
    for (const auto & user : users) {
        if (user.getLogin() == login &&
                user.getPassword() == password) {
            userId = user.getTeacherId();
            break;
        }
    }
    return userId;
}

bool AuthFacade::isAuthorizedAsAdmin(const std::string &login, const std::string &password)
{
    return login == adminLogin && password == adminPassword;
}

void AuthFacade::registerNewUser(const std::string &login, const std::string &password, const int fk)
{
    controller->addNewUser(login, password, fk);
}

void AuthFacade::deleteUserLogin(const int fk)
{
    controller->deleteUserDetails(fk);
}

void AuthFacade::deleteUserLoginByTeacherId(const int teacherId)
{
    controller->deleteUserDetailsByTeacherId(teacherId);
}
