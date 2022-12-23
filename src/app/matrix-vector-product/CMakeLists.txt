

cmake_minimum_required(VERSION 3.22)
project(matrix-vector-product LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 23)

# setting up dependencies via conan
include(${CMAKE_SOURCE_DIR}/cmake/utils.cmake)

set(conan_required_packages "armadillo/10.7.3") 
utils_conan_install()
find_package(armadillo)

add_executable(mvp main.cpp)
target_link_libraries(mvp PRIVATE armadillo::armadillo)