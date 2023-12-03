cmake_minimum_required(VERSION 3.22)

# creating a custom function to easily add projects
macro(AOC day)
	# set temporary variables
	set(path "aoc_${day}")
	set(project "aoc_${day}")

	# set up project
	project(${project})
	set(CMAKE_C_STANDARD 99)

	# include files global for all solutions
	include_directories(lib_include)

	# add the source file
	add_executable(${project} "${path}/source.c")

	# optionally add the header file if it exists
	if (EXISTS "${path}/header.h")
		add_executable(${PROJECT_NAME} "${path}/header.h")
	endif ()

	unset(${path})
	unset(${project})
endmacro()

# actually create the projects

AOC(1)