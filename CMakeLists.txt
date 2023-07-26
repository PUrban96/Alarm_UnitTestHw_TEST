cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE cmake/gcc-arm-none-eabi.cmake)
# Allow assembler
enable_language(ASM)

project("Unity_TEST" C CXX ASM)



set(INCLUDE_DIRS_HAL_LIB

    Drivers/STM32F4xx_HAL_Driver/Inc
    Drivers/STM32F4xx_HAL_Driver/Inc/Legacy
    Drivers/CMSIS/Device/ST/STM32F4xx/Include
    Drivers/CMSIS/Include
)
set(INCLUDE_DIRS_APP

    Core/Inc
    Core/Src
)
set(INCLUDE_DIRS_TEST

    Core/test/vbat
    Core/test/unity
    Core/test/unity/fixture
    Core/test/unity/core
)



set(GLOBAL_DEFINES
    -DDEBUG
    -DUNITY_INCLUDE_CONFIG_H
    -DUSE_HAL_DRIVER
    -DSTM32F446xx
)


set(C_SRCS_HAL_LIB

    Core/Src/stm32f4xx_hal_msp.c
    Core/Src/stm32f4xx_it.c
    Core/Src/syscalls.c
    Core/Src/sysmem.c
    Core/Src/system_stm32f4xx.c
    Core/Startup/startup_stm32f446retx.s
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
)
set(C_SRCS_APP

    Core/Src/main.c
    Core/Src/vbat.c
    Core/Src/adc.c
    Core/Src/alarmSignal.c
)
set(C_SRCS_TEST

    Core/test/vbat/vbat_test_runner.c
    Core/test/vbat/vbat_test.c
    Core/test/vbat/mock_alarmSignal.c
    Core/test/vbat/mock_adc.c
    Core/test/vbat/output.c

    Core/test/unity/core/unity.c
    Core/test/unity/fixture/unity_fixture.c
)

include(cmake/compiler_flags.cmake)

add_executable(${PROJECT_NAME} ${C_SRCS_HAL_LIB} ${C_SRCS_APP})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${INCLUDE_DIRS_HAL_LIB} ${INCLUDE_DIRS_APP})
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE ${GLOBAL_DEFINES})


add_custom_command(
    TARGET ${PROJECT_NAME} 
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${PROJECT_NAME}>
)

#generate hex file
add_custom_command(
    TARGET ${PROJECT_NAME} 
    COMMAND ${CMAKE_OBJCOPY} -O ihex
    $<TARGET_FILE:${PROJECT_NAME}> ${PROJECT_NAME}.hex
)

#generate bin file
add_custom_command(
    TARGET ${PROJECT_NAME} 
    COMMAND ${CMAKE_OBJCOPY} -O binary
    $<TARGET_FILE:${PROJECT_NAME}> ${PROJECT_NAME}.bin
)

#generate extended listing
add_custom_command(
    TARGET ${PROJECT_NAME} 
    COMMAND ${CMAKE_OBJDUMP} -h -S
        $<TARGET_FILE:${PROJECT_NAME}> > ${PROJECT_NAME}.lss
)

#generate memory dump
add_custom_command(
    TARGET ${PROJECT_NAME} 
    COMMAND ${CMAKE_OBJDUMP} -x --syms
        $<TARGET_FILE:${PROJECT_NAME}> > ${PROJECT_NAME}.dmp
)





