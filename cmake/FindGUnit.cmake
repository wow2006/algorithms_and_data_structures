find_package(GMock REQUIRED)


add_library(
  GUnit
  INTERFACE
)

target_link_libraries(
  GUnit
  INTERFACE
  ${GMOCK_BOTH_LIBRARIES}
  ${GTEST_BOTH_LIBRARIES}
)

target_include_directories(
  GUnit
  INTERFACE
  SYSTEM ${CMAKE_SOURCE_DIR}/3rdparty/GUnit/include/
  SYSTEM ${GTEST_INCLUDE_DIRS}
  SYSTEM ${GMOCK_INCLUDE_DIRS}
)

target_compile_features(
	GUnit
	INTERFACE
	cxx_std_14
)

target_compile_options(
	GUnit
	INTERFACE
	$<$<CXX_COMPILER_ID:GNU>:-Wall -pedantic>
	$<$<CXX_COMPILER_ID:Clang>:-Weverything -pedantic -Wno-c++98-compat -Wno-c++98-compat-pedantic>
	$<$<CXX_COMPILER_ID:MSVC>:/Wall>
)
