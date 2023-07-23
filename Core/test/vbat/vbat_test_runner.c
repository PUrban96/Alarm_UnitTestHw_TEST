#include "unity/fixture/unity_fixture.h"

TEST_GROUP_RUNNER(vbat)
{
   /* Test cases to run */
   RUN_TEST_CASE(vbat, AlarmOffAfterInit);
   RUN_TEST_CASE(vbat, AlarmOnAfter5TimesCheckAboveTreshold);
   RUN_TEST_CASE(vbat, WhenAdc4TimesAboveTresholdAnd1TimeUnderTresholdThenAlarmOff);
   RUN_TEST_CASE(vbat, WhenAdc4TimesUnderTresholdAnd1TimeAboveTresholdThenAlarmOff);
   RUN_TEST_CASE(vbat, WhenAdc4TimesUnderTresholdAnd4TimeAboveTresholdThenAlarmOff);
   RUN_TEST_CASE(vbat, AlarmStillOnAfterMeasComeBackAboveTreshold);
   RUN_TEST_CASE(vbat, AlarmStillOnAfter5InRowMeasComeBackAboveTreshold);
}
