cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(Ocean_sim LANGUAGES CXX)

add_library(additional_files STATIC Main.cpp Ocean.cpp Predator.cpp Prey.cpp EmptyEntity.hpp Food.hpp IEntity.hpp Obstacle.hpp Ocean.hpp Predator.hpp Prey.hpp)

add_executable(Ocean Main.cpp)

target_link_libraries(Ocean additional_files)