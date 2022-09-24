cmake_minimum_required(VERSION 3.5)

project(None LANGUAGES CXX)

enable_testing()



find_package(Threads REQUIRED)

if ($ENV{GOOGLETEST_DIR})
    set(GOOGLETEST_DIR $ENV{GOOGLETEST_DIR})
else ()
    if (NOT "" STREQUAL "")
        message(WARNING "Using googletest src dir specified at Qt Creator wizard")
    endif ()
    set(GOOGLETEST_DIR "")
endif ()
if (EXISTS ${GOOGLETEST_DIR})
    set(GTestSrc ${GOOGLETEST_DIR}/googletest)
    set(GMockSrc ${GOOGLETEST_DIR}/googlemock)
elseif (UNIX AND EXISTS /usr/src/gtest)
    set(GTestSrc /usr/src/gtest)
    message(WARNING "Using gtest from system")
    if (EXISTS /usr/src/gmock)
        set(GMockSrc /usr/src/gmock)
    endif ()
else ()
    message( FATAL_ERROR "No googletest src dir found - set GOOGLETEST_DIR to enable!")
endif ()

set(GTestFiles ${GTestSrc}/src/gtest-all.cc)
set(GTestIncludes ${GTestSrc} ${GTestSrc}/include)
if (NOT ${GMockSrc} STREQUAL "")
    list(APPEND GTestFiles ${GMockSrc}/src/gmock-all.cc)
    list(APPEND GTestIncludes ${GMockSrc} ${GMockSrc}/include)
endif ()

include_directories(${GTestIncludes})

#add_subdirectory("./")

add_executable(None
    testrepository/run_tests.cpp
    testrepository/tests.cpp

    controllers/groupcontroller.cpp
    controllers/groupcontroller.h
    controllers/studentcontroller.cpp
    controllers/studentcontroller.h
    controllers/subjectconstroller.cpp
    controllers/subjectconstroller.h
    controllers/teachercontroller.cpp
    controllers/teachercontroller.h

    entity/group.cpp
    entity/group.h
    entity/student.cpp
    entity/student.h
    entity/subject.cpp
    entity/subject.h
    entity/teacher.cpp
    entity/teacher.h

    repository_impl/grouprepositoryimplpg.cpp
    repository_impl/grouprepositoryimplpg.h
    repository_impl/studentrepositoryimplpg.cpp
    repository_impl/studentrepositoryimplpg.h
    repository_impl/subjectrepositoryimplpg.cpp
    repository_impl/subjectrepositoryimplpg.h
    repository_impl/teacherrepositoryimplpg.cpp
    repository_impl/teacherrepositoryimplpg.h

    testrepository/testgrouprepository.cpp
    testrepository/testgrouprepository.h
    testrepository/teststudentrepository.cpp
    testrepository/teststudentrepository.h
    testrepository/testsubjectrepository.cpp
    testrepository/testsubjectrepository.h
    testrepository/testteacherrepository.cpp
    testrepository/testteacherrepository.h

    repositories/grouprepository.cpp
    repositories/grouprepository.h
    repositories/studentrepository.cpp
    repositories/studentrepository.h
    repositories/subjectrepository.cpp
    repositories/subjectrepository.h
    repositories/teacherrepository.cpp
    repositories/teacherrepository.h

               ${GTestFiles})

add_test(NAME None COMMAND None)
target_link_libraries(None PRIVATE Threads::Threads)

