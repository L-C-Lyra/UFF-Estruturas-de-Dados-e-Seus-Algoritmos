#include <stdio.h>
#include <stdlib.h>

typedef struct noA {
    char info;
    struct noA *esq;
    struct noA *dir;
} TNoA;

TNoA *inicializa(void);
void imprime(TNoA *nodo, int tab);
TNoA *criaNo(char ch);
int altura(TNoA *raiz);
int contaNos(TNoA *raiz);
int arvore_cheia(TNoA *raiz);