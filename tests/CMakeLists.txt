cmake_minimum_required(VERSION 3.3)

project(Test)

include(CTest)
enable_testing()

include(DownloadProject.cmake)
download_project(
        PROJ googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG master
        UPDATE_DISCONNECTED 1
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)
set(test_SRCS matrixTests.cpp)
add_executable(runUnitTests ${test_SRCS})
target_link_libraries(runUnitTests gtest core)
add_test(runUnitTests runUnitTests)