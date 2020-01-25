#ifndef GLOBAL_TYPES_H_INCLUDED
#define GLOBAL_TYPES_H_INCLUDED

/**
 * Tipo Booleano
 */
typedef enum { false, true } bool;

/**
 * Tipo do dígito das datas e horas
 */ 
typedef unsigned int date_digit_type_t, time_digit_type_t;

/* Tipo Data */
typedef struct {
  date_digit_type_t day;
  date_digit_type_t month;
  date_digit_type_t year;
} date_t;

/* Tipo Hora */
typedef struct {
  time_digit_type_t hours;
  time_digit_type_t minutes;
  time_digit_type_t seconds;
} time_type_t;

#endif
