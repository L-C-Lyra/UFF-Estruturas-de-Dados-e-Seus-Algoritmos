#include <stdio.h>
#include "metadados.c"
#include "no_interno.c"

void imprime_arquivos() {
    int i;
    //Imprime arquivo de metadados
    FILE *arq_m = fopen("metadados.dat", "rb");
    TMetadados *m = le_metadados(arq_m);
    printf("*** Arquivo de Metadados ***\n");
    imprime_metadados(m);
    fclose(arq_m);

    //Imprime arquivo de índice (nós internos da árvore)
    //A leitura não segue ordem específica -- os nós são lidos na ordem em que foram gravados no arquivo
    FILE *arq_i = fopen("indice.dat", "rb");
    printf("\n\n*** Arquivo de Indice ***\n");
    i = 0;
    TNoInterno *ni = le_no_interno(m->d, arq_i);
    while (ni != NULL) {
        printf("(((Endereco %d)))\n", i * tamanho_no_interno(m->d));
        imprime_no_interno(m->d, ni);
        ni = le_no_interno(m->d, arq_i);
        i += 1;
    }
    fclose(arq_i);

    //Imprime arquivo de dados (nós folha da árvore)
    //A leitura não segue ordem específica -- os nós são lidos na ordem em que foram gravados no arquivo
    FILE *arq_d = fopen("clientes.dat", "rb");
    printf("\n*** Arquivo de Dados ***\n");
    i = 0;
    TNoFolha *nf = le_no_folha(m->d, arq_d);
    while (nf != NULL) {
        printf("(((Endereco %d)))\n", i * tamanho_no_folha(m->d));
        imprime_no_folha(m->d, nf);
        nf = le_no_folha(m->d, arq_d);
        i += 1;
    }
    fclose(arq_d);
}

/*
 * Executa busca em Arquivos utilizando Arvore B+
 * Assumir que ponteiros para NULL têm valor -1
 *
 * chave: chave do cliente que esta sendo buscado
 * nome_arquivo_metadados: nome do arquivo binário que contem os metadados
 * nome_arquivo_indice: nome do arquivo binário de indice (que contem os nohs internos da arvore B+)
 * nome_arquivo_dados: nome do arquivo binário de dados (que contem as folhas da arvore B+)
 *
 * Retorna ponteiro para nó em que a chave está ou deveria estar
 */
int busca(int chave, char *nome_arquivo_metadados, char *nome_arquivo_indice, char *nome_arquivo_dados) {
	FILE *arquivo_metadados = fopen(nome_arquivo_metadados, "rb");
    if (arquivo_metadados == NULL) return -1;
    TMetadados *metadados = le_metadados(arquivo_metadados);
    fclose(arquivo_metadados);
    if (metadados == NULL) return -1;
    int d = metadados->d;
    int endereco_folha_resultado = -1;
    if (metadados->raiz_folha) {
        FILE *arquivo_dados = fopen(nome_arquivo_dados, "rb");
        if (arquivo_dados != NULL) {
            fseek(arquivo_dados, metadados->pont_raiz, SEEK_SET);
            TNoFolha *no_folha = le_no_folha(d, arquivo_dados);
            if (no_folha != NULL) {
                imprime_no_folha(d, no_folha);
                for (int i = 0; i < 2 * d; i++) if (no_folha->clientes[i] != NULL) free(no_folha->clientes[i]);
                free(no_folha->clientes);
                free(no_folha);
            }
            fclose(arquivo_dados);
        }
        endereco_folha_resultado = metadados->pont_raiz;
    } else {
        FILE *arquivo_indice = fopen(nome_arquivo_indice, "rb");
        FILE *arquivo_dados = fopen(nome_arquivo_dados, "rb");
        if ((arquivo_indice != NULL) && (arquivo_dados != NULL)) {
            int endereco_atual = metadados->pont_raiz;
            int na_folha = 0;
            while (!na_folha) {
                fseek(arquivo_indice, endereco_atual, SEEK_SET);
                TNoInterno *no_interno = le_no_interno(d, arquivo_indice);
                if (no_interno == NULL) break;
                imprime_no_interno(d, no_interno);
                int idx = 0;
                while ((idx < no_interno->m) && (chave >= no_interno->chaves[idx])) idx++;
                int proximo_endereco = no_interno->p[idx];
                if (no_interno->aponta_folha) {
                    na_folha = 1;
                    endereco_folha_resultado = proximo_endereco;
                    fseek(arquivo_dados, proximo_endereco, SEEK_SET);
                    TNoFolha *no_folha = le_no_folha(d, arquivo_dados);
                    if (no_folha != NULL) {
                        imprime_no_folha(d, no_folha);
                        for (int i = 0; i < 2 * d; i++) if (no_folha->clientes[i] != NULL) free(no_folha->clientes[i]);
                        free(no_folha->clientes);
                        free(no_folha);
                    }
                } else endereco_atual = proximo_endereco;
                free(no_interno->p);
                free(no_interno->chaves);
                free(no_interno);
            }
        }
        if (arquivo_indice != NULL) fclose(arquivo_indice);
        if (arquivo_dados != NULL) fclose(arquivo_dados);
    }
    free(metadados);
    return endereco_folha_resultado;
}

int main () {
    //Descomente essa linha de código caso deseje imprimir o conteúdo dos arquivos de entrada para analisar
    //o comportamento da sua implementação

    //imprime_arquivos();

    /* Le chave a ser buscada */
    int chave;

    scanf("%d", &chave);

    //Chama função de busca
    int pont = busca(chave, "metadados.dat", "indice.dat", "clientes.dat");

    //Imprime resultado da função
    printf("RESULTADO DA BUSCA: %d", pont);
}