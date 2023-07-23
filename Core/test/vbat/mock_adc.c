#include <stdbool.h>
#include <stdint.h>

#include "mock_adc.h"
#include "adc.h"


adc_raw_t adc_value;

adc_raw_t adc_read(void)
{
 return adc_value;
}

void mock_adc_init()
{
    adc_value = 0xFFFF;
}

void mock_set_adc_value(adc_raw_t value)
{
    adc_value = value;
}