cmake_minimum_required(VERSION 3.20)
project(test_alg)

set(CMAKE_CXX_STANDARD 11)

add_executable(test_alg main.cpp HeapSort.cpp HeapSort.h Utils.h QuickSort.cpp QuickSort.h MergeSort.cpp MergeSort.h)
