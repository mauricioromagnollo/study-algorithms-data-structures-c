
void IniciaAgenda(Agenda *l) {
    // Cria Lista Vazia
    l->primeiro = (Apontador)malloc(sizeof(Celula));
    l->ultimo = l->primeiro;
    l->ultimo->prox = NULL;
    l->cont = 0;

    // Verifica se existem dados
    if(existeArquivo(FILENAME)) {
        // LeAgenda(l,FILENAME);
    } else {
        criaArquivo(FILENAME);
    }
}

void AddContato(Contato x, Agenda *l) {
    Contato x = getContato();
    setContato(x,l);
}

void setContato(Contato x, Agenda *l) {
    l->ultimo->prox = (Apontador)malloc(sizeof(Celula));
    l->ultimo = l->ultimo->prox;
    l->ultimo->item = x;
    l->ultimo->prox = NULL;
    l->cont++;   
}

void RemoveContato(Apontador p, Agenda *l, Contato *x) {
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

bool EditarContato(Apontador p, Lista *l) {
    int codigo;
    Apontador p;
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

void Pesquisa(Agenda *l) {
    int t_pesquisa;
    Apontador aux;
    Contato x;

    printf("[?] Pesquisar por código (1), nome (2), Sair(0)\n> ");
    scanf("%d",&t_pesquisa);

    switch(t_pesquisa) {
        case 0:
            return;
            break;

        case 1: 
            int codigo;
            printf("[*] Digite o código.\n> ");
            scanf("%d",&codigo);
            aux = buscaCodigo(codigo,l);
            if(aux != NULL) {
                Pesquisa(aux,l,&x);
                exibeContato(x);                
            } else {
                printf("[!] Contato não encontrado.\n");
                pausar(1);
                return;
            }

            break;

        case 2:
            char nome[100];
            printf("[*] Digite o nome.\n> ");
            gets(nome);
            aux = buscaNome(nome,l,&x);
            exibeContato(x);
            break;

        default:
            printf("[!] Opção inválida!\n");
            pausar(2);
            return;
            break;
    }
}

void ExibeAgenda(Agenda *l) {
	if(vazia(*l)) {
		printf("[!] AGENDA VAZIA!\n");
		pausar(2);
		return;
	} else {
       printf("\n**************LISTANDO OS CONTATOS**************\n");
        Apontador q = l->primeiro->prox;
        while(q != NULL) {
            exibeItem(q->item);
            q = q->prox;
        }
        printf("\n**************FIM LISTAGEM CONTATOS**************\n");
	}
}

void EncerraAgenda(Agenda *l) {
    // DELETA O ARQUIVO .txt SE EXISTIR
    // CRIA NOVO ARQUIVO
    // ESCREVE DADOS DA AGENDA NO ARQUIVO
    // LIBERA A AGENDA DA MEMÓRIA:
    if(vazia(*l)) {
        return FALSE;
    } else {
        Apontador prox, atual;
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

void EscreveAgenda(Agenda *l, char *fileName) {
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

void LeAgenda(Agenda *l, char *fileName) {

}
// ------------------------------------

/** AUXILIARES */
// ------------------------------------
Item getContato() {
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

void exibeContato(Contato x) {
    printf("-------------------------\n");
    printf("Código:.%d\n", x.codigo);
    printf("Nome:...%s\n", x.nome);
    printf("Email:..%s\n", x.email);
    printf("Número:.(%hi) %d\n",x.ddd,x.telefone);
    printf("-------------------------\n");
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
        return TRUE;
    }
    fclose(f);
}

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