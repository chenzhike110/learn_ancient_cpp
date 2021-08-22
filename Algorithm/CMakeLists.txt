file(GLOB ALG_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(Algorithm ALG_SRC)

target_include_directories(Algorithm INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
