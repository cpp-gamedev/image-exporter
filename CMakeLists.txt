cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(image-exporter)

add_executable(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC ./include)
target_sources(${PROJECT_NAME} PRIVATE
  include/image_upscaler/image_upscaler.hpp
  src/image_upscaler.cpp
  tests/main.cpp
)

if(CMAKE_CXX_COMPILER_ID STREQUAL Clang OR CMAKE_CXX_COMPILER_ID STREQUAL GNU)
  target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall -Wextra -Wpedantic -Wconversion -Werror=return-type 
  )
endif()
