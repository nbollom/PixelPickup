cmake_minimum_required(VERSION 2.6)

add_executable(sfml_test main.cpp)
include_directories(${PROJECT_SOURCE_DIR}/deps/SFML/include)
target_link_libraries (sfml_test LINK_PUBLIC sfml-system sfml-window sfml-graphics sfml-audio sfml-network entityx chipmunk_static)
