# Declare the project
# CXX means C++.
project(knapsack CXX)


# Require make version 3.0 minimum
cmake_minimum_required(VERSION 3.0)


# Enable compilation with c++11
# Turn on all warnings and make them errors.
# Also enable a set of sanitizers to handle various
# kinds of undefined behaviors.
set(CMAKE_CXX_FLAGS "-std=c++11 ${SAN_FLAGS}")


# Declares the executable to be built from source files
# Removed Wall because of freqent unsigned vs signed comparisons
add_executable(knapsack main.cpp knapsack.cpp)


set(files knapsack.hpp knapsack.cpp main.cpp)
# This creates a new target for the make program. After
# including this, you can write:
#
#   make printout
#
# And the build system will assemble a PDF containing the
# formatted text in the files listed above. The PDF will
# be created in the build directory and is named "printout.pdf".
# DO NOT MODIFY THIS COMMAND
add_custom_target(printout
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMAND a2ps -Afill -o- ${files} | ps2pdf - ${CMAKE_BINARY_DIR}/printout.pdf)
