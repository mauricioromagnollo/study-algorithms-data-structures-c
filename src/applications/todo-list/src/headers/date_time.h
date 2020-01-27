#ifndef DATE_TIME_H_INCLUDED
#define DATE_TIME_H_INCLUDED

#include "date_time_types.h"
#include "boolean_type.h"

date_t getCurrentDate();
date_t newDate(day_t, month_t, year_t);
bool isDateEquals(date_t, date_t);
bool isDateBefore(date_t, date_t);
void printDate(date_t);

time_type_t getCurrentTime();
time_type_t newTime(hour_t, minute_t, second_t);
bool isTimeEquals(time_type_t, time_type_t);
bool isTimeBefore(time_type_t, time_type_t, bool);
void printTime(time_type_t);

#endif
