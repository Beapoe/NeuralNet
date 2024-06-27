cmake_minimum_required(VERSION 3.10)
set(NAME NeuralNet)
set(LSOURCE
    src/tools.h
    src/tools.cpp
    src/Neuron.h
    src/Neuron.cpp
	src/Layer.h
	src/Layer.cpp
    src/DataSet.h
    src/DataSet.cpp
    src/ActivationFunction.h
    src/Linear.h
    src/Linear.cpp)
project(${NAME} VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(${NAME} STATIC ${LSOURCE})
target_include_directories(${NAME} PRIVATE ${NAME}/src)
add_executable(${NAME}_test test.cpp)
target_link_libraries(${NAME}_test ${NAME})
