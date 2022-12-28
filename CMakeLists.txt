cmake_minimum_required(VERSION 3.16)

# Pulldown raylib
execute_process(COMMAND git clone https://github.com/raysan5/raylib.git raylib)
add_subdirectory(${CMAKE_BINARY_DIR}/raylib)

# Pulldown Lua
execute_process(COMMAND git clone https://github.com/lua/lua.git lua)

project(lua)

# Finding all the source files for lualib
file(GLOB luaSrcs ${CMAKE_BINARY_DIR}/lua/*.c)
list(REMOVE_ITEM luaSrcs ${CMAKE_BINARY_DIR}/lua/lua.c)
list(REMOVE_ITEM luaSrcs ${CMAKE_BINARY_DIR}/lua/onelua.c)

add_library(lua
    ${luaSrcs}
)

target_include_directories(lua PUBLIC ${CMAKE_BINARY_DIR}/lua)

# Tiny comp
project(TinyComp)

add_executable(TinyComp
    src/main.c
    src/tinyComp.c
)

target_include_directories(TinyComp PUBLIC src)
target_link_libraries(TinyComp PUBLIC raylib lua)