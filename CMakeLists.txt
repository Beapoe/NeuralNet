cmake_minimum_required(VERSION 3.10)
set(NAME NeuralNet)
set(LSOURCE include/tools.h
			include/Layer.h
			include/Neuron.h
			src/tools.cpp
			src/Neuron.cpp)
project(${NAME} VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(lib${NAME} STATIC ${LSOURCE})
target_include_directories(lib${NAME} PRIVATE include)
install(TARGETS lib${NAME} DESTINATION /lib)
