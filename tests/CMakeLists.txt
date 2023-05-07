if(IMAGE_UPSCALE_TEST)
  add_subdirectory(tests)
endif()

## tests/CMakeLists.txt
add_executable(upscale-test)
target_link_libraries(upscale-test PRIVATE image-upscaler::image-upscaler)
target_sources(upscale-test PRIVATE main.cpp)
if(CMAKE_CXX_COMPILER_ID STREQUAL Clang OR CMAKE_CXX_COMPILER_ID STREQUAL GNU)
  target_compile_options(upscale-test PRIVATE
    -Wall -Wextra -Wpedantic -Wconversion -Werror=return-type 
    )

endif()
