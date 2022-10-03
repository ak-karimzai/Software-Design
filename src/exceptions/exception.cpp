#include "exception.h"

#include <sstream>

Exception::Exception(std::string fileName,
                     std::string className,
                     int currentLine)
{
    std::stringstream ss;
    ss << "in file " << fileName << "\n" <<
           "class " << className  << "\n"  <<
           "line " << currentLine << "\n";
    info = ss.str();
}

const char *Exception::what() const noexcept
{
    return this->info.c_str();
}

DataUpdateException::DataUpdateException(const std::string &fileName, const std::string &className, int currentLine) : Exception(fileName, className, currentLine)
{}

DataAccessException::DataAccessException(const std::string &fileName, const std::string &className, int currentLine) : Exception(fileName, className, currentLine)
{}

DataDeleteException::DataDeleteException(const std::string &fileName, const std::string &className, int currentLine) : Exception(fileName, className, currentLine)
{}

DataSourceAccessException::DataSourceAccessException(const std::string &fileName, const std::string &className, int currentLine) : Exception(fileName, className, currentLine)
{}

ConfigFileException::ConfigFileException(const std::string &fileName, const std::string &className, int currentLine) : Exception(fileName, className, currentLine)
{}
