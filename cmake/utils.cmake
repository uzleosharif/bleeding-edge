

macro(utils_conan_install)
  list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})
  list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_BINARY_DIR})

  include(${CMAKE_SOURCE_DIR}/cmake/conan.cmake)

  conan_cmake_configure(
    REQUIRES ${conan_required_packages}
    GENERATORS cmake_find_package
  )

  conan_cmake_autodetect(settings)
  
  conan_cmake_install(
    PATH_OR_REFERENCE .
    BUILD missing
    REMOTE conancenter
    SETTINGS ${settings}
  )
endmacro()