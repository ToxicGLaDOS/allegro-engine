cmake_minimum_required(VERSION 3.10)
set(CMAKE_BUILD_TYPE Debug)

option(buildTests "set whether to build the tests directory" OFF)

add_subdirectory(src)
add_subdirectory(examples/pong)
add_subdirectory(examples/hello_world)
add_subdirectory(examples/polygon-test)
add_subdirectory(examples/circles)

if(${buildTests})
	add_subdirectory(tests)
endif(${buildTests})
