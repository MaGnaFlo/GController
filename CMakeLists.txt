cmake_minimum_required(VERSION 3.16)

project(GController VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(gctrl ${SRC_FILES})
target_include_directories(gctrl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/hidapi/include)
target_link_directories(gctrl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/hidapi/lib)
target_link_libraries(gctrl PRIVATE hidapi)
