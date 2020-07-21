#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

#ifdef __unix__
    #include <unistd.h>
#elif defined(_WIN32) || defined(WIN32)
    #include <windows.h>
#endif

/** ARQUIVO DE DADOS DA AGENDA */
#define FILENAME "agenda.dat"

/** DEFININDO TIPO BOOL */
#define TRUE 1
#define FALSE 0
typedef int bool;

/** ESTRUTURA DE DADOS AGENDA */
typedef struct {
    int codigo;
    char *nome;
    char *email;
    short int ddd;
    int telefone;
}Item;

typedef struct aux *apontador;

typedef struct aux {
    Item item;
    apontador prox;
}Celula;

typedef struct {
    apontador primeiro, ultimo;
    int cont;
}Lista;

typedef Lista Agenda;

/** INTERFACE AGENDA */
int MenuAgenda();
void IniciaAgenda(Agenda *l);
//void AddContato(Agenda *l);
//void RemoverContato(Agenda *l);
//void EditarContato(Agenda *l);
//void Pesquisa(Agenda *l);
//void Exibe(Agenda *l);
//void EncerraAgenda(Agenda *l);

/** INTERFACE LISTA */
void inicializa(Lista *l);
bool vazia(Lista l);
void insere(Item x, Lista *l);
bool listaContatos(Lista *l);
bool retira(apontador p, Lista *l, Item *x);
bool altera(Lista *l);
bool libera(Lista *l);
Item novoContato();
void exibe(Item x);
apontador buscaCodigo(int codigo, Lista *l);
apontador buscaNome(char *nome, Lista *l);

/** MANIPULAÇÃO DE ARQUIVOS */
void criaArquivo(char *fileName);
void removeArquivo(char *fileName);
bool existeArquivo(char *fileName);
void escreveDadosArquivo(char *fileName, Lista *l);
//void leDadosArquivo(char *fileName, Lista *l);

/** AUXILIARES */
void clear();
void buffclear();
void setUTF8();
int numrand(short int __init, short int __end);
void pausar(int t_seg);

#endif // AGENDA_H_INCLUDED
