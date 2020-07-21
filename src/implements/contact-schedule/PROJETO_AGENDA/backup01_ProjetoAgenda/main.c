#include "agenda.h"

void teste();

int main(int argc, char const *argv[])
{
    teste();
    return 0;
}

void teste() {
    printf("*****TESTE******");
    Lista lista;
    inicializa(&lista);
    Item x = novoContato();
    insere(x,&lista);
    insere(x,&lista);
    insere(x,&lista);
    insere(x,&lista);
    listaContatos(&lista);
    criaArquivo(FILENAME);
    escreveDadosArquivo(FILENAME,&lista);

}

void teste() {

    setUTF8();
    clear();

    Lista lista;
    bool loop = TRUE;

    inicializa(&lista);

    while(loop) {
        clear();
        switch(MenuAgenda()) {
            case 1:
                printf("DDDDD");
                break;
            case 0:
                printf("sssss");
                loop = FALSE;
                break;
            default:
                printf("[!] Error: Invalid option!\n");
                break;
        }
    }
}
