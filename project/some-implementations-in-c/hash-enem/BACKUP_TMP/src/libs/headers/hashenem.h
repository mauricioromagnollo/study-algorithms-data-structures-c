#ifndef HASHENEM_H_INCLUDED
#define HASHENEM_H_INCLUDED

// =============================================================================
// ESTRUTURA DOS DADOS:
// =============================================================================

/**
 * ----------------------------------------
 * {*} DADOS GLOBAIS E CONSTANTES;
 * ----------------------------------------
 */ 
typedef unsigned int tamanho_t;
typedef unsigned int keymod_t;
typedef enum { false, true } bool;
typedef unsigned short int posToken_t;
typedef bool flag_t;
typedef char * token_t;
#define TAMANHO_DA_LINHA 150
typedef char linha_t[TAMANHO_DA_LINHA];

#define DIRETORIO_DE_DADOS "./data"
#define TOKEN ";"
#define NUMERO_DE_ESCOLAS 30228

#define ARG_TAMANHO_DA_HASH "-M"
#define ARG_ENDERECO_DO_ARQUIVO "-d"
#define ARG_IMPRIMIR "-p"
#define ARG_BUSCA_IDS "-b"
#define ARG_MOD "-mod"

#define NOME_ARQUIVO_BUSCA "dados-enem.txt"
#define NOME_ARQUIVO_IDS "indices.txt"

enum { INICIO_POSICAO_TOKEN, POS_ID, POS_ESTADO, POS_MUNICIPIO, POS_REDE, 
  POS_CIEN_HUMANAS, POS_CIEN_NATUREZA, POS_LINGUAGEM, POS_MAT, POS_REDACAO };

/**
 * ----------------------------------------
 * {*} TIPO DE DADO ESCOLA;
 * @type: escola_t
 * ----------------------------------------
 */ 
typedef unsigned int id_t;
typedef float nota_t;
typedef char estado_t[3];
typedef char municipio_t[30];
typedef char rede_t[20];

typedef struct { 
  id_t id;
  estado_t estado;
  municipio_t municipio;
  rede_t rede;
  nota_t mediaCienciasNatureza, mediaCienciasHumanas, mediaLinguagem,
    mediaMatematica, mediaRedacao;
} escola_t;

/**
 * ----------------------------------------
 * {*} TIPO DE DADO LISTA;
 * @type: lista_t
 * ----------------------------------------
 */ 
typedef struct celula {
  struct celula *prox;
  escola_t escola;
} celula_t;

typedef struct lista {
  celula_t *primeiro, *ultimo;
  tamanho_t tamanho;
} lista_t;

#define SIZE_CELULA_LISTA sizeof(celula_t)

/**
 * ----------------------------------------
 * {*} TIPO DE DADO HASH;
 * @type: hashtable_t
 * ----------------------------------------
 */ 
typedef struct {
  lista_t *lista;
  int colisao;
}hashtable_t;


// =============================================================================
// FUNÇÕES / PROCEDIMENTOS:
// =============================================================================

/** ------------------------------
    ## Funções Dados Escola ##
 -------------------------------- */ 
/*
 * Exibe os dados de uma escola passada como parâmetro;
 */ 
void imprimeDadoEscola(escola_t);


/** ------------------------------
    ## Funções Lista Encadeada ##
 -------------------------------- */
/*
 * Inicializa uma Lista Vazia;
 */ 
void criaListaVazia(lista_t *);
/*
 * Retorna true (1) se a lista estiver vazia ou false (0) caso contrário;
 */
bool isListaVazia(lista_t);
/*
 * Insere uma estrutura escola na lista;
 */
void insereNaLista(escola_t, lista_t *); 
/*
 * Exclui uma escola da lista passando o 'id' como parâmetro;
 */
void excluiDaLista(id_t, lista_t *);
/*
 * Procura o endereço de uma celula contendo uma escola na lista,
 * passando o 'id' como parâmetro;
 */
celula_t * procuraNaLista(id_t, lista_t);


/** ------------------------------
    ## Funções Tabela Hash ##
 -------------------------------- */
/*
 * Retorna o valor da hashcode;
 * return (id % tamanho); 
 */  
int getHashCode(id_t, tamanho_t);
// celula_t * procuraHashTable(hashtable, key, num);
// int getNumColisoes(hashtable, M);
// float getTamanhoMedio(hashtable, M);
// int getNumVazia(hashtable, M); 


/** ------------------------------------
    ## Funções de uso Geral ##
 --------------------------------------- */
/*
 * Transforma uma String passada como parâmetro para Inteiro;
 */  
int parseInt(const char *);
/*
 * Transforma um String passada como parâmetro para Float;
 */
float parseFloat(const char *str);
/*
 * Retorna true (1) se duas strings são iguais ou false (0) caso contrário;
 */
bool isStrEquals(const char *, const char *);
/*
 * Realiza cópia da primeira string passada no parâmetro para a segunda;
 */
void copyString(const char *, char *); 


/** ------------------------------------
    ## Funções Manipulação de Arquivos ##
 --------------------------------------- */
/*
 * Retorna os dados da Escola do arquivo;
 * param <- ponteiroDoArquivo, nomeDoArquivo
 */  
void lerArquivoTexto(FILE *, char *, escola_t *);
/*
 * Retorna o caminho completo do nome do arquivo passado como parâmetro;
 * @param: nomeDoArquivo 
 * 
 * Ex: getCaminhoDoArquivoDeDados("dados-enem.txt") -> "./data/dados-enem.txt"
 */  
char * getCaminhoDoArquivoDeDados(char *);


/** ------------------------------------
    ## Funções para Ler Argumentos ##
 --------------------------------------- */
/*
 * Lê todos os argumentos passado nos parâmetros do executável;
 * $ ./hashenem -d "arquivo.txt" ...
 * 
 * Seta os valores das variáveis utilizando endereço de memória para definir
 * o procedimento que será realizado através dos parâmetros;
 */ 
void lerArgumentos(int, char **, flag_t *, flag_t *, flag_t *, tamanho_t *, keymod_t *, id_t *);


#endif