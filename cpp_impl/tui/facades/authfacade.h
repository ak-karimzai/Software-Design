#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include "../../controllers/authcontroller.h"

#include <memory>

class AuthFacade
{
public:
    AuthFacade(AuthController * controller);

    int getTeacherId(const std::string & login,
                      const std::string & password);
    bool isAuthorizedAsAdmin(const std::string & login,
                            const std::string & password);
    void registerNewUser(const std::string & login,
                         const std::string & password,
                         const int fk);
    void deleteUserLogin(const int id);
    void deleteUserLoginByTeacherId(const int teacherId);
private:
    AuthController * controller;
};

#endif // AUTHMANAGER_H
