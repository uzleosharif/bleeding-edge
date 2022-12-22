

project(qt-tutorials CXX)

cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 23)

# conan get required packages (qt related)
include(${CMAKE_SOURCE_DIR}/cmake/utils.cmake)
utils_conan_run()