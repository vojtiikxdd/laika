cmake_minimum_required(VERSION 3.10)
project(laika VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBRAW REQUIRED libraw)

add_executable(laika-cli src/main.cpp)

target_link_libraries(laika-cli PRIVATE ${LIBRAW_LIBRARIES})
target_include_directories(laika-cli PRIVATE ${LIBRAW_INCLUDE_DIRS})