#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

class Exception : public std::exception
{
public:
    Exception(std::string fileName,
              std::string className,
              int currentLine);
    const char *what() const noexcept;
protected:
    std::string info;
};

class DataAccessException : public Exception
{
public:
    DataAccessException(const std::string &fileName, const std::string &className, int currentLine);
};

class DataUpdateException : public Exception
{
public:
    DataUpdateException(const std::string &fileName, const std::string &className, int currentLine);
};

class DateDeleteException : public Exception
{
public:
    DateDeleteException(const std::string &fileName, const std::string &className, int currentLine);
};

class DataSourceAccessException : public Exception
{
public:
    DataSourceAccessException(const std::string &fileName, const std::string &className, int currentLine);

};

class ConfigFileException : public Exception
{
public:
    ConfigFileException(const std::string &fileName, const std::string &className, int currentLine);

};

#endif // EXCEPTION_H
