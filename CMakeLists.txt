cmake_minimum_required(VERSION 3.14)
project(clrs)

set(CMAKE_CXX_STANDARD 20)

include_directories(src include)

get_filename_component(GTEST_LIBRARY_PATH lib/libgtest.a ABSOLUTE)
get_filename_component(GTEST_INCLUDE_DIR_PATH include/gtest ABSOLUTE)
get_filename_component(GTEST_MAIN_LIBRARY_PATH lib/libgtest_main.a ABSOLUTE)
set(GTEST_LIBRARY ${GTEST_LIBRARY_PATH})
set(GTEST_INCLUDE_DIR ${GTEST_INCLUDE_DIR_PATH})
set(GTEST_MAIN_LIBRARY ${GTEST_MAIN_LIBRARY_PATH})
find_package(GTest REQUIRED)
enable_testing()

file(GLOB_RECURSE source_files *.cc)

foreach (file ${source_files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file})
    target_link_libraries(${name} ${GTEST_BOTH_LIBRARIES} pthread)
    gtest_discover_tests(${name})
endforeach ()
