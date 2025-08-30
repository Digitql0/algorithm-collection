cmake_minimum_required(VERSION 3.10)
project(algorithms LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

# Collect sources
file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS
    src/*.cpp
    src/*.c
)
list(REMOVE_ITEM LIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.c")

# Build as a static library
add_library(algorithms STATIC ${LIB_SOURCES})
target_include_directories(algorithms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(APP_SOURCES src/main.c)

# Build as an Executable
add_executable(algorithmsApp ${APP_SOURCES})
target_link_libraries(algorithmsApp PRIVATE algorithms)
