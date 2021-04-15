cmake_minimum_required(VERSION 3.17)

project(CLRS)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

file(GLOB_RECURSE HEADER_FILES *.h)
file(GLOB_RECURSE SOURCE_FILES *.cc)

foreach (file ${SOURCE_FILES})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file} ${HEADER_FILES})
endforeach ()
