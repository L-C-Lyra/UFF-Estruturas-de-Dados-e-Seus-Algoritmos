#include "pilhas-vetores.h"

int base, lim, topo;

void inicializa_pilha(int *base, int *lim, int *topo) {
    *base = 0;
    *lim = 9;
    *topo = -1;
}

int pilha_cheia(int lim, int topo) {
    if (topo == lim) return 1;
    return 0;
}

int pilha_vazia(int base, int topo) {
    if (topo < base) return 1;
    return 0;
}

int push(TPilha *pilha, int lim, int *topo, TNoA *info) {
    if (pilha_cheia(lim, *topo)) return -1;
    *topo = *topo + 1;
    pilha[*topo].info = info;
    return 1;
}

TNoA *pop(TPilha *pilha, int base, int *topo) {
    if (pilha_vazia(base, *topo)) return NULL;
    TNoA *info = pilha[*topo].info;
    *topo = *topo - 1;
    return info;
}

TNoA *peek(TPilha *pilha, int base, int *topo) {
    if (pilha_vazia(base, *topo)) return NULL;
    return pilha[*topo].info;
}

void imprime_pilha(TPilha *pilha, int *topo) {
    printf("\nEstado atual da Pilha:\n");
    for (int i = *topo; i >= 0; i--) {
        TNoA *no = pilha[i].info;
        if (no != NULL) printf("posicao [%d]: %c\n", i, no->info);
        else printf("posicao [%d]: vazio\n", i);
    }
    printf("\n");
}