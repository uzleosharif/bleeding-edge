

project(matrix-vector-product LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

# to do conan install within cmake script
if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake")
    include(${CMAKE_SOURCE_DIR}/cmake/conan.cmake)
    conan_cmake_run(CONANFILE conanfile.txt
                    BASIC_SETUP
                    BUILD missing
    )
else()
    include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
endif()


add_executable(mvp main.cpp)
target_link_libraries(mvp PRIVATE ${CONAN_LIBS})