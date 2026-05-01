#include <stdio.h>

void imprime_arquivo(char *nomeArq){
    FILE *arq; //declara ponteiro para arquivo
    //abre arquivo para leitura
    arq = fopen(nomeArq, "r");
    if (arq != NULL){// checa se não deu erro na abertura do arquivo
        char s[10];
        fscanf(arq, "%s", s);
        while (!feof(arq)) {//testa se chegou ao final do arquivo
            printf("%s\n", s);
            fscanf(arq, "%s", s);
        }
        fclose(arq); //fecha arquivo
    }
    else printf("Erro ao abrir arquivo\n");
}

void merge(char *nomeArq1, char *nomeArq2, char *nomeArqMerge) {
    FILE *arq1 = fopen(nomeArq1, "r");
    FILE *arq2 = fopen(nomeArq2, "r");
    FILE *arqMerge = fopen(nomeArqMerge, "w");
    if ((arq1 == NULL) || (arq2 == NULL) || (arqMerge == NULL)) {
        if (arq1) fclose(arq1);
        if (arq2) fclose(arq2);
        if (arqMerge) fclose(arqMerge);
        printf("Erro ao abrir arquivo(s)\n");
    }
    int n1, n2;
    int r1 = fscanf(arq1, "%d", &n1);
    int r2 = fscanf(arq2, "%d", &n2);
    int last_written = 0;
    int has_written = 0;
    while ((r1 == 1) && (r2 == 1)) {
        int min_n;
        if (n1 < n2) {
            min_n = n1;
            r1 = fscanf(arq1, "%d", &n1);
        } else if (n2 < n1) {
            min_n = n2;
            r2 = fscanf(arq2, "%d", &n2);
        } else {
            min_n = n1;
            r1 = fscanf(arq1, "%d", &n1);
            r2 = fscanf(arq2, "%d", &n2);
        }
        if ((!has_written) || (min_n != last_written)) {
            fprintf(arqMerge, "%d\n", min_n);
            last_written = min_n;
            has_written = 1;
        }
    }
    while (r1 == 1) {
        if ((!has_written) || (n1 != last_written)) {
            fprintf(arqMerge, "%d\n", n1);
            last_written = n1;
            has_written = 1;
        }
        r1 = fscanf(arq1, "%d", &n1);
    }
    while (r2 == 1) {
        if ((!has_written) || (n2 != last_written)) {
            fprintf(arqMerge, "%d\n", n2);
            last_written = n2;
            has_written = 1;
        }
        r2 = fscanf(arq2, "%d", &n2);
    }
    fclose(arq1);
    fclose(arq2);
    fclose(arqMerge);
}

int main(int argc, char **argv) {
    merge("numeros1.txt", "numeros2.txt", "merge.txt");
    imprime_arquivo("merge.txt");
}
