################ PROJECT NAME #####################

cmake_minimum_required (VERSION 3.0)

project(OKeyGameSolver)

set(VERSION 1.0.0)

################ PACKAGE #####################


################ MACRO #####################

set(CMAKE_CXX_STANDARD 11)
add_definitions()

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

################ INCLUDE #####################

include_directories(".")

################ SOURCE_FILES #####################

file(GLOB_RECURSE SOURCE_FILES
	./best_solution.cpp
)

############### HEADERS_FOR_QT ###################

file(GLOB_RECURSE HeaderFiles "./*.h")
add_custom_target(headers SOURCES ${HeaderFiles})

################ BUILD #####################

add_library(OKeyGameSolver SHARED ${SOURCE_FILES})
add_custom_command(
	TARGET OKeyGameSolver POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy
				${CMAKE_CURRENT_SOURCE_DIR}/best_solution.h
				${CMAKE_CURRENT_BINARY_DIR}/OKeyGameSolver.h)
add_custom_command(TARGET OKeyGameSolver COMMENT "Header file: ${CMAKE_CURRENT_BINARY_DIR}/OKeyGameSolver.h")
