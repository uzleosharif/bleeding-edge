

cmake_minimum_required(VERSION 3.22)
project(matrix-vector-product LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 23)

# here we list all the required dependencies to be installed via conan (; separated)
set(conan_required_packages "armadillo/10.7.3") 

# setting up dependencies via conan
include(${CMAKE_SOURCE_DIR}/cmake/utils.cmake)
utils_conan_install()

find_package(armadillo)
# # for multi-config build system generator
# find_package(armadillo CONFIG)

# generating targets for this project
add_executable(mvp main.cpp)
target_link_libraries(mvp PRIVATE armadillo::armadillo)