#include <stdio.h>
#include <time.h>

#include "../headers/date_time.h"

date_t getCurrentDate() {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  return (date_t) {
    (day_t)(tm.tm_mday), 
    (month_t)(tm.tm_mon + 1), 
    (year_t)(tm.tm_year + 1900)
  };
}

date_t newDate(day_t day, month_t month, year_t year) {
  return (date_t){ day, month, year };
}

bool isDateEquals(date_t date1, date_t date2) {
  return (
    date1.day == date2.day && 
    date1.month == date2.month && 
    date1.year == date1.year
  );
}

bool isDateBefore(date_t date1, date_t date2) {
  if (date1.year < date2.year) {
    return true;
  } 
  if (date1.year == date2.year) {
    if (date1.month < date2.month) {
      return true;
    }
    if (date1.month == date2.month) {
      if (date1.day < date2.day) {
        return true;
      }
      if (date1.day == date2.day) {
        return false;
      }
    }
  }

  return false;
}

void printDate(date_t date) {
  printf("%02d/%02d/%d", date.day, date.month, date.year);
}

time_type_t getCurrentTime() {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  return (time_type_t) {
    (hour_t)(tm.tm_hour),
    (minute_t)(tm.tm_min),
    (second_t)(tm.tm_sec),
  };
}

time_type_t newTime(hour_t hour, minute_t minute, second_t second) {
  return (time_type_t){ hour, minute, second };
}

bool isTimeEquals(time_type_t time1, time_type_t time2) {
  return (
    time1.hour == time2.hour &&
    time1.minute == time2.minute
  );
}

bool isTimeBefore(time_type_t time1, time_type_t time2, bool checkSeconds) {
  if (time1.hour < time2.hour) {
    return true;
  }
  if (time1.hour == time2.hour) {
    if (time1.minute < time2.minute) {
      return true;
    }
    if (checkSeconds) {
      if (time1.minute == time2.minute) {
        if (time1.second < time1.second) {
          return true;
        }
      }
    }
  }

  return false;
}

void printTime(time_type_t time) {
  printf("%02d:%02d:%02d", time.hour, time.minute, time.second);
}
