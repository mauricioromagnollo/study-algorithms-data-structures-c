#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "agenda.h"

// ------------------------------------
void titleAgenda() {
    printf("\n************************************\n", );
    printf(" |       AGENDA DE CONTATOS           |\n");
    printf("************************************\n");
}

int menu() {
    int option;
    titleAgenda();
    printf("******************************\n");
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

bool vazia(Agenda l) {
    return(l.primeiro == l.ultimo);
}

void cria(Agenda *l) {
    l->primeiro = (Apontador)malloc(sizeof(Celula));
    l->ultimo = l->primeiro;
    l->ultimo->prox = NULL;
    l->cont = 0;    
}

void insere(Contato x, Agenda *l) {
    l->ultimo->prox = (Apontador)malloc(sizeof(Celula));
    l->ultimo = l->ultimo->prox;
    l->ultimo->item = x;
    l->ultimo->prox = NULL;
    l->cont++;   
}

void remove(Apontador p, Agenda *l, Contato *x) {
    if(vazia(*l) || p == NULL || p->prox == NULL) {
        return FALSE;
    } else {
        Apontador q = p->prox;
        *x = q->item;
        p->prox = q->prox;
        if(p->prox == NULL) {
            l->ultimo = p;
        }
        l->cont--;
        return TRUE;
    }    
}

void edita(Apontador p, Agenda *l, Contato x) {
    printf("\n");
}

Contato newContato() {
    Contato contato;
    char str[100];

    buffclear();
    printf("\nCódigo: ");
    scanf("%d",&contato.codigo);
    buffclear();

    printf("Nome: ");
    gets(str);
    contato.nome = (char *)malloc( strlen(str) * sizeof(char));
    strcpy(contato.nome,str);
    buffclear();

    printf("E-mail: ");
    gets(str);
    contato.email = (char *)malloc( strlen(str) * sizeof(char));
    strcpy(contato.email,str);
    buffclear();

    printf("DDD: ");
    scanf("%hi", &contato.ddd);
    buffclear();

    printf("Telefone: ");
    scanf("%d", &contato.telefone);
    buffclear();

    return contato;
}

void exibeContato(Contato x) {
    printf("-------------------------\n");
    printf("Código:.%d\n", x.codigo);
    printf("Nome:...%s\n", x.nome);
    printf("Email:..%s\n", x.email);
    printf("Número:.(%hi) %d\n",x.ddd,x.telefone);
    printf("-------------------------\n");
}

void exibeAgenda(Agenda *l) {
    if(vazia(*l)) {
        printf("[!] AGENDA VAZIA!\n");
        pausar(2);
        return;
    } else {
       printf("\n**************LISTANDO OS CONTATOS**************\n");
        Apontador q = l->primeiro->prox;
        while(q != NULL) {
            exibeContato(q->item);
            q = q->prox;
        }
        printf("\n**************FIM LISTAGEM CONTATOS**************\n");
    }
}

Apontador buscaCodigo(int codigo, Lista *l) {
    if(vazia(*l)) {
        return NULL;
    } else {
        Apontador q = l->primeiro;
        while(q != NULL) {
            if(q->prox->item.codigo == codigo)
                return q;
            q = q->prox;
        }
        return NULL;
    }
}

Apontador buscaNome(char *nome, Lista *l) {
    if(vazia(*l)) {
        return NULL;
    } else {
        Apontador q = l->primeiro;
        while(q != NULL) {
            if(strcmp(q->prox->item.nome,nome) == 0)
                return q;
            q = q->prox;
        }
        return NULL;
    }
}

void libera(Agenda *l) {
    if(vazia(*l)) {
        return;
    } else {
        Apontador prox, atual;
        atual = l->primeiro->prox;
        while(atual != NULL) {
            prox = atual->prox;
            free(atual);
            atual = prox;
        }
        l->ultimo = l->primeiro;
    }
}

// ------------------------------------

void newfile(char *fileName) {
    FILE *f = fopen(fileName,"w");
    fclose(f);
}

void removefile(char *fileName) {
    remove(fileName);
}

bool existfile(char *fileName) {
    FILE *f;
    if( (f = fopen(fileName,"r")) == NULL)
        return FALSE;
    else {
        return TRUE;
    }
    fclose(f);
}

void writefile(Agenda *l, char *fileName) {
    FILE *f;

    if(f = fopen(fileName,"wb") != NULL) {
        Apontador q = l->primeiro->prox;
        while(q->prox != NULL) {
            fprintf(f,"%d %s %s %hi %d\n",q->item.codigo,q->item.nome,q->item.email,q->item.ddd,q->item.telefone);
            q = q->prox;
        }

    } else {
        printf("[!] Error: Os Dados não foram salvos!");
    }

    fclose(f);
}

void readfile(Agenda *l, char *fileName) {
    printf("\n");
}

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

void pausar(int t_seg) {
    #ifdef __unix__
        sleep(t_seg);
    #elif defined(_WIN32) || defined(WIN32)
        Sleep(t_seg * 1000);
    #endif
}

// ------------------------------------