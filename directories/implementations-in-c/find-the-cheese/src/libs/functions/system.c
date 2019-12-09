#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#ifdef __unix__
  #include <unistd.h>
#elif defined(_WIN32) || defined(WIN32)
  #include <windows.h>
#endif

int getNumRand(int initValue, int endValue) {
  srand(time(NULL));
  return (initValue + (rand() % (endValue - initValue)));
}

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

void clearScreen() {
  #ifdef __unix__
    system("clear");
  #elif defined(_WIN32) || defined(WIN32)
    system("cls");
  #endif
}
