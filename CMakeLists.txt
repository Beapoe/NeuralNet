cmake_minimum_required(VERSION 3.10)
set(NAME NeuralNet)
set(LSOURCE
	src/tools.h
	src/Neuron.h
	src/tools.cpp
	src/Neuron.cpp)
project(${NAME} VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(${NAME} STATIC ${LSOURCE})
target_link_libraries(${NAME} PRIVATE ${NAME}/src)
target_include_directories(${NAME} PRIVATE ${NAME}/src)
