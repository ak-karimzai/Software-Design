cmake_minimum_required(VERSION 3.5)

project(None LANGUAGES CXX)

enable_testing()

find_package(Threads REQUIRED)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

if(NOT "${CMAKE_CXX_STANDARD}")
    set(CMAKE_CXX_STANDARD 20)
endif()

if(NOT PostgreSQL_FOUND)
    find_package(PostgreSQL REQUIRED)
endif()

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

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -DJWT_CLAIM_EXPLICIT=0")
link_directories(libs)

set(CMAKE_CXX_FLAGS "-lpqxx -lpq -lmysqlcppconn")

set(MAIN_APP_SRC
    tui/facades/authfacade.cpp
    tui/facades/teacherfacade.cpp
    tui/facades/studentfacade.cpp

    config/config.cpp

    tui/authdisplay.cpp
    tui/studentdisplay.cpp
    tui/teacherdisplay.cpp
    tui/admindisplay.cpp
)

set(MAIN_APP_HEADERS
    tui/facades/authfacade.h
    tui/facades/teacherfacade.h
    tui/facades/studentfacade.h

    config/config.h

    tui/authdisplay.h
    tui/teacherdisplay.h
    tui/studentdisplay.h
    tui/admindisplay.h

    tui/display.h
)

set(SOURCES
    controllers/groupcontroller.cpp
    controllers/studentcontroller.cpp
    controllers/subjectconstroller.cpp
    controllers/teachercontroller.cpp
    controllers/authcontroller.cpp

    entity/group.cpp
    entity/student.cpp
    entity/subject.cpp
    entity/teacher.cpp
    entity/auth.cpp

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

    repositories/grouprepository.cpp
    repositories/studentrepository.cpp
    repositories/subjectrepository.cpp
    repositories/teacherrepository.cpp
    repositories/authrepository.cpp

    exceptions/exception.cpp
)

set(HEADERS
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

    repositories/grouprepository.h
    repositories/studentrepository.h
    repositories/subjectrepository.h
    repositories/teacherrepository.h
    repositories/authrepository.h

    exceptions/exception.h
)

set(
    TEST_SRC_HEADERS

    testrepository/run_tests.cpp
    testrepository/pg_tests.cpp
    testrepository/tests.cpp

    testrepository/testgrouprepository.h
    testrepository/teststudentrepository.h
    testrepository/testsubjectrepository.h
    testrepository/testteacherrepository.h
    testrepository/testauthrepository.h

    testrepository/testgrouprepository.cpp
    testrepository/teststudentrepository.cpp
    testrepository/testsubjectrepository.cpp
    testrepository/testteacherrepository.cpp
    testrepository/testauthrepository.cpp
)

add_executable(None
    ${SOURCES}
    ${HEADERS}
    ${TEST_SRC_HEADERS}
    ${GTestFiles})

add_executable(main.exe
    main.cpp

    ${SOURCES}
    ${HEADERS}
    ${MAIN_APP_SRC}
    ${MAIN_APP_HEADERS}
)

add_test(NAME None COMMAND None)
target_link_libraries(None PRIVATE Threads::Threads pqxx pq mysqlcppconn)
target_link_libraries(main.exe pqxx pq mysqlcppconn)


