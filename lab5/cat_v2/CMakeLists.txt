add_executable(cat_v2 main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(Freetype REQUIRED)
find_package(JPEG REQUIRED)
find_package(SFML 2 COMPONENTS window graphics system REQUIRED)

target_include_directories(cat PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(cat PUBLIC cxx_std_17)
target_compile_definitions(cat PRIVATE SFML_STATIC)

target_link_libraries(cat_v2 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
