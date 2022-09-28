#ifndef AUTHCONTROLLER_H
#define AUTHCONTROLLER_H

#include "../repositories/authrepository.h"

class AuthController
{
public:
    ~AuthController();
    AuthController(AuthRepository *authRepository);

    void addNewUser(const std::string & login,
                            const std::string & password,
                            const int teacherId);
    void changeUserPassword(const int teacherId,
                                    const std::string & newPassword);
    void changeUserLogin(const int teacherId,
                                 const std::string & newLogin);
    Auth getUserDetails(const int teacherId);
    void deleteUserDetails(const int authId);
    void deleteUserDetailsByTeacherId(const int teacherId);
    std::vector<Auth> getUsers();
private:
    AuthRepository * authRepository;
};

#endif // AUTHCONTROLLER_H
