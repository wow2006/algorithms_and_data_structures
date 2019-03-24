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

  add_test(
    ${test_file_name}
    ${test_file_name}
  )
endmacro()

add_test_case(
  testNthToLastNode
  ../src/nthToLastNode.cpp
)

add_test_case(
  testAddTwoNumbersLists
  ../src/addTwoNumbersLists.cpp
)

add_test_case(
  testSwapNodesWithoutSwappingData
  ../src/swapNodesWithoutSwappingData.cpp
)
