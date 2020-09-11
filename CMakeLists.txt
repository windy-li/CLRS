cmake_minimum_required(VERSION 3.17)

project(CLRS)

set(CMAKE_CXX_STANDARD 17)

include_directories(src test)

file(GLOB_RECURSE HEADER_FILES src/*.h)
file(GLOB_RECURSE TEST_FILES test/*.cc)

foreach (file ${TEST_FILES})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file} ${HEADER_FILES})
endforeach ()
