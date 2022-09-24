#include "testrepository/testsubjectrepository.h"
#include "controllers/subjectconstroller.h"

#include <iostream>

int main()
{
    std::vector<Subject> subjects = {
                Subject(1, "AAA", 34, 1),
                Subject(2, "BBB", 36, 3),
                Subject(3, "CCC", 40, 9)
            };
    TestSubjectRepository testrepo(subjects);
    SubjectConstroller subcontroller(&testrepo);
    std::cout <<"EEEEEE" << std::endl;
    return 0;
}
