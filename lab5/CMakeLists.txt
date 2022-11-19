cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(test1)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(Freetype REQUIRED)
find_package(JPEG REQUIRED)
find_package(SFML 2 COMPONENTS window graphics system REQUIRED)

add_subdirectory(cat)
add_subdirectory(cat_v2)
add_subdirectory(cat_v3)
