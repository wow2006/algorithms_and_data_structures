macro(add_test_case test_file_name file_name)
  add_executable(
    ${test_file_name}
    ${test_file_name}.cpp
    ${file_name}
  )

  target_include_directories(
    ${test_file_name}
    PUBLIC
    ../include
  )

  target_link_libraries(
    ${test_file_name}
    PUBLIC
    common
    GTest::GTest
    GTest::Main
  )

  if(ENABLE_SANITIZE)
    target_compile_options(
      ${test_file_name}
      PUBLIC
      -fsanitize=address
    )

    target_link_options(
      ${test_file_name}
      PUBLIC
      -fsanitize=address
    )
  endif()

  gtest_discover_tests(
    ${test_file_name}
  )
endmacro()

add_test_case(
  testSinglyLinkedList
  ../src/SinglyLinkedList.cpp
)

#add_test_case(
#  testNthToLastNode
#  ../src/nthToLastNode.cpp
#)
#
#add_test_case(
#  testAddTwoNumbersLists
#  ../src/addTwoNumbersLists.cpp
#)
#
#add_test_case(
#  testSwapNodesWithoutSwappingData
#  ../src/swapNodesWithoutSwappingData.cpp
#)
#
