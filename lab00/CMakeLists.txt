
include_directories(src)
include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

add_executable (main src/lib.c src/main.c)
add_executable (test src/lib.c test/test.c)
target_link_libraries(test check)
