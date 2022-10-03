#ifndef CONFIG_H
#define CONFIG_H

#include "../exceptions/exception.h"

#include <string>

class MySqlConfig
{
public:
    MySqlConfig(const std::string &url, const std::string &user, const std::string &password);


    const std::string &getUrl() const;
    void setUrl(const std::string &newUrl);
    const std::string &getUser() const;
    void setUser(const std::string &newUser);
    const std::string &getPassword() const;
    void setPassword(const std::string &newPassword);

private:
    std::string url;
    std::string user;
    std::string password;
};

std::string getPGConfig();
MySqlConfig getMySqlConfig();

#endif // CONFIG_H
