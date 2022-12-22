

project(hello-app LANGUAGES CXX)
cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 23)

# for module feature
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmodules-ts")

# everytime we invoke the build tool (e.g. make) we check for gcm.cache and only build `stdimport` target if its not 
# available
# TODO: abstract from gcc / linux
add_custom_target(stdimport
    COMMAND echo "if [ ! -d gcm.cache ]; then g++ ${CMAKE_CXX_FLAGS_RELEASE} -std=c++${CMAKE_CXX_STANDARD} ${CMAKE_CXX_FLAGS} -x c++-system-header iostream; fi" > run.sh
    COMMAND /bin/sh run.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/
    VERBATIM
)

add_executable(hello hello.cpp)
add_dependencies(hello stdimport)
