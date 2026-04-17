cmake_minimum_required(VERSION 3.10)
project(data)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(Matplot++_DIR "E:/cpp_libs/matplot-install/Release/lib/cmake/Matplot++")
find_package(Matplot++ REQUIRED)

add_library(ds STATIC
    src/LinkedList/LinkedList.cpp
    src/List/List.cpp
    src/Stack/Stack.cpp
    src/Queue/Queue.cpp
    src/Queue/CircleQueue.cpp
    src/Stack/ListStack.cpp
)

add_library(vis STATIC
    src/utils/display.cpp
)
target_include_directories(vis PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(vis PUBLIC Matplot++::matplot)

target_include_directories(ds PUBLIC ${PROJECT_SOURCE_DIR}/src)

add_executable(matplot src/demo/matplot.cpp)
target_link_libraries(matplot PRIVATE vis)

add_executable(data src/main.cpp)
target_link_libraries(data PRIVATE ds)

add_executable(linkedlist src/demo/linkedlist.cpp)
target_link_libraries(linkedlist PRIVATE ds)

add_executable(stack src/demo/stack.cpp)
target_link_libraries(stack PRIVATE ds)

add_executable(circlequeue src/demo/circlequeue.cpp)
target_link_libraries(circlequeue PRIVATE ds)

add_executable(liststack src/demo/liststack.cpp)
target_link_libraries(liststack PRIVATE ds)
