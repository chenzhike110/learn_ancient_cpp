cmake_minimum_required(VERSION 3.5)
project(learn_ancient_cpp CXX)

# set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/Bin)

# add_subdirectory(Data_structure)
# add_subdirectory(Algorithm)
# file(GLOB DATA_SRC Data_structure/src/*.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/Data_structure/include
)

add_executable(learn_ancient_cpp	
    main.cpp
)

# target_link_libraries(learn_ancient_cpp PUBLIC Data_structure)  

# target_include_directories(learn_ancient_cpp PUBLIC
#     ${CMAKE_SOURCE_DIR}/Data_structure/include
# )