cmake_minimum_required(VERSION 3.24)
include(FetchContent)
# proj
project(fork_stb VERSION 0.0)
# lang
enable_language(CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
# file
set(vFileRootBase ${CMAKE_SOURCE_DIR}/..)
set(vFileRootCode ${vFileRootBase}/code)
set(vFileRootMake ${CMAKE_BINARY_DIR})
# make
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(${PROJECT_NAME} ${vFileRootCode}/Main.cpp)
# test
include(CTest)
enable_testing()
function(fMakeTest vName vText)
  add_test(${vName} COMMAND ${vFileRootMake}/${PROJECT_NAME} "test" ${vName})
  set_tests_properties(${vName} PROPERTIES PASS_REGULAR_EXPRESSION ${vText})
endfunction(fMakeTest)
fMakeTest(HelloWorld "=HelloWorld")
