cmake_minimum_required(VERSION 3.10)
project(os_lab2)

set(CMAKE_CXX_STANDARD 11)

add_executable(run main.cpp min_max.cpp average.cpp)

option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
	include(FetchContent)
	FetchContent_Declare(
		googletest
		URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
	)

	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	FetchContent_MakeAvailable(googletest)

	add_executable(tests tests.cpp min_max.cpp average.cpp)
	target_link_libraries(tests GTest::gtest_main)
endif()
