#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>

class Subject
{
public:
    Subject();
    Subject(int id, const std::string &subjectName, int marks, int studentId);
    ~Subject();

    int getId() const;
    void setId(int newId);

    const std::string &getSubjectName() const;
    void setSubjectName(const std::string &newSubjectName);

    int getMarks() const;
    void setMarks(int newMarks);

    int getStudentId() const;
    void setStudentId(int newStudentId);

private:
    int id;
    std::string subjectName;
    int marks;
    int studentId;
};

#endif // SUBJECT_H
