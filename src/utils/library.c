#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <wctype.h>
#include <sys/stat.h>
#include "library.h"

void getUTF8() {
  setlocale(LC_ALL,"");
}

void clearBuffer() {
  #ifdef __unix__
    __fpurge(stdin);
  #elif defined(_WIN32) || defined(WIN32)
    fflush(stdin);
  #endif  
}

char * getDate() {
  return &*__DATE__;
}

char * getTime() {
  return &*__TIME__;
}

void pauseScript(unsigned int timeInSeconds) {
  #ifdef __unix__
    sleep(timeInSeconds);
  #elif defined(_WIN32) || defined(WIN32)
    Sleep(timeInSeconds * 1000);
  #endif 
}

int getNumRand(int initValue, int endValue) {
  return (initValue + (rand() % (endValue - initValue)));
}

int parseInt(char *string) {
  return (int)(atoi(string));
}

unsigned short int isPair(int number) {
  return (unsigned short int)(number % 2 == 0);
}

/*
double calcFatRecursivo(int n) {
  double vfat;
  if ( n <= 1 ) {
  	return (1);
  } else {
     vfat = n * fatRecursivo(n - 1);
     return (vfat);
  }	
}

float calcFat(float num) {
	float fat=1;
    
    if(num == 0 || num == 1) {
      fat = 1;
    } else if(num < 0) {
      fat = -1;
    } else if(num == 2) {
    	fat = num;
    } else {
    	while(num != 1) {
      	fat *= num;
    		num--;
     	}
    }	
     
    return fat;
}

int inverterInt(int num) {
	int aux, num2=0, f;
	aux = num;
	while(aux>0) {
		f = aux % 10;
		num2 = 10*num2+f;
		aux = (int) aux/10;
	}
	return (num2);
}

short int capicua(int num) {
	int aux,aux2,num2=0;
	aux = num;
	while(aux > 0) {
		aux2 = aux % 10;
		num2 = 10*num2+aux2;
		aux = (int) aux/10;
	}

	if(num == num2)
		return 1;
	else
		return 0;
}


void retorna_maior_menor(double *vet, int tam, double *maior, double *menor) {
	short int i=0;
	*maior = DBL_MIN;
	*menor = DBL_MAX;

	for(i=0; i<tam; i++) {
		if(*maior < vet[i])
			*maior = vet[i];
	
		if(*menor > vet[i])
			*menor = vet[i];
	}
}

 {
	if(*a == *b)
		return 1;
	else {
	    double aux;
	    aux = *a;
	    *a = *b;
	    *b = aux;
	    return 0;
	}
}

short int palindrome(char *str) {
	short int _size = strlen(str);
	short int i, j, retorno;
	char strInvert[_size];

  	for(i = 0, j = _size - 1; i < _size; i++, j--) {
		strInvert[i] = str[j];  		
    }

    for(i = 0; i < _size; i++) {
    	if(str[i] != strInvert[i]) {
    		retorno = 0;
    		i = _size;
    	} else {
    		retorno = 1;
    	}
    }

	return retorno;
}

int getEspacos(const char *str) {
	char ch='*';
	int qtdeEspacos=0;
	while(ch != NULL) {
		ch = getch(str);
		if(ch == '')
			qtdeEspacos++;
	}
	return qtdeEspacos;
}

void parseNumRomanoStr(unsigned int numero, char *resultado) {
 	//     char *romanNumber = malloc(sizeof(char) * 1024);

    char *centenas[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char *dezenas[]  = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char *unidades[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    int   size[] = { 0, 1, 2, 3, 2, 1, 2, 3, 4, 2,};

    while (numero >= 1000) {
        *resultado++ = 'M';
         numero -= 1000;
    }

    strcpy (resultado, centenas[numero / 100]); resultado += size[numero / 100]; numero = numero % 100;
    strcpy (resultado, dezenas[numero / 10]);   resultado += size[numero / 10];  numero = numero % 10;
    strcpy (resultado, unidades[numero]);       resultado += size[numero];
}

int *getVetorDinamico(int n) {
	int *vet;
	vet = (int *) malloc(n * sizeof(int));
	return vet;
}

int **getMatrizDinamica(int Linhas, int Colunas) {
	short int i=0,j=0; 
	int **Matriz = (int **)malloc(Linhas * sizeof(int*));

	for(i=0; i<Linhas; i++)
		Matriz[i] = (int *)malloc(Colunas * sizeof(int));

	return Matriz;
}

short int criaArquivo(const char *nomeArquivo) {
	FILE *file;
	file = fopen(nomeArquivo,"w");

	if(file == NULL)
		return 0;
	else
		return 1;

	fclose(file);
}

short int deletaArquivo(const char *nomeArquivo) {
	return(!remove(nomeArquivo));
}

void insertionSort(int original[], int tamanho) {
	int i, j, atual;

	for (i = 1; i < tamanho; i++) {
		atual = original[i];
		for (j = i - 1; (j >= 0) && (atual < original[j]); j--) {
			original[j + 1] = original[j];
        }
		original[j+1] = atual;
	}
}
*/
