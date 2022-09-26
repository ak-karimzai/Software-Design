#ifndef AUTHREPOSITORY_H
#define AUTHREPOSITORY_H

#include "../entity/auth.h"

#include <vector>

class AuthRepository
{
public:
    virtual void addNewUser(const std::string & login,
                            const std::string & password,
                            const int teacherId);
    virtual void changeUserPassword(const int teacherId,
                                    const std::string & newPassword);
    virtual void changeUserLogin(const int teacherId,
                                 const std::string & newLogin);
    virtual Auth getUserDetails(const int teacherId);
    virtual void deleteUserDetails(const int teacherId);
    virtual std::vector<Auth> getUsers();
};

#endif // AUTHREPOSITORY_H
