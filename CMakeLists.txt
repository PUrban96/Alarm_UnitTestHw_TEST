cmake_minimum_required(VERSION 3.20)

project("Unity_TEST" C CXX ASM)

include(cmake/st-project_vbat_test.cmake)

add_executable(${PROJECT_NAME})
add_st_target_properties_VBAT_TEST(${PROJECT_NAME})