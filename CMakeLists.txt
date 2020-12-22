cmake_minimum_required(VERSION 3.6)
project(rgb-filter)

set(CMAKE_CXX_STANDARD 17)

set(APP_TARGET rgb-filter)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(${APP_TARGET} main.cpp)
target_link_libraries(${APP_TARGET})