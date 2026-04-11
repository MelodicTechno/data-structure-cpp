cmake_minimum_required(VERSION 3.10)
project(data)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(data
    src/main.cpp
    src/LinkedList/LinkedList.cpp
    src/LinkedList/ListNode.cpp
    src/List/List.cpp
)

target_include_directories(data PRIVATE ${PROJECT_SOURCE_DIR}/src)
