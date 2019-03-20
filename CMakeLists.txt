cmake_minimum_required(VERSION 3.9)

project(anAlgoProbAday CXX)

option(ENABLE_TESTS "" ON)

if(ENABLE_TESTS)
  enable_testing()

  find_package(GTest REQUIRED)
endif()

# create interface for all projects
add_library(Common INTERFACE)

# compile flags
target_compile_options(
	Common
	INTERFACE
	$<$<CXX_COMPILER_ID:GNU>:-Wall -pedantic>
	$<$<CXX_COMPILER_ID:Clang>:-Weverything -pedantic -Wno-c++98-compat>
	$<$<CXX_COMPILER_ID:MSVC>:/Wall>
)

# use c++11
target_compile_features(
	Common
	INTERFACE
	cxx_std_11
)

# dirctory headers
target_include_directories(
	Common
	INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_subdirectory(linked_list_problems)
