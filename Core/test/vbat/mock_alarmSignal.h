#pragma once

typedef enum _alarmState_e
{
    ALARM_UNDEFINED = -1,
    ALARM_OFF,
    ALARM_ON,
}alarmState_e;

void mock_alarmState_init(void);
alarmState_e mock_alarmState_get_alarm_state(void);