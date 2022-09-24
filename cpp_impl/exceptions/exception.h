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
    DataAccessException(std::string fileName,
                        std::string className,
                        int currentLine) : Exception(fileName,
                                                     className,
                                                     currentLine) {}
};

#endif // EXCEPTION_H
