

project(snake CXX)

cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 23)

set(conan_required_packages "qt/5.15.7")

include(${CMAKE_SOURCE_DIR}/cmake/utils.cmake)
utils_conan_install()

if(${is_multi_config})
  find_package(Qt5 CONFIG)
else()
  find_package(Qt5)
endif()

add_executable(snake-qt qt_main.cpp engine.cpp qt_gui.cpp)
target_include_directories(snake-qt PRIVATE ${CMAKE_SOURCE_DIR}/src/lib/)
target_link_libraries(snake-qt PRIVATE Qt5::Widgets utils)