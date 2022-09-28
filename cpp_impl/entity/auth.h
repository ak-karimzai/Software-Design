#ifndef AUTH_H
#define AUTH_H

#include <string>
#include <ostream>

class Auth
{
public:
    Auth();
    ~Auth();
    Auth(int id, const std::string &login, const std::string &password, int teacher_id);

    int getId() const;
    void setId(int newId);
    const std::string &getLogin() const;
    void setLogin(const std::string &newLogin);
    const std::string &getPassword() const;
    void setPassword(const std::string &newPassword);
    int getTeacherId() const;
    void setTeacherId(int newTeacherId);
    friend std::ostream& operator<<(std::ostream& os, const Auth& auth);
private:
    int id;
    std::string login;
    std::string password;
    int teacherId;
};

#endif // AUTH_H
