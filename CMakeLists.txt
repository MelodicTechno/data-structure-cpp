cmake_minimum_required(VERSION 3.10)
project(data)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(ds STATIC
    src/LinkedList/LinkedList.cpp
    src/List/List.cpp
    src/Stack/Stack.cpp
    src/Queue/Queue.cpp
)

target_include_directories(ds PUBLIC ${PROJECT_SOURCE_DIR}/src)

add_executable(data src/main.cpp)
target_link_libraries(data PRIVATE ds)

add_executable(linkedlist src/demos/linkedlist.cpp)
target_link_libraries(linkedlist PRIVATE ds)

add_executable(stack src/demos/stack.cpp)
target_link_libraries(stack PRIVATE ds)
