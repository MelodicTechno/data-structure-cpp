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

add_executable(demo_linkedlist src/demos/linkedlist_demo.cpp)
target_link_libraries(demo_linkedlist PRIVATE ds)

add_executable(demo_stack src/demos/stack_demo.cpp)
target_link_libraries(demo_stack PRIVATE ds)
