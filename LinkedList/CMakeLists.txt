project(LinkedList CXX)

add_library(
  SinglyLinkedList
  src/SinglyLinkedList.cpp
)

target_include_directories(
  SinglyLinkedList
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(ENABLE_TESTS)
    add_subdirectory(tests)
endif()
