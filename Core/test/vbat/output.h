#pragma once

#include "main.h"

extern UART_HandleTypeDef huart2;

void output_init(void);
int output_send(int c);
void output_flush(void);
void output_close(void);