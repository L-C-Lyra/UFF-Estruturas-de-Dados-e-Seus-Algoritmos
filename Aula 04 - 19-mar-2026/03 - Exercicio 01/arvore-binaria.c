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

int altura(TNoA *raiz) {
    if (raiz == NULL) return 0;
    int altura_esq = altura(raiz->esq);
    int altura_dir = altura(raiz->dir);
    if (altura_esq > altura_dir) return altura_esq + 1;
    return altura_dir + 1;
}

int contaNos(TNoA *raiz) {
    if (raiz == NULL) return 0;
    return contaNos(raiz->esq) + contaNos(raiz->dir) + 1;
}

int arvore_cheia(TNoA *raiz) {
    if (raiz == NULL) return 1;
    int h = altura(raiz);
    int n = contaNos(raiz);
    return n == pow(2, h) - 1;
}

int main(void) {
    TNoA *raizNaoCheia = criaNo('A');
    raizNaoCheia->esq = criaNo('B');
    raizNaoCheia->dir = criaNo('C');
    raizNaoCheia->dir->esq = criaNo('D');
    raizNaoCheia->dir->dir = criaNo('E');
    TNoA *raizCheia = criaNo('1');
    raizCheia->esq = criaNo('2');
    raizCheia->dir = criaNo('3');
    raizCheia->esq->esq = criaNo('4');
    raizCheia->esq->dir = criaNo('5');
    raizCheia->dir->esq = criaNo('6');
    raizCheia->dir->dir = criaNo('7');
    printf("A primeira arvore e cheia? %s\n", arvore_cheia(raizNaoCheia) ? "SIM" : "NAO");
    printf("A segunda arvore e cheia? %s\n", arvore_cheia(raizCheia) ? "SIM" : "NAO");
    free(raizNaoCheia);
    free(raizCheia);
    return 0;
};