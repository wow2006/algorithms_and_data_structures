cmake_minimum_required(VERSION 3.9)

project(anAlgoProbAday CXX)

list(APPEND ${CMAKE_SOURCE_DIR}/cmake/modules)

option(ENABLE_TESTS    "" ON)

if(ENABLE_TESTS)
  enable_testing()

  find_package(GTest REQUIRED)
endif()

add_subdirectory(common)
add_subdirectory(LinkedList)

