#include <stdio.h>
#include <string.h>

#include "./libs/headers/calculadora_tempo.h"
#include "./libs/headers/hashenem.h"

int main(int argc, char *argv[]) {

  tempo_t tempo;
  escola_t escola;
  hashtable_t *hash;
  
  flag_t flagImprimir = false;
  flag_t flagBuscarArquivoIds = false;
  flag_t flagArquivoDeBusca = false;
  
  FILE *arquivoDeBusca = NULL;
  FILE *arquivoIds = NULL;
 
  tamanho_t tamanhoDaHash = 0;
  keymod_t keyMod = 0;
  id_t idParaBuscar = 0;
  posToken_t posicaoDoToken;
  token_t token = NULL;
  linha_t linha = "";

  celula_t *celula;
  
  int hashkey;

  lerArgumentos(argc, argv, &flagImprimir, &flagBuscarArquivoIds, &flagArquivoDeBusca, &tamanhoDaHash, &keyMod, &idParaBuscar);

  if (flagBuscarArquivoIds) {
    arquivoIds = fopen(getCaminhoDoArquivoDeDados(NOME_ARQUIVO_IDS), "r");
    if (!arquivoIds) {
      printf("\n[!] Erro ao abrir o arquivo de IDs!\n\n");
      exit(1);
    }
  }

  arquivoDeBusca = fopen(getCaminhoDoArquivoDeDados(NOME_ARQUIVO_BUSCA), "r");
  if (!arquivoDeBusca) {
    printf("\n[!] Erro ao abrir o arquivo de Busca!\n\n");
    exit(1);
  }

  hash = (hashtable_t *)malloc(tamanhoDaHash * sizeof(hashtable_t));
  if (!hash) {
    printf("[!] Erro ao alocar espaço na Tabela Hash!\n\n");
    exit(1);
  }

  for (int i = 0; i < tamanhoDaHash; i++) {
    criaListaVazia(hash[i].lista);    
  }
  
  iniciarContagemDeTempo(&tempo);

  while (!feof(arquivoDeBusca)) {
    fgets(linha, TAMANHO_DA_LINHA, arquivoDeBusca);
    token = strtok(linha, TOKEN);
    posicaoDoToken = INICIO_POSICAO_TOKEN;

    while (token) {
      posicaoDoToken++;
      switch (posicaoDoToken) {
        case POS_ID:            escola.id = parseInt(token); break;
        case POS_ESTADO:        copyString(token, escola.estado); break;
        case POS_MUNICIPIO:     copyString(token, escola.municipio); break;
        case POS_REDE:          copyString(token, escola.rede); break;
        case POS_CIEN_NATUREZA: escola.mediaCienciasNatureza = parseFloat(token); break;
        case POS_CIEN_HUMANAS:  escola.mediaCienciasHumanas = parseFloat(token); break;
        case POS_LINGUAGEM:     escola.mediaLinguagem = parseFloat(token); break;
        case POS_MAT:           escola.mediaMatematica = parseFloat(token); break;
        case POS_REDACAO:       escola.mediaRedacao = parseFloat(token); break;
        default: break;
      }
      token = strtok(NULL, TOKEN);
    }

    hashkey = getHashCode(escola.id, keyMod);

    celula = procuraNaLista(escola.id, *hash[hashkey].lista);

    if (!celula) {
      insereNaLista(escola, hash[hashkey].lista);
    } else {
      hash->colisao++;
    } 
  }

  pararContagemDeTempo(&tempo);
  calcularTempo(&tempo);

  if (flagBuscarArquivoIds) {
    while (!feof(arquivoIds)) {
      fgets(linha, 30, arquivoIds);
      int txtIds = parseInt(linha);

      if (txtIds > 0) {
        hashkey = getHashCode(txtIds, keyMod);
        celula = procuraNaLista(txtIds, *hash[hashkey].lista);

        if (celula->escola.id < 0) {
          printf("\n[!] Não existe o ID = %d\n", txtIds);
        } else {
          if (!flagImprimir) {
            printf("\n[*] A escola de ID = %d existe!\n", txtIds);
          } else if (flagImprimir) {
            imprimeDadoEscola(celula->escola);
          }
        }
      }
    }
  }

  fclose(arquivoDeBusca);
  fclose(arquivoIds);

  return 0;
}