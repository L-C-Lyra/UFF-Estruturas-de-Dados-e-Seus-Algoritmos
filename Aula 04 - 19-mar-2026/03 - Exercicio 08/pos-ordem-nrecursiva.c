#include <stdio.h>
#include "arvore-binaria.h"
#include "pilhas-vetores.h"

#define MAX_PILHA 100

void imprime_posNRecursiva(TNoA *raiz) {
    if (raiz == NULL) return;
    TPilha pilha[MAX_PILHA];
    int base, lim, topo;
    inicializa_pilha(&base, &lim, &topo);
    lim = MAX_PILHA - 1;
    TNoA *atual = raiz;
    TNoA *ultimo = NULL;
    while ((atual != NULL) || !pilha_vazia(base, topo)) {
        if (atual != NULL) {
            push(pilha, lim, &topo, atual);
            atual = atual->esq;
        } else {
            TNoA *no_peek = peek(pilha, base, &topo);
            if ((no_peek->dir != NULL) && (ultimo != no_peek->dir)) atual = no_peek->dir;
            else {
                printf("%c ", no_peek->info);
                ultimo = pop(pilha, base, &topo);
            }
        }
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
    imprime_posNRecursiva(raiz);
    return 0;
}