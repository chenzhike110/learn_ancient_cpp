file(GLOB DATA_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(Data_structure DATA_SRC)

target_include_directories(Data_structure INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
