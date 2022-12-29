project(menu CXX)

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


add_executable(simple-menu simple_menu.cpp simple_menu_main.cpp)
target_link_libraries(simple-menu PRIVATE Qt5::Widgets)

add_executable(another-menu another_menu.cpp another_menu_main.cpp)
target_link_libraries(another-menu PRIVATE Qt5::Widgets)

add_executable(checkable-menu checkable.cpp checkable_main.cpp)
target_link_libraries(checkable-menu PRIVATE Qt5::Widgets)

add_executable(toolbar toolbar.cpp toolbar_main.cpp)
target_link_libraries(toolbar PRIVATE Qt5::Widgets)

add_executable(skeleton skeleton.cpp skeleton_main.cpp)
target_link_libraries(skeleton PRIVATE Qt5::Widgets)