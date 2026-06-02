#include <limits.h>
#include <stdio.h>

#include "cliente.c"
#include "compartimento_hash.c"

#define M 7

void imprime_arquivos(char *nome_arquivo_hash, char *nome_arquivo_dados) {
    //Imprime arquivo de hash
    printf("TABELA HASH:\n");
    imprime_arquivo_hash(nome_arquivo_hash);

    //Imprime arquivo de dados
    printf("\nDADOS:\n");
    imprime_arquivo_dados(nome_arquivo_dados);
}

/* Executa insercao em Arquivos por Encadeamento Exterior (Hash)
 * cod_cli: chave do cliente que esta sendo inserido
 * nome_cli: nome do cliente a ser inserido
 * nome_arquivo_hash: nome do arquivo que contem a tabela hash
 * nome_arquivo_dados: nome do arquivo onde os dados estao armazenados
 * Retorna o endereco (lógico) onde o cliente foi inserido, ou -1 se nao conseguiu inserir
 */
int insere(int cod_cli, char *nome_cli, char *nome_arquivo_hash, char *nome_arquivo_dados, int m) {
    FILE *arquivo_hash = fopen(nome_arquivo_hash, "rb+");
    FILE *arquivo_dados = fopen(nome_arquivo_dados, "rb+");
    if ((arquivo_hash == NULL) || (arquivo_dados == NULL)) {
        if (arquivo_hash != NULL) fclose(arquivo_hash);
        if (arquivo_dados != NULL) fclose(arquivo_dados);
        return -1;
    }
    int h = cod_cli % m;
    fseek(arquivo_hash, h * tamanho_compartimento(), SEEK_SET);
    TCompartimento *comp = le_compartimento(arquivo_hash);
    if (comp == NULL) {
        fclose(arquivo_hash);
        fclose(arquivo_dados);
        return -1;
    }
    if (comp->prox == -1) {
        fseek(arquivo_dados, 0, SEEK_END);
        int novo_cli_pos = ftell(arquivo_dados) / tamanho_cliente();
        TCliente *novo_cli = cliente(cod_cli, nome_cli, -1, 1);
        salva_cliente(novo_cli, arquivo_dados);
        free(novo_cli);
        comp->prox = novo_cli_pos;
        fseek(arquivo_hash, h * tamanho_compartimento(), SEEK_SET);
        salva_compartimento(comp, arquivo_hash);
        free(comp);
        fclose(arquivo_hash);
        fclose(arquivo_dados);
        return novo_cli_pos;
    } else {
        int curr_cli_pos = comp->prox;
        int prev_cli_pos = -1;
        int liberado_cli_pos = -1;
        while (curr_cli_pos != -1) {
            fseek(arquivo_dados, curr_cli_pos * tamanho_cliente(), SEEK_SET);
            TCliente *curr_cli = le_cliente(arquivo_dados);
            if (curr_cli == NULL) break;
            if ((curr_cli->cod == cod_cli) && (curr_cli->ocupado == 1)) {
                free(curr_cli);
                free(comp);
                fclose(arquivo_hash);
                fclose(arquivo_dados);
                return -1;
            }
            if ((curr_cli->ocupado == 0) && (liberado_cli_pos == -1)) liberado_cli_pos = curr_cli_pos;
            prev_cli_pos = curr_cli_pos;
            curr_cli_pos = curr_cli->prox;
            free(curr_cli);
        }
        if (liberado_cli_pos != -1) {
            fseek(arquivo_dados, liberado_cli_pos * tamanho_cliente(), SEEK_SET);
            TCliente *liberado_cli = le_cliente(arquivo_dados);
            liberado_cli->cod = cod_cli;
            strcpy(liberado_cli->nome, nome_cli);
            liberado_cli->ocupado = 1;
            fseek(arquivo_dados, liberado_cli_pos * tamanho_cliente(), SEEK_SET);
            salva_cliente(liberado_cli, arquivo_dados);
            free(liberado_cli);
            free(comp);
            fclose(arquivo_hash);
            fclose(arquivo_dados);
            return liberado_cli_pos;
        } else {
            fseek(arquivo_dados, 0, SEEK_END);
            int novo_cli_pos = ftell(arquivo_dados) / tamanho_cliente();
            TCliente *novo_cli = cliente(cod_cli, nome_cli, -1, 1);
            salva_cliente(novo_cli, arquivo_dados);
            free(novo_cli);
            fseek(arquivo_dados, prev_cli_pos * tamanho_cliente(), SEEK_SET);
            TCliente *ultimo_cli = le_cliente(arquivo_dados);
            if (ultimo_cli != NULL) {
                ultimo_cli->prox = novo_cli_pos;
                fseek(arquivo_dados, prev_cli_pos * tamanho_cliente(), SEEK_SET);
                salva_cliente(ultimo_cli, arquivo_dados);
                free(ultimo_cli);
            }
            free(comp);
            fclose(arquivo_hash);
            fclose(arquivo_dados);
            return novo_cli_pos;
        }
    }
}

int main() {
    /* Essa função gera a saída que é usada no teste do run.codes. Ela NÃO DEVE SER MODIFICADA */
    int cod;
    char nome[TAM_NOME] = "";
    int pont;

    //le dados a serem inseridos
    scanf("%d", &cod);
    scanf("%s", nome);

    //Imprime arquivos de entrada
    //imprime_arquivos("tabHash.dat", "clientes.dat");

    pont = insere(cod, nome, "tabHash.dat", "clientes.dat", M);
    imprime_arquivos("tabHash.dat", "clientes.dat");
    //Imprime resultado da função
    printf("\nRESULTADO: %d", pont);
}