cmake_minimum_required(VERSION 3.10)

project(vbat_test C)

add_subdirectory(../unity unity)

set(CMAKE_C_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(INCLUDE_DIRS
	../../Core/Src
)

set(TEST_INCLUDE_DIRS
	../../Core/Src
	../unity/core
	../unity/fixture
	.
)

set(SRCS
	../../Core/Src/vbat.c
)

set(TEST_SRCS
    vbat_test_main.c
    vbat_test_runner.c
    vbat_test.c
	mock_alarmSignal.c
	mock_adc.c
)

set(GLOBAL_DEFINES

)

include_directories(${INCLUDE_DIRS} ${TEST_INCLUDE_DIRS})
add_definitions(${GLOBAL_DEFINES})

link_libraries(unity)
add_executable(${PROJECT_NAME} ${SRCS} ${TEST_SRCS})
