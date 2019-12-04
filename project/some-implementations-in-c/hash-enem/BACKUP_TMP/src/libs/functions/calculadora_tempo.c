
#include <stdio.h>
#include "../headers/calculadora_tempo.h"

void iniciarContagemDeTempo(tempo_t *tempo) {
  tempo->inicio = (float) clock();
}

void pararContagemDeTempo(tempo_t *tempo) {
  tempo->fim = (float) clock();
}

void calcularTempo(tempo_t *tempo) {
  tempo->resultado = ((float)(tempo->fim - tempo->inicio) * 1000);
}

void imprimeTempoCalculado(tempo_t tempo) {
  printf("\n[*] Tempo Gasto: %.2f ms.\n", tempo.resultado);
}
