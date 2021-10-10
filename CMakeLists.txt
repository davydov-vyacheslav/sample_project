cmake_minimum_required (VERSION 3.12)
set(CMAKE_OSX_ARCHITECTURES arm64)
project (sample_project)

include_directories(lab00/src)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_executable (main lab00/src/lib.c lab00/src/main.c)
add_executable (test lab00/src/lib.c lab00/test/test.c)
target_link_libraries(test check)
