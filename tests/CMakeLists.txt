add_executable(rgb-test)
target_sources(rgb-test PRIVATE rgb_test.cpp)
target_link_libraries(rgb-test PRIVATE image-upscaler::image-upscaler)
if(CMAKE_CXX_COMPILER_ID STREQUAL Clang OR CMAKE_CXX_COMPILER_ID STREQUAL GNU)
  target_compile_options(rgb-test PRIVATE
    -Wall -Wextra -Wpedantic -Wconversion -Werror=return-type
  )
endif()
add_test(rgb-test rgb-test)
