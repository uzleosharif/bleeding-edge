

macro(utils_conan_run)
    if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake")
        include(${CMAKE_SOURCE_DIR}/cmake/conan.cmake)
        conan_cmake_run(CONANFILE conanfile.txt
                        BASIC_SETUP
                        BUILD missing)
    else()
        include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
        conan_basic_setup()
    endif()
endmacro()