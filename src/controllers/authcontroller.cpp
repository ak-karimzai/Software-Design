#include "authcontroller.h"

AuthController::~AuthController()
{

}

AuthController::AuthController(AuthRepository *authRepository) : authRepository(authRepository)
{}

void AuthController::addNewUser(const std::string &login, const std::string &password, const int teacherId)
{
    authRepository->addNewUser(login, password, teacherId);
}

void AuthController::changeUserPassword(const int teacherId, const std::string &newPassword)
{
    authRepository->changeUserPassword(teacherId, newPassword);
}

void AuthController::changeUserLogin(const int teacherId, const std::string &newLogin)
{
    authRepository->changeUserLogin(teacherId, newLogin);
}

Auth AuthController::getUserDetails(const int teacherId)
{
    return authRepository->getUserDetails(teacherId);
}

void AuthController::deleteUserDetails(const int teacherId)
{
    authRepository->deleteUserDetails(teacherId);
}

void AuthController::deleteUserDetailsByTeacherId(const int teacherId)
{
    authRepository->deleteUserDetailsByTeacherId(teacherId);
}

std::vector<Auth> AuthController::getUsers()
{
    return authRepository->getUsers();
}
