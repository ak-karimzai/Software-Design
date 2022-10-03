#include "config.h"

#include <fstream>
#include <algorithm>
#include <sstream>
#include <iostream>

const std::string pgConfigFileName = "./config/postgres.config";
const std::string mySqlConfigFileName = "./config/mysql.config";

MySqlConfig::MySqlConfig(const std::string &url, const std::string &user, const std::string &password) : url(url),
    user(user),
    password(password)
{}

const std::string &MySqlConfig::getUrl() const
{
    return url;
}

void MySqlConfig::setUrl(const std::string &newUrl)
{
    url = newUrl;
}

const std::string &MySqlConfig::getUser() const
{
    return user;
}

void MySqlConfig::setUser(const std::string &newUser)
{
    user = newUser;
}

const std::string &MySqlConfig::getPassword() const
{
    return password;
}

void MySqlConfig::setPassword(const std::string &newPassword)
{
    password = newPassword;
}


std::string getPGConfig() {
    std::string res;
    try {
        std::ifstream configFile(pgConfigFileName);
        if (!configFile.is_open()) {
            throw ConfigFileException(__FILE__, "configuration file not found", __LINE__);
        }
        std::string line;
        while (std::getline(configFile, line)) {
            res += line += " ";
        }
        configFile.close();
    }  catch (std::exception & e) {
        throw ConfigFileException(__FILE__, "configuration file problem", __LINE__);
    }
    return res;
}

MySqlConfig getMySqlConfig() {
    std::string user;
    std::string password;
    std::string url;
    try {
        std::ifstream configFile(mySqlConfigFileName);
        if (!configFile.is_open()) {
            throw ConfigFileException(__FILE__, "configuration file not found", __LINE__);
        }
        std::string line;
        while (std::getline(configFile, line)) {
            size_t position = line.find('=');
            if (position != std::string::npos) {
                std::string key = line.substr(0,
                                              position);
                std::string value = std::string(line.begin() + position + 1,
                                                line.end());
                if (key == "hostaddr") {
                    url = value;
                } else if (key == "user") {
                    user = value;
                } else if (key == "password") {
                    password = value;
                }
            }
        }
    }  catch (std::exception & e) {
        throw ConfigFileException(__FILE__, "configuration file problem", __LINE__);
    }
    return MySqlConfig(url, user, password);
}
