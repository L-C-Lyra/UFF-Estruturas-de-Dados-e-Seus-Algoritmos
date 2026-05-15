#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "cliente.c"

#include <dirent.h>
#include <string.h>

typedef struct vetor {
    TCliente *cli;
    int congelado;
} TVet;

void imprime_arquivo(char *nome) {
    FILE *arq; //declara ponteiro para arquivo
    // abre arquivo para leitura
    arq = fopen(nome, "r");
    if (arq != NULL) {// checa se não deu erro na abertura do arquivo
        char linha[150];
        fgets(linha, 150, arq);
        while (!feof(arq)) {//testa se chegou ao final do arquivo
            printf("%s", linha);
            fgets(linha, 150, arq);
        }
        fclose(arq); //fecha arquivo
    } else printf("Erro ao abrir arquivo\n");
}

char *gera_nome_particao(int num_part) {
    char *nome_particao = (char *) malloc(sizeof(char[10]));
    char num_particao[10];

    strcpy(nome_particao, "p");
    sprintf(num_particao, "%d", num_part);
    strcat(nome_particao, num_particao);
    strcat(nome_particao, ".txt");

    return nome_particao;
}


int selecao_substituicao(char *nome_arquivo_entrada, int tam_memoria) {
    FILE *arquivo_entrada = fopen(nome_arquivo_entrada, "r");
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 0;
    }
    TVet *memoria = (TVet *) malloc(tam_memoria * sizeof(TVet));
    for (int i = 0; i < tam_memoria; i++) {
        memoria[i].cli = le_cliente(arquivo_entrada);
        if (memoria[i].cli != NULL) memoria[i].congelado = 0;
        else memoria[i].congelado = 1;
    }
    int num_particao = 0;
    while (1) {
        int existe_cliente = 0;
        for (int i = 0; i < tam_memoria; i++) {
            if (memoria[i].cli != NULL) {
                existe_cliente = 1;
                break;
            }
        }
        if (!existe_cliente) break;
        num_particao++;
        char *nome_arquivo_particao = gera_nome_particao(num_particao);
        FILE *arquivo_particao = fopen(nome_arquivo_particao, "w");
        if (arquivo_particao == NULL) {
            printf("Erro ao criar arquivo de particao.\n");
            free(nome_arquivo_particao);
            fclose(arquivo_entrada);
            break;
        }
        free(nome_arquivo_particao);
        while (1) {
            int menor_idx = -1;
            for (int i = 0; i < tam_memoria; i++) if ((memoria[i].cli != NULL) && (memoria[i].congelado == 0)) if ((menor_idx == -1) || (memoria[i].cli->cod_cliente < memoria[menor_idx].cli->cod_cliente)) menor_idx = i;
            if (menor_idx == -1) break;
            salva_cliente(memoria[menor_idx].cli, arquivo_particao);
            int ultimo_cod_cliente = memoria[menor_idx].cli->cod_cliente;
            TCliente *novo = le_cliente(arquivo_entrada);
            if (novo != NULL) {
                free(memoria[menor_idx].cli);
                memoria[menor_idx].cli = novo;
                if (novo->cod_cliente < ultimo_cod_cliente) memoria[menor_idx].congelado = 1;
                else memoria[menor_idx].congelado = 0;
            } else {
                free(memoria[menor_idx].cli);
                memoria[menor_idx].cli = NULL;
                memoria[menor_idx].congelado = 1;
            }
        }
        fclose(arquivo_particao);
        for (int i = 0; i < tam_memoria; i++) if (memoria[i].cli != NULL) memoria[i].congelado = 0;
    }
    free(memoria);
    fclose(arquivo_entrada);
    return num_particao;
}

int main() {
    int tam_memoria;
    scanf("%d", &tam_memoria);
    int num_part = selecao_substituicao("entrada.txt", tam_memoria);
    for (int i = 1; i < num_part+1; i++) {
        printf("*** %s\n", gera_nome_particao(i));
        imprime_arquivo(gera_nome_particao(i));
    }
}