QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        controllers/groupcontroller.cpp \
        controllers/studentcontroller.cpp \
        controllers/subjectconstroller.cpp \
        controllers/teachercontroller.cpp \
        entity/group.cpp \
        entity/student.cpp \
        entity/subject.cpp \
        entity/teacher.cpp \
        main.cpp \
        repository_impl/grouprepositoryimplpg.cpp \
        repository_impl/studentrepositoryimplpg.cpp \
        repository_impl/subjectrepositoryimplpg.cpp \
        repository_impl/teacherrepositoryimplpg.cpp \
        testrepository/testgrouprepository.cpp \
        testrepository/teststudentrepository.cpp \
        testrepository/testsubjectrepository.cpp \
        testrepository/testteacherrepository.cpp \
        repositories/grouprepository.cpp \
        repositories/studentrepository.cpp \
        repositories/subjectrepository.cpp \
        repositories/teacherrepository.cpp \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    controllers/groupcontroller.h \
    controllers/studentcontroller.h \
    controllers/subjectconstroller.h \
    controllers/teachercontroller.h \
    entity/group.h \
    entity/student.h \
    entity/subject.h \
    entity/teacher.h \
    repositories/grouprepository.h \
    repositories/studentrepository.h \
    repositories/subjectrepository.h \
    repositories/teacherrepository.h \
    repository_impl/grouprepositoryimplpg.h \
    repository_impl/studentrepositoryimplpg.h \
    repository_impl/subjectrepositoryimplpg.h \
    repository_impl/teacherrepositoryimplpg.h \
    testrepository/testgrouprepository.h \
    testrepository/teststudentrepository.h \
    testrepository/testsubjectrepository.h \
    testrepository/testteacherrepository.h
