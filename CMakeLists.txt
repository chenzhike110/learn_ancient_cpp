cmake_minimum_required(VERSION 3.13)
project(learn_ancient_cpp)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Data_structure)
add_subdirectory(Algorithm)

target_link_libraries(learn_ancient_cpp 
  PUBLIC Data_structure)
  PUBLIC Algorithm
)

target_include_directories(learn_ancient_cpp 
  ${PROJECT_SOURCE_DIR}/Data_structure
  ${PROJECT_SOURCE_DIR}/Algorithm
)
