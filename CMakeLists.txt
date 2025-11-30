cmake_minimum_required(VERSION 3.14)
project(tedit)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
file(GLOB SOURCE src/**.cc)
add_executable(tedit ${SOURCE})
