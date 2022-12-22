

project(stl CXX)

cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 23)


########### MODULES? ##################
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmodules-ts")
# # everytime we invoke the build tool (e.g. make) we check for gcm.cache and only build `stdimport` target if its not 
# # available (aka pre-compilation as this is needed till we get modules officially supported for std library)
# # TODO: abstract from gcc / linux

# # TODO: make a cmake macro that can be placed at top-level and used in deeper hierarchies
# # TODO: headers should be in a text file and the final custom-command should depend on its changes
# set(std_headers "initializer_list")
# set(gcc_cmd_base "g++ ${CMAKE_CXX_FLAGS_RELEASE} -std=c++${CMAKE_CXX_STANDARD} ${CMAKE_CXX_FLAGS} \
#                      -x c++-system-header ")
# set(gcc_cmd "")
# foreach(h ${std_headers})
#     set(gcc_cmd "${gcc_cmd} ${gcc_cmd_base} ${h};")
# endforeach()

# add_custom_target(ranges-stdimport
#     COMMAND echo "if [ ! -d gcm.cache ]; then ${gcc_cmd} fi" > run.sh
#     COMMAND /bin/sh run.sh
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/
#     VERBATIM
# )
########### MODULES? ##################

add_executable(ranges ranges.cpp)
# add_dependencies(ranges ranges-stdimport)