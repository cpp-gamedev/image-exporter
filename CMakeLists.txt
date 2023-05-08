cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(image-upscaler)

option(IMAGE_UPSCALE_TEST "Build image upscale test" ON)

add_library(${PROJECT_NAME})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME}) # this is what other targets will link to
target_include_directories(${PROJECT_NAME} PUBLIC ./include)
target_sources(${PROJECT_NAME} PRIVATE
  include/image_upscaler/image_upscaler.hpp
  src/image_upscaler.cpp
  )

if(IMAGE_UPSCALE_TEST)
    enable_testing()
    add_subdirectory(tests)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL Clang OR CMAKE_CXX_COMPILER_ID STREQUAL GNU)
  target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall -Wextra -Wpedantic -Wconversion -Werror=return-type 
    )
endif()
