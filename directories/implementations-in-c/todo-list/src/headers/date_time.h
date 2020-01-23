#ifndef DATE_TIME_H_INCLUDED
#define DATE_TIME_H_INCLUDED

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

/**
 * Retorna a estrutura 'date_t' contendo a data atual.
 */ 
date_t getCurrentDate();

/**
 * Retorna a estrutura 'date_t' com os parâmetros definidos,
 * (dia, mês, ano)
 */
date_t newDate(date_digit_type_t, date_digit_type_t, date_digit_type_t);

/**
 * Imprime a Data atual.
 * Ex: 01/02/2020
 */
void printDate();

/**
 * Retorna a estrutura 'time_type_t' contendo a hora atual.
 */
time_type_t getCurrentTime();

/**
 * Retorna a estrutura 'time_type_t' com os parâmetros definidos,
 * (horas, minutos, segundos)
 */
time_type_t newTime(time_digit_t, time_digit_t, time_digit_t);

/**
 * Imprime a Hora atual.
 * Ex: 23:55:10
 */
void printTime();

#endif