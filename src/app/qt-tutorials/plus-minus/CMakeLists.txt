

project(plus-minus CXX)

cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)

set(conan_required_packages "qt/5.15.7")

include(${CMAKE_SOURCE_DIR}/cmake/utils.cmake)
utils_conan_install()

if(${is_multi_config})
  find_package(Qt5 CONFIG)
else()
  find_package(Qt5)
endif()


add_executable(plus-minus plus_minus.cpp main.cpp)
target_link_libraries(plus-minus PRIVATE Qt5::Widgets)