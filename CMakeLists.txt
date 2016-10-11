cmake_minimum_required(VERSION 3.6)
project(homework2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp IComparable.cpp IComparable.h OOInt.cpp OOInt.h OOStr.cpp OOStr.h mergeSort.h genericWrapper.h)
add_executable(homework2 ${SOURCE_FILES})
