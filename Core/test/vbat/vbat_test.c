#include "unity/fixture/unity_fixture.h"

#include "mock_alarmSignal.h"
#include "mock_adc.h"

#include "vbat.h"

TEST_GROUP(vbat);

TEST_SETUP(vbat)
{
    /* Init before every test */
    mock_alarmState_init();
    mock_adc_init();

    vbat_init();
}

TEST_TEAR_DOWN(vbat)
{
    /* Cleanup after every test */
}

TEST(vbat, AlarmOffAfterInit)
{
    vbat_init();

    TEST_ASSERT_EQUAL(ALARM_OFF, mock_alarmState_get_alarm_state());
}

TEST(vbat, AlarmOnAfter5TimesCheckAboveTreshold)
{
    for (int i = 0; i < VBAT_COUNTER_ALARM_ON; i++)
    {
        mock_set_adc_value(VBAT_ALARM_ON_TRESHOLD_RAW - 1);
        vbat_checkAlarm();
    }

    TEST_ASSERT_EQUAL(ALARM_ON, mock_alarmState_get_alarm_state());
}

TEST(vbat, WhenAdc4TimesAboveTresholdAnd1TimeUnderTresholdThenAlarmOff)
{
    for (int i = 0; i < 4; i++)
    {
        mock_set_adc_value(VBAT_ALARM_ON_TRESHOLD_RAW - 1);
        vbat_checkAlarm();
    }

    mock_set_adc_value(VBAT_ALARM_ON_TRESHOLD_RAW);
    vbat_checkAlarm();

    TEST_ASSERT_EQUAL(ALARM_OFF, mock_alarmState_get_alarm_state());
}

TEST(vbat, WhenAdc4TimesUnderTresholdAnd1TimeAboveTresholdThenAlarmOff)
{
    for (int i = 0; i < 4; i++)
    {
        mock_set_adc_value(VBAT_ALARM_ON_TRESHOLD_RAW);
        vbat_checkAlarm();
    }

    mock_set_adc_value(VBAT_ALARM_ON_TRESHOLD_RAW - 1);
    vbat_checkAlarm();

    TEST_ASSERT_EQUAL(ALARM_OFF, mock_alarmState_get_alarm_state());
}

TEST(vbat, WhenAdc4TimesUnderTresholdAnd4TimeAboveTresholdThenAlarmOff)
{
    for (int i = 0; i < 4; i++)
    {
        mock_set_adc_value(VBAT_ALARM_ON_TRESHOLD_RAW);
        vbat_checkAlarm();
    }

    for (int i = 0; i < 4; i++)
    {
        mock_set_adc_value(VBAT_ALARM_ON_TRESHOLD_RAW - 1);
        vbat_checkAlarm();
    }

    TEST_ASSERT_EQUAL(ALARM_OFF, mock_alarmState_get_alarm_state());
}

TEST(vbat, WhenAdc4TimesUnderTresholdAnd5TimeAboveTresholdThenAlarmOn)
{
    for (int i = 0; i < 4; i++)
    {
        mock_set_adc_value(VBAT_ALARM_ON_TRESHOLD_RAW);
        vbat_checkAlarm();
    }

    for (int i = 0; i < VBAT_COUNTER_ALARM_ON; i++)
    {
        mock_set_adc_value(VBAT_ALARM_ON_TRESHOLD_RAW - 1);
        vbat_checkAlarm();
    }

    TEST_ASSERT_EQUAL(ALARM_ON, mock_alarmState_get_alarm_state());
}

TEST(vbat, AlarmStillOnAfterMeasComeBackAboveTreshold)
{
    for (int i = 0; i < VBAT_COUNTER_ALARM_ON; i++)
    {
        mock_set_adc_value(VBAT_ALARM_ON_TRESHOLD_RAW - 1);
        vbat_checkAlarm();
    }

    mock_set_adc_value(VBAT_ALARM_ON_TRESHOLD_RAW);
    vbat_checkAlarm();

    TEST_ASSERT_EQUAL(ALARM_ON, mock_alarmState_get_alarm_state());
}

TEST(vbat, AlarmStillOnAfter5InRowMeasComeBackAboveTreshold)
{
    for (int i = 0; i < VBAT_COUNTER_ALARM_ON; i++)
    {
        mock_set_adc_value(VBAT_ALARM_ON_TRESHOLD_RAW - 1);
        vbat_checkAlarm();
    }

    for (int i = 0; i < VBAT_COUNTER_ALARM_ON; i++)
    {
        mock_set_adc_value(VBAT_ALARM_ON_TRESHOLD_RAW);
        vbat_checkAlarm();
    }

    TEST_ASSERT_EQUAL(ALARM_ON, mock_alarmState_get_alarm_state());
}
