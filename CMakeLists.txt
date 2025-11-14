cmake_minimum_required(VERSION 0.0)
project(NxtM C++)

include(FetchContent)

FetchContent_Declare(
	googletest
	URL https://github.com/google.com/google/googletest/archive/refs/heads/main.zip)

FetchContent_MakeAvailable(googletest)

add_executable(tests
	)

target_link_libraries(tests
	gtest_main)

include_directories()
