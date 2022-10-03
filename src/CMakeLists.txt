cmake_minimum_required(VERSION 3.5)

project(untitled6 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(CMAKE_CXX_FLAGS "-lpqxx -lpq -lmysqlcppconn")


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        inputdialog.cpp
        studentdialog.cpp
        studentdialog.h
        inputdialog.h
        mainwindow.h
        mainwindow.ui

        entity/group.cpp
        entity/student.cpp
        entity/subject.cpp
        entity/teacher.cpp
        entity/auth.cpp

        logger/logger.cpp

        repository_impl/authrepositoryimplmysql.cpp
        repository_impl/grouprepositoryimplmysql.cpp
        repository_impl/studentrepositoryimplmysql.cpp
        repository_impl/subjectrepositoryimplmysql.cpp
        repository_impl/teacherrepositoryimplmysql.cpp

        repository_impl/grouprepositoryimplpg.cpp
        repository_impl/studentrepositoryimplpg.cpp
        repository_impl/subjectrepositoryimplpg.cpp
        repository_impl/teacherrepositoryimplpg.cpp
        repository_impl/authrepositoryimplpg.cpp
        repository_impl/querygenerators.cpp

        controllers/groupcontroller.cpp
        controllers/studentcontroller.cpp
        controllers/subjectconstroller.cpp
        controllers/teachercontroller.cpp
        controllers/authcontroller.cpp

        exceptions/exception.cpp

        logger/logger.h

        repository_impl/authrepositoryimplmysql.h
        repository_impl/grouprepositoryimplmysql.h
        repository_impl/studentrepositoryimplmysql.h
        repository_impl/subjectrepositoryimplmysql.h
        repository_impl/teacherrepositoryimplmysql.h

        repository_impl/grouprepositoryimplpg.h
        repository_impl/studentrepositoryimplpg.h
        repository_impl/subjectrepositoryimplpg.h
        repository_impl/teacherrepositoryimplpg.h
        repository_impl/authrepositoryimplpg.h
        repository_impl/querygenerators.h

        repositories/grouprepository.cpp
        repositories/studentrepository.cpp
        repositories/subjectrepository.cpp
        repositories/teacherrepository.cpp
        repositories/authrepository.cpp

        controllers/groupcontroller.h
        controllers/studentcontroller.h
        controllers/subjectconstroller.h
        controllers/teachercontroller.h
        controllers/authcontroller.h


        entity/group.h
        entity/student.h
        entity/subject.h
        entity/teacher.h
        entity/auth.h


        repositories/grouprepository.h
        repositories/studentrepository.h
        repositories/subjectrepository.h
        repositories/teacherrepository.h
        repositories/authrepository.h

        exceptions/exception.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(untitled6
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET untitled6 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(untitled6 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(untitled6
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(untitled6 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets pqxx pq mysqlcppconn)

set_target_properties(untitled6 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(untitled6)
endif()
