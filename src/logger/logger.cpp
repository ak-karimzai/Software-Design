#include "logger.h"

#include <time.h>
#include <sstream>

const std::string infoFileName = "./logger/info.log";
const std::string errorFileName = "./logger/error.log";
const std::string warningFileName = "./logger/warning.log";

Logger::~Logger()
{
    infoFile.close();
    errorFile.close();
    warningFile.close();
    created = false;
}

bool Logger::created = false;
std::shared_ptr<Logger> Logger::logger;
std::ofstream Logger::infoFile;
std::ofstream Logger::errorFile;
std::ofstream Logger::warningFile;

Logger *Logger::getInstance()
{
    if (created == false) {
        logger = std::shared_ptr<Logger>(new Logger());
        infoFile = std::ofstream(infoFileName);
        errorFile = std::ofstream(errorFileName);
        warningFile = std::ofstream(warningFileName);
        created = true;
    }
    return logger.get();
}

void Logger::logError(const std::string &msg)
{
    errorFile << currentDateTime() << " - " << __func__
              << ":" << msg << std::endl;
}

void Logger::logInfo(const std::string &msg)
{
    infoFile << currentDateTime() << " - " << __func__
              << ":" << msg << std::endl;
}

void Logger::logWarning(const std::string &msg)
{
    warningFile << currentDateTime() << " - " << __func__
              << ":" << msg << std::endl;
}

Logger::Logger()
{

}

const std::string Logger::currentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}
