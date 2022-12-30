project(events CXX)

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

add_executable(click click_main.cpp)
target_link_libraries(click PRIVATE Qt5::Widgets)

add_executable(keypress keypress_main.cpp)
target_link_libraries(keypress PRIVATE Qt5::Widgets)

add_executable(move move.cpp move_main.cpp)
target_link_libraries(move PRIVATE Qt5::Widgets)

add_executable(disconnect disconnect.cpp disconnect_main.cpp)
target_link_libraries(disconnect PRIVATE Qt5::Widgets)