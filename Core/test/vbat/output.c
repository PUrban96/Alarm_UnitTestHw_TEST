#include "main.h"
#include "stm32f4xx_hal.h"
#include "output.h"

void output_init(void)
{

}

int output_send(int c)
{
    HAL_UART_Transmit(&huart2, (uint8_t*) &c, 1, 1000);
}

void output_flush(void)
{

}

void output_close(void)
{

}