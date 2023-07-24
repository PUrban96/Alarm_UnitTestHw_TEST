cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE cmake/gcc-arm-none-eabi.cmake)
# Allow assembler
enable_language(ASM)

project("Unity_TEST" C CXX ASM)

include(cmake/st-project_vbat_test.cmake)
include(cmake/compiler_flags.cmake)

add_executable(${PROJECT_NAME})
add_st_target_properties_VBAT_TEST(${PROJECT_NAME})