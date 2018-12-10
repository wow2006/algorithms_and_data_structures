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
  NAME AllLinkedLists
  COMMAND nthToLastNodeTest
)

