#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

#ifdef __unix__
    #include <unistd.h>
#elif defined(_WIN32) || defined(WIN32)
    #include <windows.h>
#endif

/** DEFININDO TIPO BOOL */
#define TRUE 1
#define FALSE 0
typedef int bool;

/** ESTRUTURA DE DADOS AGENDA */
#define ARQUIVO_DE_DADOS "agenda.dat"

typedef struct {
    int codigo;
    char *nome;
    char *email;
    short int ddd;
    int telefone;
}Item;

typedef struct tipoCelula *Apontador;

typedef struct tipoCelula {
    Item item;
    Apontador prox;
}Celula;

typedef struct {
    Apontador primeiro, ultimo;
    int cont;
}Lista;

typedef Lista Agenda;
typedef Item Contato;

/** INTERFACE AGENDA */
void titleAgenda();
bool menu();
bool vazia(Agenda l);
void cria(Agenda *l);
void insere(Contato x, Agenda *l);
void remove(Apontador p, Agenda *l, Contato *x);
void edita(Apontador p, Contato x, Agenda *l);
Contato newContato();
void exibeContato(Contato x);
void exibeAgenda(Agenda *l);
Apontador buscaCodigo(int codigo, Agenda *l);
Apontador buscaNome(char *nome, Agenda *l);
void libera(Agenda *l);

/** INTERFACE ARQUIVO DE DADOS */
void newfile(char *fileName);
void removefile(char *fileName);
bool existfile(char *fileName);
void writefile(Agenda *l, char *fileName);
void readfile(Agenda *l, char *fileName);

/** AUXILIARES */
void clear();
void buffclear();
void setUTF8();
void pausar(int t_seg);

#endif // AGENDA_H_INCLUDED