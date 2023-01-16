cmake_minimum_required(VERSION 3.22)
project(logic)

set(CMAKE_CXX_STANDARD 17)

add_executable(logic sources/main.cpp includes/Dataset.hpp sources/Dataset.cpp includes/main.hpp sources/NeuralNetwork.cpp includes/NeuralNetwork.hpp sources/Weights.cpp includes/Weights.hpp)
