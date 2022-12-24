

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
target_link_libraries(hello Qt5::Core)