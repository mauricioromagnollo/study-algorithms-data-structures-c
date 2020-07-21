/**
 * C - Library
 * x0n4d0
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#ifdef __unix__
  #include <unistd.h>
#elif defined(_WIN32) || defined(WIN32)
  #include <windows.h>
#endif

typedef enum { false, true } bool;

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define ALLOC(obj) do { obj = malloc(sizeof(obj[0]));if (!obj) exit(1);} while (0)
#define REALLOC(obj) do { obj = realloc(obj,sizeof(obj[0]));if (!obj) exit(1);} while (0)
#define REMOVE(obj) (free(obj))
#define MAX(x,y) ((x)<(y) ? (y) : (x))

/*
 * Write with special characteres
 */
void setUTF8();
/*
 * Clear buffer
 */
void clearBuffer();
/*
 * Return current date
 */
char * getDate();
/*
 * Return current time
 */
char * getTime();
/*
 * Parse one Integer in param and code will be paused
 */
void pauseScript(unsigned int timeInSeconds);
/*
 * Parse one init end value to param
 * Return one random number inside the interval params
 */
int getNumRand(int initValue, int endValue);
/*
 * Parse one string to param and returns a Integer
 */
int parseInt(char *string);

/*
 * Parse one number in param and return 1 if pair or 0 case not
 */
unsigned short int isPair(int number);


// unsigned int getStringLengthWithoutLib(const char *str)
// char * getInvertedString(char *string);

#endif // LIBRARY_H_INCLUDED
