cmake_minimum_required(VERSION 3.9)

set(project_name STB_Image_lib)
project(${project_name})

set(CMAKE_CXX_STANDARD 20)

set(source 
    ${CMAKE_CURRENT_SOURCE_DIR}/stb_image.cpp
)
set(include_files 
    ${CMAKE_CURRENT_SOURCE_DIR}/stb/stb_image.h
)
set(${include_locations}
    ${CMAKE_CURRENT_SOURCE_DIR}/stb
)

add_library(${project_name} STATIC ${source})
target_include_directories(${project_name} PUBLIC ${include_locations})
