#ifndef CALCULADORA_TEMPO_H_INCLUDED
#define CALCULADORA_TEMPO_H_INCLUDED

#include <time.h>

/**
 * {*} Definindo o Tipo de Dado que Calcula Tempo;
 * @type: tempo_t
 */ 
typedef struct {
  clock_t inicio;
  clock_t fim;
  float resultado;
} tempo_t;

/*
 * Inicia contagem de tempo;
 * Inicializa a variável tempo_t->inicio com clock();
 */ 
void iniciarContagemDeTempo(tempo_t *);
/*
 * Finaliza contagem de tempo;
 * Inicializa a variável tempo_t->fim com clock();
 */ 
void pararContagemDeTempo(tempo_t *);
/*
 * Realiza o cálculo do tempo;
 * (float)((tempo_t->fim - tempo_t->inicio) * 1000);
 * O resultado é armazenado em tempo_t->resultado;
 */ 
void calcularTempo(tempo_t *);
/*
 * Exibe o tempo calculado em 'ms';
 */ 
void imprimeTempoCalculado(tempo_t);

#endif