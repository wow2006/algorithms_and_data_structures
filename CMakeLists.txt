cmake_minimum_required(VERSION 3.1)

project(anAlgoProbAday CXX)

set(CMAKE_CXX_STANDARD 11)

list(APPEND ${CMAKE_SOURCE_DIR}/cmake/modules)

option(ENABLE_TESTS    "" ON)

if(ENABLE_TESTS)
  enable_testing()

  find_package(GTest REQUIRED)
endif()

add_subdirectory(common)
add_subdirectory(LinkedList)

