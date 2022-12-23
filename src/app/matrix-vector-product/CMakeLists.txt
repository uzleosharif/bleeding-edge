

cmake_minimum_required(VERSION 3.22)
project(matrix-vector-product LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 23)

# here we list all the required dependencies to be installed via conan (; separated)
set(conan_required_packages "armadillo/10.7.3") 

# setting up dependencies via conan
get_property(is_multi_config GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

include(${CMAKE_SOURCE_DIR}/cmake/utils.cmake)
utils_conan_install()

if(${is_multi_config})
  find_package(armadillo CONFIG)
else()
  find_package(armadillo)
endif()

# generating targets for this project
add_executable(mvp main.cpp)
target_link_libraries(mvp PRIVATE armadillo::armadillo)