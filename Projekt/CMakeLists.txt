cmake_minimum_required(VERSION 3.24)
project(Projekt)

set(CMAKE_CXX_STANDARD 11)

add_executable(Projekt main.cpp src/CKnapsackProblem.cpp src/CKnapsackProblem.h src/CGeneticAlgorithm.cpp src/CGeneticAlgorithm.h src/CIndividual.cpp src/CIndividual.h)
