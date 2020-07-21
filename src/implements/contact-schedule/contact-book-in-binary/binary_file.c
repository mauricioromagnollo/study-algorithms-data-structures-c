#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "binary_file.h"

#ifdef __unix__
  #include <unistd.h>
#elif defined(_WIN32) || defined(WIN32)
  #include <windows.h>
#endif