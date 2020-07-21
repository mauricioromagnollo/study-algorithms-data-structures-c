#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "agenda.h"

/** INTERFACE AGENDA */
// ------------------------------------
int MenuAgenda() {
    int option;
    printf("\n**********MENU AGENDA*********\n");
    printf("1 - ADICIONAR CONTATO\n");
    printf("2 - REMOVER CONTATO\n");
    printf("3 - LISTAR CONTATOS\n");
    printf("4 - ALTERAR CONTATO\n");
    printf("5 - DELETAR LISTA\n");
    printf("6 - SALVAR LISTA");
    printf("0 - SAIR\n");
    printf("******************************\n");
    printf("> ");
    scanf("%d",&option);
    return option;
}

void IniciaAgenda(Agenda *l) {
    // Cria Lista Vazia
    l->primeiro = (apontador)malloc(sizeof(Celula));
    l->ultimo = l->primeiro;
    l->ultimo->prox = NULL;
    l->cont = 0;

    // Verifica se existem dados
}

// ------------------------------------

/** INTERFACE LISTA */
// ------------------------------------
bool vazia(Lista l) {
    return(l.primeiro == l.ultimo);
}

void insere(Item x, Lista *l) {
    l->ultimo->prox = (apontador)malloc(sizeof(Celula));
    l->ultimo = l->ultimo->prox;
    l->ultimo->item = x;
    l->ultimo->prox = NULL;
    l->cont++;
}

bool listaContatos(Lista *l) {
    if(vazia(*l)) {
        return FALSE;
    } else {
        printf("\n**************LISTANDO OS CONTATOS**************\n");
        apontador q = l->primeiro->prox;
        while(q != NULL) {
            exibe(q->item);
            q = q->prox;
        }
        printf("\n**************FIM LISTAGEM CONTATOS**************\n");
        return TRUE;
    }
}

Item novoContato() {
    Item aux;
    char str[100];

    buffclear();
    printf("\nCódigo: ");
    scanf("%d",&aux.codigo);
    buffclear();
    printf("Nome: ");
    gets(str);
    aux.nome = (char *)malloc( strlen(str) * sizeof(char));
    strcpy(aux.nome,str);
    buffclear();

    printf("E-mail: ");
    gets(str);
    aux.email = (char *)malloc( strlen(str) * sizeof(char));
    strcpy(aux.email,str);
    buffclear();

    printf("DDD: ");
    scanf("%hi", &aux.ddd);
    buffclear();
    printf("Telefone: ");
    scanf("%d", &aux.telefone);
    buffclear();
    return aux;
}

void exibe(Item x) {
    printf("[*] Exibindo contato:\n");
    printf("-------------------------\n");
    printf("Código:.%d\n", x.codigo);
    printf("Nome:...%s\n", x.nome);
    printf("Email:..%s\n", x.email);
    printf("Número:.(%hi) %d\n",x.ddd,x.telefone);
    printf("-------------------------\n");
}

apontador buscaCodigo(int codigo, Lista *l) {
    if(vazia(*l)) {
        return NULL;
    } else {
        apontador q = l->primeiro;
        while(q != NULL) {
            if(q->prox->item.codigo == codigo)
                return q;
            q = q->prox;
        }
        return NULL;
    }
}

apontador buscaNome(char *nome, Lista *l) {
    if(vazia(*l)) {
        return NULL;
    } else {
        apontador q = l->primeiro;
        while(q != NULL) {
            if(strcmp(q->prox->item.nome,nome) == 0)
                return q;
            q = q->prox;
        }
        return NULL;
    }
}

bool retira(apontador p, Lista *l, Item *x) {
    if(vazia(*l) || p == NULL || p->prox == NULL) {
        return FALSE;
    } else {
        apontador q = p->prox;
        *x = q->item;
        p->prox = q->prox;
        if(p->prox == NULL) {
            l->ultimo = p;
        }
        l->cont--;
        return TRUE;
    }
}

bool altera(Lista *l) {
    int codigo;
    apontador p;
    Item x;

    printf("[*] Digite o código do contato a ser alterado.\n> ");
    scanf("%d",&codigo);

    p = buscaCodigo(codigo,l);

    if(retira(p,l,&x)) {
        printf("[*] Contato \"%s\" Encontrado.",x.nome);
        x = novoContato();
        insere(x,l);
        return TRUE;
    } else {
        printf("[!] Error: Contato não encontrado!");
        return FALSE;
    }
}

bool libera(Lista *l) {
    if(vazia(*l)) {
        return FALSE;
    } else {
        apontador prox, atual;
        atual = l->primeiro->prox;
        while(atual != NULL) {
            prox = atual->prox;
            free(atual);
            atual = prox;
        }
        l->ultimo = l->primeiro;
        return TRUE;
    }
}
// ------------------------------------


/** MANIPULAÇÃO DE ARQUIVOS */
// ------------------------------------
void criaArquivo(char *fileName) {
    FILE *f = fopen(fileName,"w");
    fclose(f);
}

void removeArquivo(char *fileName) {
    remove(fileName);
}

bool existeArquivo(char *fileName) {
    FILE *f;
    if( (f = fopen(fileName,"r")) == NULL)
        return FALSE;
    else {
        fclose(f);
        return TRUE;
    }
}

void escreveDadosArquivo(char *fileName, Lista *l) {
    FILE *f;

    if(f = fopen(fileName,"wb") != NULL) {
        apontador q = l->primeiro->prox;
        while(q->prox != NULL) {
            fprintf(f,"%d %s %s %hi %d\n",q->item.codigo,q->item.nome,q->item.email,q->item.ddd,q->item.telefone);
            q = q->prox;
        }

    } else {
        printf("[!] Error: Os Dados não foram salvos!");
    }

    fclose(f);
}
// ------------------------------------

/** AUXILIARES */
// ------------------------------------
void clear() {
	#ifdef __unix__
		system("clear");
	#elif defined(_WIN32) || defined(WIN32)
		system("cls");
	#else
		printf("[!] Erro: void clear()\n");
		pausar(3);
	#endif
}

void buffclear() {
    #ifdef __unix__
        __fpurge(stdin);
    #elif defined(_WIN32) || defined(WIN32)
        fflush(stdin);
    #else
        printf("\t[!] Error: void buffclear()\n");
        pausar(3);
    #endif
}
void setUTF8() {
	setlocale(LC_ALL,"");
}

int numrand(short int __init, short int __end) {
	return (__init + (rand() % (__end- __init)));
}

void pausar(int t_seg) {
    #ifdef __unix__
        sleep(t_seg);
    #elif defined(_WIN32) || defined(WIN32)
        Sleep(t_seg * 1000);
    #endif
}
// ------------------------------------
