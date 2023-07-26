#include <stdbool.h>
#include <stdint.h>

#include "mock_alarmSignal.h"
#include "alarmSignal.h"

alarmState_e alarm;

void alarmOn(void)
{
    alarm = ALARM_ON;
}

void alarmOff(void)
{
    alarm = ALARM_OFF;
}

void mock_alarmState_init(void)
{
    alarm = ALARM_UNDEFINED;
}

alarmState_e mock_alarmState_get_alarm_state(void)
{
    return alarm;
}