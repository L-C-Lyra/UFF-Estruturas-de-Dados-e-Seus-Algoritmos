#include "arvore-binaria.h"
#include <math.h>

TNoA *inicializa(void) {
    return NULL;
}

void imprime(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%c\n", nodo->info);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

TNoA *criaNo(char ch) {
    TNoA *novo;
    novo = (TNoA *) malloc(sizeof(TNoA));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void imagem_espelho(TNoA *raiz) {
    if (raiz == NULL) return;
    TNoA *tmp = raiz->esq;
    raiz->esq = raiz->dir;
    raiz->dir = tmp;
    imagem_espelho(raiz->esq);
    imagem_espelho(raiz->dir);
}

int main(void) {
    TNoA *raizCheia = criaNo('1');
    raizCheia->esq = criaNo('2');
    raizCheia->dir = criaNo('3');
    raizCheia->esq->esq = criaNo('4');
    raizCheia->esq->dir = criaNo('5');
    raizCheia->dir->esq = criaNo('6');
    raizCheia->dir->dir = criaNo('7');
    imprime(raizCheia, 0);
    printf("\n\n");
    imagem_espelho(raizCheia);
    imprime(raizCheia, 0);
    free(raizCheia);
    return 0;
};