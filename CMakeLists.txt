cmake_minimum_required(VERSION 3.10)
set(NAME NeuralNet)
set(LSOURCE
    src/ActivationFunction.h
    src/ActivationFunction.cpp
    src/Neuron.h
    src/Neuron.cpp
    src/Layer.h
    src/Layer.cpp
    src/DataSet.h
    src/DataSet.cpp
    src/NeuralNet.h
    src/NeuralNet.cpp)
project(${NAME} VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(enable_cplusplus ON CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
add_library(${NAME} SHARED ${LSOURCE})
add_subdirectory(src/bdwgc)
target_link_libraries(${NAME} gc gccpp)
add_executable(${NAME}_test test.cpp)
target_link_libraries(${NAME}_test ${NAME})