#https://google.github.io/googletest/quickstart-cmake.html

cmake_minimum_required(VERSION 3.14)
project(clrs)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip)
FetchContent_MakeAvailable(googletest)

include_directories(src)

file(GLOB_RECURSE source_files *.cc)

enable_testing()

include(GoogleTest)

foreach (file ${source_files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file})
    target_link_libraries(${name} gtest_main)
    gtest_discover_tests(${name})
endforeach ()
