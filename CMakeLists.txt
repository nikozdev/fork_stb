cmake_minimum_required(VERSION 3.24)
include(FetchContent)
# proj
set(vProjNameBase Stb)
set(vProjNameDist "p${vProjNameBase}")
set(vProjNameTlib "t${vProjNameBase}Lib")
project(${vProjNameBase} VERSION 0.1)
# lang
enable_language(CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
# file
set(vFileRootBase ${CMAKE_SOURCE_DIR})
set(vFileRootCode ${vFileRootBase}/code)
set(vFileRootMake ${CMAKE_BINARY_DIR})
# make
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_library(${vProjNameTlib} INTERFACE)
target_include_directories(${vProjNameTlib} INTERFACE ${vFileRootCode})
add_library(${vProjNameDist}::${vProjNameTlib} ALIAS ${vProjNameTlib})
