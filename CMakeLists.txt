cmake_minimum_required(VERSION 3.13)
project(NCursesConnectN C)

set(CMAKE_C_STANDARD 11)

add_executable(NCursesConnectN main.c curse.h curse.c move.c move.h board.c board.h win.c win.h)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses)
set_target_properties(NCursesConnectN
        PROPERTIES
        OUTPUT_NAME "NCursesConnectN"
        SUFFIX ".out"
        )

target_link_libraries(NCursesConnectN PRIVATE ${CURSES_LIBRARIES})

target_include_directories(NCursesConnectN  PRIVATE ${CURSES_INCLUDE_DIRS})