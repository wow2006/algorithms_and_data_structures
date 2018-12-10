cmake_minimum_required(VERSION 3.9)

project(anAlgoProbAday CXX)

# create interface for all projects
add_library(Common INTERFACE)

# compile flags
target_compile_options(
	Common
	INTERFACE
	$<$<CXX_COMPILER_ID:GNU>:-Wall -pedantic>
	$<$<CXX_COMPILER_ID:Clang>:-Weverything -pedantic>
	$<$<CXX_COMPILER_ID:MSVC>:/Wall>
)

# use c++11
target_compile_features(
	Common
	INTERFACE
	cxx_std_11
)

# dirctory headers
target_include_directories(
	Common
	INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Files
file(GLOB SOURCES "./*/*.cpp")

foreach( sourcefile ${SOURCES} )
        get_filename_component(demo_name ${sourcefile} NAME_WE)

		if (${demo_name} STREQUAL "pstring")

			add_library(pstring ${sourcefile})

			target_link_libraries(pstring PUBLIC Common)

            continue()
		endif()

		if (${demo_name} STREQUAL "pUnitTest")
			add_library(pUnitTest ${sourcefile})

            continue()
		endif()

        add_executable( ${demo_name} ${sourcefile} )
		if (${demo_name} STREQUAL "pstring_test")
			target_link_libraries (${demo_name} pstring pUnitTest)
		else()
            target_link_libraries(${demo_name} PUBLIC Common)
		endif()
endforeach( sourcefile ${SOURCES} )
