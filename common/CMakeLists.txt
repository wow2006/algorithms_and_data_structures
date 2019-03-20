# common

# create interface for all projects
add_library(
  common
  INTERFACE
)

# compile flags
target_compile_options(
  common
  INTERFACE
  $<$<CXX_COMPILER_ID:GNU>:-Wall -pedantic>
  $<$<CXX_COMPILER_ID:Clang>:-Weverything -pedantic -Wno-c++98-compat -Wno-global-constructors>
  $<$<CXX_COMPILER_ID:MSVC>:/Wall>
)

# use c++11
target_compile_features(
  common
  INTERFACE
  cxx_std_11
)
