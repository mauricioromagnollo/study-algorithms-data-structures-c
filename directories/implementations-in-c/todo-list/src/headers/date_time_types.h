#ifndef DATE_TIME_TYPES_H_INCLUDED
#define DATE_TIME_TYPES_H_INCLUDED

typedef unsigned short int day_t, month_t; 
typedef unsigned int year_t;
typedef unsigned short int hour_t, minute_t, second_t;

typedef struct {
  day_t day;
  month_t month;
  year_t year;
}date_t;

typedef struct {
  hour_t hour;
  minute_t minute;
  second_t second;
}time_type_t;

#endif // DATE_TIME_TYPES_H_INCLUDED
