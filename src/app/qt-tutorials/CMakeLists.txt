

project(qt-tutorials CXX)

cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 23)

# here we list all the required dependencies to be installed via conan (; separated)
set(conan_required_packages "qt/5.15.7")

# setting up dependencies via conan
include(${CMAKE_SOURCE_DIR}/cmake/utils.cmake)
utils_conan_install()

if(${is_multi_config})
  find_package(Qt5 CONFIG)
else()
  find_package(Qt5)
endif()

# generating targets for this project
add_executable(hello hello_world.cpp)
target_link_libraries(hello PRIVATE Qt5::Core)

add_executable(gui-hello gui_hello.cpp)
target_link_libraries(gui-hello PRIVATE Qt5::Widgets)

add_executable(basic-str strings/basic_string.cpp)
target_link_libraries(basic-str PRIVATE Qt5::Core)

add_executable(initialize-str strings/initialize.cpp)
target_link_libraries(initialize-str PRIVATE Qt5::Core)

add_executable(access-str strings/access.cpp)
target_link_libraries(access-str PRIVATE Qt5::Core)

add_executable(build-str strings/build.cpp)
target_link_libraries(build-str PRIVATE Qt5::Core)

add_executable(sub-str strings/substrings.cpp)
target_link_libraries(sub-str PRIVATE Qt5::Core)

add_executable(compare-str strings/compare.cpp)
target_link_libraries(compare-str PRIVATE Qt5::Core)

add_executable(convert-str strings/convert.cpp)
target_link_libraries(convert-str PRIVATE Qt5::Core)

add_executable(tooltip tooltip.cpp)
target_link_libraries(tooltip PRIVATE Qt5::Widgets)

add_executable(cursors cursors.cpp)
target_link_libraries(cursors PRIVATE Qt5::Widgets)

add_executable(push-button pushbutton.cpp)
target_link_libraries(push-button PRIVATE Qt5::Widgets)

add_subdirectory(plus-minus)
add_subdirectory(menu)
add_subdirectory(layout)