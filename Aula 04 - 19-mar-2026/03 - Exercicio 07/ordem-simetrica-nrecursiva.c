#include <stdio.h>
#include "arvore-binaria.h"
#include "pilhas-vetores.h"

#define MAX_PILHA 100

void imprime_simetricaNRecursiva(TNoA *raiz) {
    if (raiz == NULL) return;
    TPilha pilha[MAX_PILHA];
    int base, lim, topo;
    inicializa_pilha(&base, &lim, &topo);
    lim = MAX_PILHA - 1;
    TNoA *atual = raiz;
    while ((atual != NULL) || !pilha_vazia(base, topo)) {
        while (atual != NULL) {
            push(pilha, lim, &topo, atual);
            atual = atual->esq;
        }
        atual = pop(pilha, base, &topo);
        printf("%c ", atual->info);
        atual = atual->dir;
    }
}

int main(void) {
    TNoA *raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->dir = criaNo('C');
    raiz->dir->esq = criaNo('D');
    raiz->dir->dir = criaNo('E');
    imprime(raiz, 0);
    printf("\n\n");
    imprime_simetricaNRecursiva(raiz);
    return 0;
}