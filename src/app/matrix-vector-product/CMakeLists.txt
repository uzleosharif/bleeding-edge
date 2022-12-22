

project(matrix-vector-product LANGUAGES CXX)

cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 23)

include(${CMAKE_SOURCE_DIR}/cmake/utils.cmake)
utils_conan_run()

add_executable(mvp main.cpp)
target_link_libraries(mvp PRIVATE ${CONAN_LIBS})