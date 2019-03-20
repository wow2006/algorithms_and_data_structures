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
  GTest::GTest
  GTest::Main
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
  GTest::GTest
  GTest::Main
)

add_test(
  NAME    addTwoNumbersListsTest 
  COMMAND addTwoNumbersListsTest 
)

add_executable(
  cloneListWithRandomPtrTest
  ../cloneListWithRandomPtr.cpp
  cloneListWithRandomPtrTest.cpp
)

target_compile_definitions(
  cloneListWithRandomPtrTest
  PUBLIC
  TESTING
)

target_link_libraries(
  cloneListWithRandomPtrTest
  PUBLIC
  GTest::GTest
  GTest::Main
)

add_test(
  NAME    cloneListWithRandomPtrTest
  COMMAND cloneListWithRandomPtrTest 
)

