#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "../headers/system.h"

void pauseScript(unsigned int timeInSeconds) {
  #ifdef __unix__
    sleep(timeInSeconds);
  #elif defined(_WIN32) || defined(WIN32)
    Sleep(timeInSeconds * 1000);
  #endif 
}

void setUTF8() {
  setlocale(LC_ALL,"");
}

void clearBuffer() {
  #ifdef __unix__
    __fpurge(stdin);
  #elif defined(_WIN32) || defined(WIN32)
    fflush(stdin);
  #endif  
}