cmake_minimum_required(VERSION 3.15)
project(NxtM LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/refs/heads/main.zip)

FetchContent_MakeAvailable(googletest)

add_executable(tests
	test/test_main.cpp
	test/test_vector3.cpp)

target_link_libraries(tests
	gtest
	gtest_main)

include_directories()
