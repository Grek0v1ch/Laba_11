cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(laba_11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "-g")

add_executable(laba_11 src/main.cpp
					   src/train/train.hpp
					   src/train/train.cpp
					   src/menu/menu.hpp
					   src/menu/menu.cpp
					   src/data_check/data_check.hpp
					   src/data_check/data_check.cpp)
