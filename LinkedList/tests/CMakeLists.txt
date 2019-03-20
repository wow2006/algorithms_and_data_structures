add_executable(
    testNthToLastNode
    testNthToLastNode.cpp
)

target_include_directories(
    testNthToLastNode
    PUBLIC
    ../include
)

target_link_libraries(
    testNthToLastNode
    PUBLIC
    common
    GTest::GTest
    GTest::Main
)

add_test(
    testNthToLastNode
    testNthToLastNode
)
