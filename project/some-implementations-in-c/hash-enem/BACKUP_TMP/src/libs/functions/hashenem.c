#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/hashenem.h"


/** ------------------------------
    ## Funções Dados Escola ##
 -------------------------------- */ 

void imprimeDadoEscola(escola_t escola) {
  printf("\n============================================\n");
  printf("ID: ....................%hi\n", escola.id);
  printf("ESTADO:.................%s\n", escola.estado);
  printf("MUNICÍPIO:..............%s\n", escola.municipio);
  printf("REDE:...................%s\n", escola.rede);
  printf("## MÉDIAS ##\n");
  printf("CIÊNCIAS DA NATUREZA:...%.2f\n", escola.mediaCienciasNatureza);
  printf("CIÊNCIAS HUMANAS:.......%.2f\n", escola.mediaCienciasHumanas);
  printf("LINGUAGENS:.............%.2f\n", escola.mediaLinguagem);
  printf("MATEMÁTICA:.............%.2f\n", escola.mediaMatematica);
  printf("REDAÇÃO:................%.2f\n", escola.mediaRedacao);
  printf("============================================\n");
}

/** ------------------------------
    ## Funções Lista Encadeada ##
 -------------------------------- */

void criaListaVazia(lista_t *lista) {
  lista->primeiro = (celula_t *)malloc(SIZE_CELULA_LISTA);
  lista->ultimo = lista->primeiro;
  lista->primeiro->prox = NULL;
  lista->tamanho = 0;
}

bool isListaVazia(lista_t lista) {
  return (lista.tamanho == 0);
}

void insereNaLista(escola_t escola, lista_t *lista) {
  if (isListaVazia(*lista)) {
    lista->primeiro->escola = escola;
  } else {
    lista->ultimo->prox = (celula_t *)malloc(SIZE_CELULA_LISTA);
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->escola = escola;
    lista->ultimo->prox = NULL;
  }
  
  lista->tamanho++;
} 

void excluiDaLista(id_t id, lista_t *lista) {
  printf("\n");
}

celula_t * procuraNaLista(id_t id, lista_t lista) {

  if (lista.primeiro->escola.id == id) {
    return (lista.primeiro);
  } else {
    celula_t *aux = (celula_t *)malloc(SIZE_CELULA_LISTA);
    aux = lista.primeiro;

    while (aux->prox != NULL) {
      if (aux->prox->escola.id == id) {
        return (aux->prox);
      } else {
        aux = aux->prox;
      }
    }
  }

  return NULL;

}

/** ------------------------------
    ## Funções Tabela Hash ##
 -------------------------------- */

int getHashCode(id_t key, tamanho_t M) {
  return (key % M);
}

/** ------------------------------------
    ## Funções de uso Geral ##
 --------------------------------------- */

int parseInt(const char *str) {
  return (atoi(str));
}

float parseFloat(const char *str) {
  return (atof(str));
}

bool isEquals(const char *str1, const char *str2) {
  return (strcmp(str1, str2) == 0);
}

void copyString(const char *stringToCopy, char *newString) {
  strcpy(newString, stringToCopy);
}


/** ------------------------------------
    ## Funções Manipulação de Arquivos ##
 --------------------------------------- */

void lerArquivoTexto(FILE *arquivo, char *nomeArquivo, escola_t *escola) {
  
  posToken_t posicaoDoToken = 0;
  token_t token = NULL;
  linha_t linha = "";
  tamanho_t tamanhoDaString = strlen(getCaminhoDoArquivoDeDados(nomeArquivo));
  char *caminhoDoArquivoDeDados = malloc(tamanhoDaString * sizeof(char));

  strcpy(caminhoDoArquivoDeDados, getCaminhoDoArquivoDeDados(nomeArquivo));

  arquivo = fopen(caminhoDoArquivoDeDados, "r");

  while (!feof(caminhoDoArquivoDeDados)) {
    posicaoDoToken = INICIO_POSICAO_TOKEN;
    fgets(linha, TAMANHO_DA_LINHA, caminhoDoArquivoDeDados);
    token = strtok(linha, TOKEN);

    while (token) {
      posicaoDoToken++;

      if (posicaoDoToken == POS_ID) {
        escola->id = parseInt(token);
      } else if (posicaoDoToken == POS_ESTADO) {
        strcpy(escola->estado, token);
      } else if (posicaoDoToken == POS_MUNICIPIO) {
        strcpy(escola->municipio, token);
      } else if (posicaoDoToken == POS_REDE) {
        strcpy(escola->rede, token);
      } else if (posicaoDoToken == POS_CIEN_NATUREZA) {
        escola->mediaCienciasNatureza = parseFloat(token);
      } else if (posicaoDoToken == POS_CIEN_HUMANAS) {
        escola->mediaCienciasHumanas = parseFloat(token);
      } else if (posicaoDoToken == POS_LINGUAGEM) {
        escola->mediaLinguagem = parseFloat(token);
      } else if (posicaoDoToken == POS_MAT) {
        escola->mediaMatematica = parseFloat(token);
      } else if (posicaoDoToken == POS_REDACAO) {
        escola->mediaRedacao = parseFloat(token);
      }

      token = strtok(NULL, TOKEN);
    }
  }
  fclose(arquivo);
}

char * getCaminhoDoArquivoDeDados(char *nomeDoArquivo) {
  int tamanhoDaString = (strlen(DIRETORIO_DE_DADOS) + strlen(nomeDoArquivo));
  char *caminhoDoArquivo = malloc(tamanhoDaString * sizeof(char));
  sprintf(caminhoDoArquivo, "%s/%s", DIRETORIO_DE_DADOS, nomeDoArquivo);
  return (caminhoDoArquivo);
}


/** ------------------------------------
    ## Funções para Ler Argumentos ##
 --------------------------------------- */

void lerArgumentos(int argc, char *argv[], flag_t *flagImprimir, flag_t *flagBuscarArquivosIds, flag_t *flagArquivoDeBusca, tamanho_t *tamanhoDaHash, keymod_t *keyMod, id_t *idParaBusca) {

  if (isStrEquals(argv[1], ARG_BUSCA_IDS)) {
    if (isStrEquals(argv[2], NOME_ARQUIVO_IDS)) {
      *flagBuscarArquivosIds = true;
    }

    if (isStrEquals(argv[3], ARG_ENDERECO_DO_ARQUIVO)) {
      if (isStrEquals(argv[4], NOME_ARQUIVO_BUSCA)) {
        *flagArquivoDeBusca = true;
      }
    }

    if (isStrEquals(argv[5], ARG_TAMANHO_DA_HASH)) {
      tamanhoDaHash = parseInt(argv[6]);
    }

    if (isStrEquals(argv[7], ARG_MOD)) {
      keyMod = parseInt(argv[8]);
    }

    if (argc == 10) {
      *flagImprimir = true;
    }

  } else {
    
    if (parseInt(argv[1]) < 0) {
      printf("[!] ID Inválido!\n");
      exit(1);
    }

    *flagBuscarArquivosIds = false;
    *idParaBusca = parseInt(argv[1]);

    if (isStrEquals(argv[2], ARG_ENDERECO_DO_ARQUIVO)) {
      if (isStrEquals(argv[2], NOME_ARQUIVO_IDS)) {
        *flagBuscarArquivosIds = true;
      }
    }

    if (isStrEquals(argv[4], ARG_TAMANHO_DA_HASH)) {
      *tamanhoDaHash = parseInt(argv[5]);
    }

    if (isStrEquals(argv[6], ARG_MOD)) {
      *keyMod = parseInt(argv[7]);
    }

    if (argc == 9) {
      *flagImprimir = true;
    }
  }
}
