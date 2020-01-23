#include <stdio.h>
#include <time.h>

#include "../headers/date_time.h"

date_t getCurrentDate() {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  return (date_t) {
    (date_digit_type_t)(tm.tm_mday), 
    (date_digit_type_t)(tm.tm_mon + 1), 
    (date_digit_type_t)(tm.tm_year + 1900)
  };
}

date_t newDate(date_digit_type_t day, date_digit_type_t month, date_digit_type_t year) {
  return (date_t){ day, month, year };
}

void printDate(date_t date) {
  printf("%02d/%02d/%d", date.day, date.month, date.year);
}

time_type_t getCurrentTime() {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  return (time_type_t) {
    (time_digit_type_t)(tm.tm_hour),
    (time_digit_type_t)(tm.tm_min),
    (time_digit_type_t)(tm.tm_sec),
  };
}

time_type_t newTime(time_digit_t hours, time_digit_t minutes, time_digit_t seconds) {
  return (time_type_t){ hours, minutes, seconds };
}

void printTime(time_type_t time) {
  printf("%02d:%02d:%02d", time.hours, time.minutes, time.seconds);
}