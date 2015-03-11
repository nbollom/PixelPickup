cmake_minimum_required(VERSION 2.6)
project (sfml_test)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "SFML static libraries")
set(SFML_BUILD_DOC OFF CACHE BOOL "SFML no docs")
set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "SFML no examples")
set(SFML_BUILD_FRAMEWORKS OFF CACHE BOOL "SFML not building as frameworks")
add_subdirectory(deps/SFML)

set(ENTITYX_BUILD_SHARED OFF CACHE BOOL "EntityX static libraries")
set(ENTITYX_BUILD_TESTING OFF CACHE BOOL "EntityX no testing")
add_subdirectory(deps/entityx)

set(BUILD_DEMOS OFF CACHE BOOL "Chipmunk no demos")
set(BUILD_SHARED OFF CACHE BOOL "Chipmunk no shared libraries")
set(BUILD_STATIC ON CACHE BOOL "Chipmunk static libraries")
add_subdirectory(deps/Chipmunk2D)

add_subdirectory(src)
