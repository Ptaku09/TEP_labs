cmake_minimum_required(VERSION 3.23)
project(Lista3)

set(CMAKE_CXX_STANDARD 98)

add_executable(Lista3 main.cpp src/CTreeStatic/CTreeStatic.cpp src/CTreeStatic/CTreeStatic.h src/CTreeDynamic/CTreeDynamic.cpp src/CTreeDynamic/CTreeDynamic.h src/CNodeDynamic/CNodeDynamic.cpp src/CNodeDynamic/CNodeDynamic.h src/CNodeStatic/CNodeStatic.cpp src/CNodeStatic/CNodeStatic.h)
