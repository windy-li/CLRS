#https://google.github.io/googletest/quickstart-cmake.html

cmake_minimum_required(VERSION 3.14)
project(clrs)

set(CMAKE_CXX_STANDARD 17)

#include(FetchContent)
#FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip)
#FetchContent_MakeAvailable(googletest)

include_directories(src include)

get_filename_component(GTEST_LIBRARY_PATH lib/libgtest.a ABSOLUTE)
get_filename_component(GTEST_INCLUDE_DIR_PATH include/gtest ABSOLUTE)
get_filename_component(GTEST_MAIN_LIBRARY_PATH lib/libgtest_main.a ABSOLUTE)

set(GTEST_LIBRARY ${GTEST_LIBRARY_PATH})
set(GTEST_INCLUDE_DIR ${GTEST_INCLUDE_DIR_PATH})
set(GTEST_MAIN_LIBRARY ${GTEST_MAIN_LIBRARY_PATH})

#set(GTEST_LIBRARY /Users/lixiaogang/Leo/clrs/lib/libgtest.a)
#set(GTEST_INCLUDE_DIR /Users/lixiaogang/Leo/clrs/include/gtest)
#set(GTEST_MAIN_LIBRARY /Users/lixiaogang/Leo/clrs/lib/libgtest_main.a)

find_package(GTest REQUIRED)

file(GLOB_RECURSE source_files *.cc)

enable_testing()

#include(GoogleTest)

foreach (file ${source_files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file})
    #    target_link_libraries(${name} gtest_main)
    target_link_libraries(${name} ${GTEST_BOTH_LIBRARIES} pthread)
    gtest_discover_tests(${name})
endforeach ()
