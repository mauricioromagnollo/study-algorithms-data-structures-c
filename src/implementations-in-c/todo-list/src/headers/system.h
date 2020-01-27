#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#ifdef __unix__
  #include <unistd.h>
#elif defined(_WIN32) || defined(WIN32)
  #include <windows.h>
#endif

/*
 * Pausa o código durante os segundos passados como parâmetro.
 */
void pauseScript(unsigned int);
/*
 * Permite imprimir com caracteres especiais.
 */
void setUTF8();
/*
 * Limpar o buffer.
 */
void clearBuffer();

#endif // SYSTEM_H_INCLUDED