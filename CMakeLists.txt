cmake_minimum_required(VERSION 3.17)
project(Rotation2D)

set(EXECUTABLE ${CMAKE_PROJECT_NAME}_run)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-pthread")

add_subdirectory(lib/GNUPlot)
add_subdirectory(test)
add_subdirectory(lib/googletest)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true include/*.h source/*.cpp)

include_directories(${CMAKE_SOURCE_DIR}/lib/GNUPlot)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(${EXECUTABLE} ${SOURCES})
add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})
target_link_libraries(${EXECUTABLE} PRIVATE GNUPlot_lib)