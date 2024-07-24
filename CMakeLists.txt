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
find_library(GC gc HINTS ${ROOT_DIR}/src/bdwgc/out/Debug)
find_library(CORD cord HINTS ${ROOT_DIR}/src/bdwgc/out/Debug)
add_library(${NAME} SHARED ${LSOURCE})
add_executable(${NAME}_test test.cpp)
if(GC AND CORD)
    message("Found gc.dll")
    message("Found cord.dll")
    target_link_libraries(${NAME} PRIVATE ${GC} ${CORD})
else()
    message(FATAL_ERROR "Could not find gc.dll or cord.dll")
endif()
target_link_libraries(${NAME}_test ${NAME})