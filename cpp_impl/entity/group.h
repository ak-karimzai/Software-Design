#ifndef GROUP_H
#define GROUP_H

#include <string>

class Group
{
public:
    Group();
    Group(int id, const std::string &name, int teacherId);
    int getId() const;
    void setId(int newId);
    const std::string &getName() const;
    void setName(const std::string &newName);
    int getTeacherId() const;
    void setTeacherId(int newTeacherId);

private:
    int id;
    std::string name;
    int teacherId;
};

#endif // GROUP_H
