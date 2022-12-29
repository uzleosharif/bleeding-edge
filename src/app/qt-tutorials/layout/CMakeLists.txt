project(layout CXX)

cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 23)
# set

set(conan_required_packages "qt/5.15.7")

include(${CMAKE_SOURCE_DIR}/cmake/utils.cmake)
utils_conan_install()

if(${is_multi_config})
  find_package(Qt5 CONFIG)
else()
  find_package(Qt5)
endif()

add_executable(abs absolute.cpp)
target_link_libraries(abs PRIVATE Qt5::Widgets)

add_executable(vbox vertical_box.cpp vertical_box_main.cpp)
target_link_libraries(vbox PRIVATE Qt5::Widgets)

add_executable(buttons buttons.cpp buttons_main.cpp)
target_link_libraries(buttons PRIVATE Qt5::Widgets)

add_executable(nesting nesting.cpp nesting_main.cpp)
target_link_libraries(nesting PRIVATE Qt5::Widgets)

add_executable(form form.cpp form_main.cpp)
target_link_libraries(form PRIVATE Qt5::Widgets)

add_executable(calculator calculator.cpp calculator_main.cpp)
target_link_libraries(calculator PRIVATE Qt5::Widgets)