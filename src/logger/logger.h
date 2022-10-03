#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include <iostream>
#include <fstream>

class Logger
{
public:
    ~Logger();
    static Logger * getInstance();

    void logError(const std::string & msg);
    void logInfo(const std::string & msg);
    void logWarning(const std::string & msg);
private:
    Logger();
    const std::string currentDateTime();

private:
    static std::shared_ptr<Logger> logger;
    static std::ofstream infoFile;
    static std::ofstream errorFile;
    static std::ofstream warningFile;
    static bool created;
};

#endif // LOGGER_H
