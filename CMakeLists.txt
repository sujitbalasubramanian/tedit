cmake_minimum_required(VERSION 3.14)
project(tedit)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
 
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
  GIT_TAG v6.1.9
)
 
FetchContent_MakeAvailable(ftxui)
 
add_executable(tedit src/tedit.cc)

target_link_libraries(tedit
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)
