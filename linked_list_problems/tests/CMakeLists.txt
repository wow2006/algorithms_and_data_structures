add_executable(
  nthToLastNodeTest
  ../nthToLastNode.cpp
  nthToLastNodeTest.cpp
)

target_compile_definitions(
  nthToLastNodeTest
  PUBLIC
  TESTING
)

target_link_libraries(
  nthToLastNodeTest
  PUBLIC
  GUnit
)

add_test(
  NAME    nthToLastNodeTest 
  COMMAND nthToLastNodeTest
)

add_executable(
  addTwoNumbersListsTest 
  ../addTwoNumbersLists.cpp
  addTwoNumbersListsTest.cpp
)

target_compile_definitions(
  addTwoNumbersListsTest 
  PUBLIC
  TESTING
)

target_link_libraries(
  addTwoNumbersListsTest 
  PUBLIC
  GUnit
)

add_test(
  NAME    addTwoNumbersListsTest 
  COMMAND addTwoNumbersListsTest 
)

