

project(qt-tutorials CXX)

cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 23)

# # get required packages (qt related) via conan
# include(${CMAKE_SOURCE_DIR}/cmake/utils.cmake)
# utils_conan_run()


# include(${CMAKE_SOURCE_DIR}/cmake/conan.cmake)

# conan_cmake_configure(
#   REQUIRES qt/5.15.7
#   GENERATORS cmake_find_package
# )
# conan_cmake_autodetect(settings)
# conan_cmake_install(
#   PATH_OR_REFERENCE .
#   BUILD missing
#   REMOTE conancenter
#   SETTINGS ${settings}
# )