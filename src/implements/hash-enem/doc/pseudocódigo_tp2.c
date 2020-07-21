HEADER (.h)
 
typedef struct school{
    int id;
    char rede[20];
    char estado[3];
    char municipio[30];
    float mediacn, mediach, medial, mediam, mediar;
}TEscola;
 
typedef struct celula{
    struct celula *prox;
    TEscola escola;
}TCelula;
 
typedef struct lista{
    TCelula *primeiro, *ultimo;
    int tam;
}TLista;
 
void FazListaVazia(*lista);
 
inteiro VerificaListaVazia(lista);
 
void Inserir(*lista, escola);
 
void Excluir(*lista, id);
 
TipoCelula *Procurar(lista, id);
 
TipoCelula *ProcurarHashTable(hashtable, key, num);
 
void ImprimeEscola(escola);
 
inteiro hashcode(key, M);
 
inteiro NumColisoes(hashtable, M);
 
numflutuante TamMedio(hashtable, M);
 
inteiro NumVazia(hashtable, M);
 
-------------------------------------------------------------------------------------
 
functions (.c)
 
FazListaVazia(*lista){
    lista->primeiro <- aloca memória
    lista->ultimo aponta para lista->primeiro
    lista->primeiro->prox <- NULL
    lista->tam <- 0
}
 
VerificaListaVazia(lista){
    se(lista.tam = 0)
        retorna 1
    fim do se
    senão
        retorna 0
    fim senão
}
 
Inserir(*lista, escola){
    se (lista é vazia)
        lista->primeiro->escola <- escola;
        lista->tam aumenta em 1;
    fim se
    senão
        lista->ultimo->prox <- aloca memória
        lista->ultimo aponta para lista->ultimo->prox;
        lista->ultimo->escola <- escola;
        lista->ultimo->prox <- NULL;
        lista->tam aumenta em 1;
    fim senão
}
 
Procurar(lista, id){
    Cria uma celula *aux
    aux <- aloca memória
    se (lista.primeiro->escola.id = id){
        retorna (lista.primeiro);
    fim se
    senão
        aux <- primeira celula da lista
        enquanto (a prox celula de aux != NULL) faça
            se (aux->prox->escola.id == id)
                retorna aux->prox;
            fim se
            senão
                aux aponta para aux->prox;
            fim senão
        fim enquanto
    fim senão
    retorna NULL;
}
 
ImprimeEscola(escola){
    imprime escola.id
    imprime escola.estado
    imprime escola.municipio
    imprime escola.rede
    imprime escola.mediacn
    imprime escola.mediach
    imprime escola.medial
    imprime escola.mediam
    imprime escola.mediar
}
 
 
ProcurarHashTable(hashtable, key, num){
    pos <-  codigo hash (posicao a ser inserida) de key e num
    retorna a procura de 'key' em hashtable[pos]
}
 
hashcode(key, M){
    retorna o resto de key/M;
}
 
NumColisoes(hashtable, M){
    i <- 0,
    ncol <- 0;
    enquanto i<M faça
        se (a lista hashtable[i] != vazia)
            ncol <-  (tamanho de hashtable[i]) - 1
        fim se
        i aumenta em 1
    fim enquanto
    retorna ncol
}
 
TamMedio(hashtable, M){
    tamtotal <- 0
    i <- 0
    enquanto i<M faça
        tamtotal aumenta em (tamanho de hashtable[i])
    fim enquanto
    retorna tamtotal/M;
}
 
NumVazia(hashtable, M){
    cont <- 0
    i <- 0
    equanto i<M faça
        se hashtable[i] for vazia
            cont aumenta em 1
        fim se
    fim enquanto
    retorna cont
}
 
 
------------------------------------------------------------------------------------
 
main.c
 
O pseudo código da main pode ficar muito confuso, então por isso, apenas irei mostrar o código em C
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"
 
int main(int argc, char *argv[])
{
    clock_t inicio = (float) clock();
 
    if(strcmp(argv[1], "-b") == 0)
    {
        FILE *file;
        file = fopen(argv[2], "rt");
 
        if(file != NULL)
        {
            if(strcmp(argv[3], "-d") == 0)
            {
                FILE *enem;
                enem = fopen(argv[4], "rt");
 
                if(enem != NULL)
                {
                    if(strcmp(argv[5], "-M") == 0)
                    {
                        int M = atoi(argv[6]);
 
                        if(strcmp(argv[7], "-mod") == 0)
                        {
                            int num = atoi(argv[8]);
 
                            char linha[150], *result, *token;
                            int i=0,j;
 
                            TEscola escolas[30228];
 
                            while(!feof(enem))
                            {
 
                                result = fgets(linha, 150, enem);
                                token = strtok(result, ";");
 
                                escolas[i].id = atoi(token);
 
                                j=0;
 
                                while(token != NULL)
                                {
                                    token = strtok(NULL, ";");
                                    j++;
 
                                    if(j==1)
                                    {
                                        strcpy(escolas[i].estado, token);
                                    }
                                    else if(j==2)
                                    {
                                        strcpy(escolas[i].municipio, token);
                                    }
                                    else if(j==3)
                                    {
                                        strcpy(escolas[i].rede, token);
                                    }
                                    else if(j==4)
                                    {
                                        escolas[i].mediach = atof(token);
                                    }
                                    else if(j==5)
                                    {
                                        escolas[i].mediacn = atof(token);
                                    }
                                    else if(j==6)
                                    {
                                        escolas[i].medial = atof(token);
                                    }
                                    else if(j==7)
                                    {
                                        escolas[i].mediam = atof(token);
                                    }
                                    else if(j==8)
                                    {
                                        escolas[i].mediar = atof(token);
                                    }
                                }
 
                                i++;
                            }
                            fclose(enem);
 
                            char linha2[15], *result2;
                            int indice;
 
                            TLista hashtable[M];
 
                            for(i=0; i<M; i++)
                            {
                                FazListaVazia(&hashtable[i]);
                            }
 
                            for(i=0; i<30228; i++)
                            {
                                int pos = hashcode(escolas[i].id, num);
                                Inserir(&(hashtable[pos]), escolas[i]);
                            }
 
                            TCelula *resp;
                            resp = (TCelula*) malloc(sizeof(TCelula));
                            
                            while(!feof(file))
                            {
                                result2 = fgets(linha2, 15, file);
                                indice = atoi(result2);
                                resp = ProcurarHashTable(hashtable, indice, num);
                            }
                            fclose(file);
                        }
                        else
                        {
                            printf("\nArgumento Invalido!");
                        }
                    }lista *lista
                    else
                    {
                        printf("\nArgumento Invalido!");
                    }
                }
                else
                {
                    printf("\nNao foi possivel abrir o arquivo!");
                }
            }
            else
            {
                printf("\nArgumento Invalido!");
            }
        }
        else
        {
            printf("Nao foi possivel abrir o arquivo!");
        }
 
    }
    else
    {
        int id = atoi(argv[1]);
        if(strcmp(argv[2], "-d") == 0)
        {
            FILE *file;
            file = fopen(argv[3], "rt");
 
            ///Carrega dados do arq
 
            if(file == NULL)
            {
                printf("\nNao foi possivel ler o arquivo!");
            }
            else
            {
 
                char linha[150], *result, *token;
                int i=0,j;
 
                TEscola escolas[30228];
 
                while(!feof(file))
                {
 
                    result = fgets(linha, 150, file);
                    token = strtok(result, ";");
 
                    escolas[i].id = atoi(token);
 
                    j=0;
 
                    while(token != NULL)
                    {
                        token = strtok(NULL, ";");
                        j++;
 
                        if(j==1)
                        {
                            strcpy(escolas[i].estado, token);
                        }
                        else if(j==2)
                        {
                            strcpy(escolas[i].municipio, token);
                        }
                        else if(j==3)
                        {
                            strcpy(escolas[i].rede, token);
                        }
                        else if(j==4)
                        {
                            escolas[i].mediach = atof(token);
                        }
                        else if(j==5)
                        {
                            escolas[i].mediacn = atof(token);
                        }
                        else if(j==6)
                        {
                            escolas[i].medial = atof(token);
                        }
                        else if(j==7)
                        {
                            escolas[i].mediam = atof(token);
                        }
                        else if(j==8)
                        {
                            escolas[i].mediar = atof(token);
                        }
                    }
 
                    i++;
                }
                fclose(file);
 
                if(strcmp(argv[4], "-M") == 0)
                {
                    int M = atoi(argv[5]);
                    TLista hashtable[M];
 
                    if(strcmp(argv[6], "-mod") == 0)
                    {
                        int num = atoi(argv[7]);
 
                        for(i=0; i<M; i++)
                        {
                            FazListaVazia(&hashtable[i]);
                        }
 
                        for(i=0; i<30228; i++)
                        {
 
                            int pos = hashcode(escolas[i].id, num);
                            Inserir(&(hashtable[pos]), escolas[i]);
                        }
 
                        TCelula *resp;
                        resp = (TCelula*) malloc(sizeof(TCelula));
                        resp = ProcurarHashTable(hashtable, id, num);
 
                        if(argc > 8)
                        {
                            if(strcmp(argv[8], "-p") == 0)
                            {
                                if(resp != NULL)
                                {
                                    ImprimeEscola(resp->escola);
                                }
                                else
                                {
                                    printf("\nEscola Inexistente");
                                }
                            }
                            else
                            {
                                printf("\nArgumento Invalido!");
                            }
                        }
                        else
                        {
                            if(resp != NULL)
                            {
                                printf("\nEscola Encontrada!");
                            }
                            else
                            {
                                printf("\nEscola Inexistente");
                            }
                        }
                    }
                    else
                    {
                        printf("\nArgumento Invalido!");
                    }
                }
                else
                {
                    printf("\nArgumento Invalido!");
                }
            }
        }
        else
        {
            printf("\nArgumento Invalido!");
        }
    }
 
    clock_t fim = (float) clock();
 
    float tempo = (float) (fim - inicio)*1000 / CLOCKS_PER_SEC;
 
    printf("Tempo gasto: %f ms\n", tempo);
 
    return 0;
}