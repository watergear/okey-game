################ PROJECT NAME #####################

cmake_minimum_required (VERSION 3.0)

project(tests)

set(VERSION 1.0.0)

enable_testing()

################ PACKAGE #####################

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

################ MACRO #####################

set(CMAKE_CXX_STANDARD 11)
add_definitions()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

################ INCLUDE #####################

include_directories("../")
include_directories(${GTEST_INCLUDE_DIRS})

################ SOURCE_FILES #####################

file(GLOB_RECURSE SOURCE_FILES
	../best_solution.cpp
)
file(GLOB_RECURSE TEST_FILES
	./tests.cpp
)

############### HEADERS_FOR_QT ###################

file(GLOB_RECURSE HeaderFiles "./*.h")
add_custom_target(headers SOURCES ${HeaderFiles})

################ BUILD #####################

add_executable(tests ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(tests ${GTEST_LIBRARIES})
target_link_libraries(tests ${CMAKE_THREAD_LIBS_INIT})
add_test(tests tests)
