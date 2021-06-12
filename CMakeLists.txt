#Set global variables
cmake_minimum_required(VERSION 3.20.2)
project("Compiler-Compiler")
set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED true)

add_subdirectory(testing)

enable_testing()
add_test(NAME First_Test COMMAND testing/test1)