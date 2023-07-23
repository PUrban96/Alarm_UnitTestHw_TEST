#include <stdbool.h>
#include <stdint.h>

#include "vbat.h"

#include "adc.h"
#include "alarmSignal.h"

int checkCounter = 0;

void vbat_init()
{
   checkCounter = 0;
   alarmOff();
}

void vbat_checkAlarm()
{
   if (adc_read() < VBAT_ALARM_ON_TRESHOLD_RAW)
   {
      checkCounter++;
   }
   else
   {
      checkCounter = 0;
   }

   if (checkCounter >= VBAT_COUNTER_ALARM_ON)
   {
      alarmOn();
   }
}
