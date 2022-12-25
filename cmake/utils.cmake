

macro(utils_conan_install)
  get_property(is_multi_config GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

  list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})
  list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_BINARY_DIR})

  include(${CMAKE_SOURCE_DIR}/cmake/conan.cmake)

  foreach(pkg ${conan_required_packages})    
    if(${is_multi_config})
      conan_cmake_configure(REQUIRES ${pkg} GENERATORS cmake_find_package_multi)
      foreach(TYPE ${CMAKE_CONFIGURATION_TYPES})
        conan_cmake_autodetect(settings BUILD_TYPE ${TYPE})      
        conan_cmake_install(
          PATH_OR_REFERENCE .
          BUILD missing
          REMOTE conancenter
          SETTINGS ${settings}
          CONF "tools.system.package_manager:sudo=True"
          CONF "tools.system.package_manager:mode=install"
          OPTIONS "*:shared=True"
        )
      endforeach()
    else()
      conan_cmake_configure(REQUIRES ${pkg} GENERATORS cmake_find_package)
      conan_cmake_autodetect(settings)
      conan_cmake_install(
        PATH_OR_REFERENCE .
        BUILD missing
        REMOTE conancenter
        SETTINGS ${settings}
        CONF "tools.system.package_manager:sudo=True"
        CONF "tools.system.package_manager:mode=install"
        OPTIONS "*:shared=True"
      )
    endif()
  endforeach()
  
endmacro()