cmake_minimum_required(VERSION 2.6)

SET(CMAKE_CXX_FLAGS "-std=c++0x")

add_executable(pixelpickup main.cpp)
include_directories(${PROJECT_SOURCE_DIR}/deps/SFML/include)
include_directories(${PROJECT_SOURCE_DIR}/deps/Chipmunk2D/include)
include_directories(${PROJECT_SOURCE_DIR}/deps/entityx)
target_link_libraries (pixelpickup LINK_PUBLIC sfml-system sfml-window sfml-graphics sfml-audio sfml-network entityx chipmunk_static)
