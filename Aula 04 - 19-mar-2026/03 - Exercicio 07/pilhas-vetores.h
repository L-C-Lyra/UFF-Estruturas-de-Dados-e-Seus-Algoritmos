#ifndef PILHAS_VETORES_H
#define PILHAS_VETORES_H

#include <stdio.h>
#include "arvore-binaria.h"

typedef struct pilha {
    TNoA *info;
} TPilha;

void inicializa_pilha(int *base, int *lim, int *topo);
int pilha_cheia(int lim, int topo);
int pilha_vazia(int base, int topo);
int push(TPilha *pilha, int lim, int *topo, TNoA *info);
TNoA *pop(TPilha *pilha, int base, int *topo);
TNoA *peek(TPilha *pilha, int base, int *topo);
void imprime_pilha(TPilha *pilha, int *topo);

#endif