cmake_minimum_required(VERSION 3.17)

project(CLRS)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

#file(GLOB_RECURSE header_files *.h)
file(GLOB_RECURSE source_files *.cc)

foreach (file ${source_files})
    get_filename_component(name ${file} NAME)
#    add_executable(${name} ${file} ${header_files})
    add_executable(${name} ${file})
endforeach ()
