cmake_minimum_required(VERSION 3.15)
project(FinalProjExamples)

# filesystem.h require C++17
set(CMAKE_CXX_STANDARD 17)

file(COPY sample_data/ DESTINATION sample_data/)

# show compiler output and enable warnings
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

add_executable(rapidJSONExample rapidJSONExample.cpp)
add_executable(supersearch main.cpp)

# this makes sure we also link rapidjson
target_include_directories(rapidJSONExample PRIVATE rapidjson/)

set(CMAKE_VERBOSE_MAKEFILE OFF)

# testing with the single_include versions of Catch2 V2 (in directory catch2)
include(CTest)
add_executable(test_DSAvlTree test_DSAvlTree.cpp)
add_test(NAME TestAvlTree COMMAND test_DSAvlTree)
include(CTest)
add_executable(test_DSHash test_DSHash.cpp)
add_test(NAME TestHash COMMAND test_DSHash)

#add a testDocumentParser
include(CTest)
add_executable(testDocumentParser testDocumentParser.cpp DocumentParser.cpp porter2_stemmer.cpp IndexHandler.cpp)
add_test(NAME testDocumentParser COMMAND testDocumentParser)


