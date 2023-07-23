 #pragma once
 
 #define VBAT_ALARM_ON_TRESHOLD_RAW 2850
 #define VBAT_COUNTER_ALARM_ON      5

 void vbat_init();
 void vbat_checkAlarm();
