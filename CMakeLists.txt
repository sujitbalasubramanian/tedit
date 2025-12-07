cmake_minimum_required(VERSION 3.14)
project(tedit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

include_directories(include)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB_RECURSE SOURCE CONFIGURE_DEPENDS src/*.cc)

add_executable(${PROJECT_NAME} ${SOURCE})

target_compile_options(${PROJECT_NAME} PRIVATE ${SDL2_CFLAGS_OTHER})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})

find_package(GTest REQUIRED)
file(GLOB TEST_SOURCES CONFIGURE_DEPENDS test/*.cc)

add_executable(${PROJECT_NAME}_tests ${TEST_SOURCES})

target_link_libraries(${PROJECT_NAME}_tests
    PRIVATE
    GTest::gtest
    GTest::gtest_main
    ${SDL2_LIBRARIES}
)

add_test(
    NAME ${PROJECT_NAME}_tests
    COMMAND ${PROJECT_NAME}_tests
)
